/**********************************************************
Name :
Date : 2016/08/03
By   : CharlotteHonG
Final: 2016/08/10
**********************************************************/
// FisrtOrder調整大小
void imgraw::resize_first(float Ratio){
    int w=floor(this->width * Ratio);
    int h=floor(this->high * Ratio);
    imgraw img2(h, w);
    vector<char> A(1), B(1), C(1), D(1);//附近的四個點
    vector<char> AB(1), CD(1), X(1), Y(1);
    int oy, ox;//對應到原圖的座標
    double a, b;// 公式的a與b
    int debug=0;
    for(int j=0; j < h; ++j) {
        for(int i=0; i < w; ++i) {
            oy=j/Ratio; ox=i/Ratio;
            A = this->point_read(oy, ox);
            B = this->point_read(oy, ox+1);
            C = this->point_read(oy+1, ox);
            D = this->point_read(oy+1, ox+1);
            a = (i-ox*Ratio)/(Ratio); 
            b = (j-oy*Ratio)/(Ratio);
            AB[0] = (A[0]*(1-a)) + (B[0]*a);
            CD[0] = (C[0]*(1-a)) + (D[0]*a);
            X[0] = ((AB[0]*(1-b)) + (CD[0]*b));
            // if (X[0]>255) X[0]=A[0];
            // if (X[0]<0) X[0]=A[0];
            img2.point_write(j, i, X);
        }
    }
    cout << "debug=" << debug << endl;
        
    *this = img2;
}


// ZroOrder調整大小
void imgraw::resize_zero(float Ratio) {
    int w=floor(this->width * Ratio);
    int h=floor(this->high * Ratio);
    imgraw img2(h, w);
        
    for(int j = 0; j < h; ++j) {
        for(int i = 0; i < w; ++i) {
            img2.point_write(j, i, this->point_read(j/Ratio, i/Ratio));
        }
    }
    *this = img2;
}

//=========================================================
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
    this->img_data.vector::resize(this->filesize);
    img.fstream::read(&this->img_data[0], this->filesize);
    img.close();
}

// 將記憶體資料匯出
void imgraw::write(string filename) {
    // 進位模式寫檔
    fstream img;
    img.open(filename, ios::out | ios::binary);
    img.fstream::write(&img_data[0], this->filesize);
    img.close();
}

// 讀檔單點
vector<char> imgraw::point_read(int y, int x) {
    int pos = (y*this->width)+x;
    vector<char> temp(1);
    temp[0] = this->img_data[pos];
    return temp;
}

// 寫入記憶體單點
void imgraw::point_write(int y, int x, vector<char> value) {
    int pos = (y*this->width)+x;
    this->img_data[pos] = value[0];
}

// 調整畫布大小
void imgraw::resize_canvas(int y, int x) {
    this->width = x;
    this->high = y;
}

int imgraw::w(){
    return this->width;
}

int imgraw::h(){
    return this->high;

}
//=========================================================