/**********************************************************
Name : OpenRaw 2.2
Date : 2016/08/03
By   : CharlotteHonG
Final: 2016/08/25
**********************************************************/
//=========================================================
// size建構子
ImrSize::ImrSize(int high=0, int width=0){
    this->high  = high;
    this->width = width;
}

// imgraw建構子
imgraw::imgraw(ImrSize size=ImrSize(0,0)) {
    int x=size.width;
    int y=size.high;
    this->width = x;
    this->high = y;
    this->img_data.vector::resize(x*y);
    this->filesize = x*y;
}
//=========================================================
// 高斯
void imgraw::gaussian(double dev=2){
    // 係數
    double sq_12 = sqrt((double)12);
    double sq_10 = sqrt((double)10);
    // 高斯係數
    double gau = (sq_12*dev)/sq_10;
    // 計算
    for (int j = 0; j < this->high; ++j){
        for (int i = 0; i < this->width; ++i){
            // 取亂數
            int ran = rand_int(-dev,dev+1);
            // 雜訊值
            double noise = gau*ran;
            // 寫入圖檔
            double temp = (double)this->point_read(j,i);
            temp += noise;
            if (temp > 255)
                temp = 255;
            else if (temp < 0)
                temp = 0;
            this->point_write(j, i, (imch)temp);
        }
    }

}
// 中值(尚未優化)
void imgraw::median_filter(ImrSize size=ImrSize(3,3)){
    imch** mask;
    imgraw img2(ImrSize(this->high, this->width));
    for (int j = 0; j < this->high; ++j){
        for (int i = 0; i < this->width; ++i){
            mask = this->getMask(j, i, size, -1, -1);
            // 建立一個臨時陣列排序用(優化時要修掉)
            imch* temp=new imch[size.high*size.width];
            // 二維轉一為
            int pos=0;
            for (int j = 0; j < size.high; ++j){
                for (int i = 0; i < size.width; ++i){
                    temp[pos] = mask[j][i];
                    ++pos;
                }
            }
            // 排序
            this->sort(temp, size.high*size.width);
            img2.point_write(j,i,temp[4]);
        }
    } *this=img2;
    // 釋放記憶體
    for (int i = 0; i < size.high ; ++i)
        delete [] mask[i];
    delete [] mask;
}
// 排序
void imgraw::sort(imch arr[], int len){
    imch temp;
    int i, j;
    for (i = 1; i < len; i++) {
        temp = arr[i];
        for (j = i - 1; j >= 0 && arr[j] > temp; j--)
            arr[j + 1] = arr[j];
        arr[j + 1] = temp;
    }
}
// 低通
void imgraw::low_pass(ImrSize size=ImrSize(3,3)){
    imch** mask;
    imgraw img2(ImrSize(this->high, this->width));
    // 印出遮罩
    // mask = this->getMask(2, 2, size, -1, -1);
    // for (int j = 0; j < size.high; ++j){
    //     for (int i = 0; i < size.width; ++i){
    //         cout << mask[j][i];
    //     }cout << endl;
    // }
    // 平均遮罩的的數值並寫入
    for (int j = 0; j < this->high; ++j){
        for (int i = 0; i < this->width; ++i){
            mask = this->getMask(j, i, size, -1, -1);
            double temp=0;
            for (int l = 0; l < size.high; ++l){
                for (int k = 0; k < size.width; ++k){
                    temp+=(double)mask[l][k];
                }
            }temp/=size.high*size.width;
            img2.point_write(j,i,(imch)temp);
        }
    } *this=img2;
    // 釋放記憶體
    for (int i = 0; i < size.high ; ++i)
        delete [] mask[i];
    delete [] mask;
}
// 取得遮罩(座標, 大小, 遮罩偏移的位置)
imch** imgraw::getMask(int oy, int ox,
        ImrSize size=ImrSize(3,3),
        int sy=-1, int sx=-1){
    // 創建動態陣列
    imch** mask;
    mask = new imch*[size.high];
    for (int i = 0; i < size.high; ++i)
        mask[i] = new imch[size.width];
    // 取得周圍16點
    int foy,fox; // 修復後的原始座標
    for (int j = 0; j < size.high; ++j){
        for (int i = 0; i < size.width; ++i){
            foy=oy+(j+(sy)); fox=ox+(i+(sx));
            // 超過左邊界修復
            if (foy<0){foy=0;}
            // 超過上邊界修復
            if (fox<0){fox=0;}
            // 超過下邊界修復
            if(foy==this->high){foy-=2;}
            if(foy==this->high-1){foy-=1;}
            // 超過右邊界修復
            if (fox==this->width){fox-=2;}
            if (fox==this->width-1){fox-=1;}
            // 紀錄對應的指標
            mask[j][i] = this->point_read(foy, fox);
        }
    }
    // 釋放記憶體
    // for (int i = 0; i < 4; ++i)
    //     delete [] mask[i];
    // delete [] mask;
    return mask;
}
// 胡椒鹽雜訊
void imgraw::salt_pepper(unsigned int white, unsigned int black=0){
    srand((unsigned)time(NULL));
    ImrSize size(this->high, this->width);
    imgraw img2(size);
    int temp;
    // 灑黑點
    temp = ((double)black/(double)100)
                     * this->high * this->width;
    // cout << temp << endl;
    for (int i = 0; i < temp; ++i){
        int y = rand_int(0,256);
        int x = rand_int(0,256);
        if (img2.point_read(y, x) != 1){
            img2.point_write(y, x, (imch)1);
        }else {--i;}
    }
    // 灑白點
    temp = ((double)white/(double)100)
                     * this->high * this->width;
    // cout << temp << endl;
    for (int i = 0; i < temp; ++i){
        int y = rand_int(0,256);
        int x = rand_int(0,256);
        if (img2.point_read(y, x) != 255
            && img2.point_read(y, x) != 1){
            img2.point_write(y, x, (imch)255);
        }else {--i;}
    }
    // 灑到原圖上
    for (int j = 0; j < this->high; ++j){
        for (int i = 0; i < this->width; ++i){
            imch temp = img2.point_read(j, i);
            if (temp == (imch)1){
                this->point_write(j, i, (imch)0);
            }else if (temp == (imch)255){
                this->point_write(j, i, (imch)255);
            }
        }
    }
    // *this = img2;
}
// 取亂數(不包含up)
int imgraw::rand_int(int low, int up){
    int temp;
    if (low < 0)
        low-=1;
    temp = (int)((rand() / (RAND_MAX+1.0)) * (up - low) + low);
    return temp;
}
//=========================================================
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
        cout << "File ok." << endl;
    } img.close();
    // 二進位模式讀檔
    // 取得總長
    img.open(this->filename, ios::in | ios::binary);
    img.seekg(0, ios::end);
    this->filesize = img.tellg();
    img.seekg(0, ios::beg);
    // 讀取值
    this->img_data.vector::resize(this->filesize);
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
    this->img_data.vector::at(pos) = value;
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
// 印出直方圖
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
    // 取得整數長度
    string temp;
    stringstream ss;
    ss << htg_high;
    temp.clear();
    ss >> temp;
    ss.clear();
    // 印出
    cout << endl << setw((64-3)-(title.length()/2));
    cout << title << endl;
    for (int i = 31; i >= 0; --i){
        cout << setw(temp.length()) << htg_high/32*(i+1) << " ";
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