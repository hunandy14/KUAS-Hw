/**********************************************************
Name : OpenRaw 2.02
Date : 2016/08/03
By   : CharlotteHonG
Final: 2016/08/12
**********************************************************/
imgraw::imgraw(int y, int x) {
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
unsigned char imgraw::point_read(int y, int x) {
    int pos = (y*this->width)+x;
    return this->img_data.at(pos);
}

// 寫入記憶體單點
void imgraw::point_write(int y, int x, unsigned char value) {
    int pos = (y*this->width)+x;
    this->img_data.at(pos) = value;
}

// 調整畫布大小
void imgraw::resize_canvas(int y, int x) {
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