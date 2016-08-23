/**********************************************************
Name : OpenRaw 2.1
Date : 2016/08/03
By   : CharlotteHonG
Final: 2016/08/19
**********************************************************/
// Imrintv建構子
ImrIntv::ImrIntv(int min, int max){
    this->min = min;
    this->max = max;
}

// size建構子
ImrSize::ImrSize(int high=0, int width=0){
    this->high  = high;
    this->width = width;
}

//========================================================
void imgraw::shrink(ImrIntv intv){
    // 取得數據極值
    this->extremum();
    int y=this->high;
    int x=this->width;

    double par = (((double)intv.max - (double)intv.min) / 
        ((double)this->max - (double)this->min));

    double temp; imch orig;
    for (int j = 0; j < y; ++j){
        for (int i = 0; i < x; ++i){
            orig = (double)this->point_read(j,i);
            temp = par*(orig - 
                    (double)this->min) + 
                    (double)intv.min;
            this->point_write(j, i, (imch)temp);
        }
    }
}
void imgraw::stretch(ImrIntv intv){
    // 取得數據極值
    this->extremum();
    int y=this->high;
    int x=this->width;

    double temp; imch orig;
    double par = (1/((double)this->max - (double)this->min)) *
        ((double)intv.max - (double)intv.min) + (double)intv.min;
    for (int j = 0; j < y; ++j){
        for (int i = 0; i < x; ++i){
            orig = (double)this->point_read(j,i);
            temp = (orig - (double)this->min) * par;
            if (temp > 255){
                temp=255;
            }else if (temp < 0){
                temp=0;
            }
            this->point_write(j, i, (imch)temp);
        }
    }
}
void imgraw::equalization(){
    // 取得數據統計
    this->histogram();
    // 找最極值
    this->extremum();
    // 取得分母
    int n = this->width * this->high;
    // 取得分子
    double grand=0,S[255];
    for (int j = 0; j < 255; ++j){
        grand += this->htg_data[j];
        S[j] = grand/n;
    }
    // 導入數據
    double temp;
    for (int i = 0; i < n; ++i){
        temp = S[(int)img_data.at(i)];
        img_data.at(i) = (int)(temp * (double)this->max);
    }
}
void imgraw::pri_htg(string title=""){
    // 取得數據
    this->histogram();
    // 壓縮數據
    int htg_comp[32]={0};
    for (int i = 0; i < 32; ++i){
        htg_comp[i]=(
            htg_data[(i*8)+0]+
            htg_data[(i*8)+1]+ 
            htg_data[(i*8)+2]+ 
            htg_data[(i*8)+3]+
            htg_data[(i*8)+4]+
            htg_data[(i*8)+5]+
            htg_data[(i*8)+6]+
            htg_data[(i*8)+7]
        );
    }
    // 找最高值
    int htg_high=0;
    for (int i = 0; i < 32; ++i){
        if (htg_comp[i]>htg_high){
            htg_high = htg_comp[i];
        }
    }
    // 轉換等比
    int htg_rate[32]={0};
    for (int i = 0; i < 32; ++i){
        htg_rate[i] = (int)((double)htg_comp[i]/(double)htg_high*32);
    }
    // 轉換字串
    string str[32][32];
    for (int j = 0; j < 32; ++j){
        for (int i = 0; i < htg_rate[j]; ++i){
            str[j][i]+=" ▌";
        }
    }
    // 印出
    cout << endl << setw((64-3)-(title.length()/2));
    cout << title << endl;
    for (int i = 31; i >= 0; --i){
        cout << setw(3) << (i+1) << " ";
        for (int j = 0; j < 32; ++j){
            cout << setw(3) <<str[j][i];
        }
        cout << endl;   
    }
    // 數據說明欄
    cout << setw(3) << "";
    for (int i = 0; i < 32/2; ++i){
        cout << setw(6) << (i+1)*16;  
    }
    cout << "" << endl;
}
// 取得數據統計
void imgraw::histogram(){
    int s=this->width * this->high;
    int temp;
    // 歸零
    for (int i = 0; i < 256; ++i)
        this->htg_data[i]=0;
    // 取得數據
    for (int i = 0; i < s; ++i){
        temp = (int)this->img_data.at(i);
        ++this->htg_data[temp];
    }
}
// 取得數據極值
void imgraw::extremum(){
    imch temp;
    this->min=255;
    this->max=0;
    for (int j = 0; j < this->high; ++j){
        for (int i = 0; i < this->width; ++i){
            temp = this->point_read(j,i);
            if (temp > this->max){
                this->max = temp;
            }else if (temp < this->min){
                this->min = temp;
            }
        }
    }
}

//========================================================
// imgraw建構子
imgraw::imgraw(ImrSize size=ImrSize(0,0)) {
    int x=size.width;
    int y=size.high;
    this->width = x;
    this->high = y;
    this->img_data.resize(x*y);
    this->filesize = x*y;
}

// 匯入檔案
void imgraw::read(string filename) {
    this->filename = filename;
    // 二進位模式開檔測試
    fstream img;
    img.open(filename, ios::in | ios::binary);
    // 如果開啟檔案失敗，fp為0；成功，fp為非0
    if(!img) {
        img.close();
        cout << "No file." << endl;
        exit(1);
    }
    else {
        // cout << "File ok." << endl;
    } img.close();
    // 二進位模式讀檔
    // 取得總長
    img.open(this->filename, ios::in | ios::binary);
    img.seekg(0, ios::end);
    this->filesize = img.tellg();
    img.seekg(0, ios::beg);
    // 讀取值
    this->img_data.resize(this->filesize);
    img.read((char*)&this->img_data[0], this->filesize);
    img.close();
}

// 將記憶體資料匯出
void imgraw::write(string filename) {
    // 進位模式寫檔
    fstream img;
    img.open(filename, ios::out | ios::binary);
    img.write((char*)&img_data[0], this->filesize);
    img.close();
}

// 讀檔單點
imch imgraw::point_read(int y, int x) {
    int pos = (y*this->width)+x;
    return this->img_data.at(pos);
}

// 寫入記憶體單點
void imgraw::point_write(int y, int x, imch value) {
    int pos = (y*this->width)+x;
    this->img_data.at(pos) = value;
}

// 調整畫布大小
void imgraw::resize_canvas(ImrSize size) {
    int x = size.width;
    int y = size.high;
    // cout << "x=" << x << endl;
    // cout << "y=" << y << endl;
    this->width = x;
    this->high = y;
}

// 獲得寬
int imgraw::w() {
    return this->width;
}

// 獲得高
int imgraw::h() {
    return this->high;
}