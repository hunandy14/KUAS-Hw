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

// 還原
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
// 收縮
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
        cout << "File ok." << endl;
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