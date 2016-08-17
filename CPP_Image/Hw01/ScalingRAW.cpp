/**********************************************************
Name :
Date : 2016/08/03
By   : CharlotteHonG
Final: 2016/08/12
**********************************************************/
// Bicubic調整大小
void imgraw::resize_bicubic(float Ratio) {
    int w=floor(this->width * Ratio);
    int h=floor(this->high * Ratio);
    imgraw img2(h, w);
    int oy, ox;// 對應到原圖的座標
    double a, b;// 公式的 a 與 b
    imch** mask;

    for(int j = 0; j < 4; ++j) {
        for(int i = 0; i < 4; ++i) {
            oy=(int)j/Ratio; ox=(int)i/Ratio;
            a = (i-ox*Ratio)/(Ratio);
            b = (j-oy*Ratio)/(Ratio);
            cout << this->point_read(j, i) << ' ';
        }
        cout << endl;
        // continue;
    }

    mask=this->getMask(0, 0);
    cout << "mask = " << endl;
    for (int j = 0; j < 4; ++j){
        for (int i = 0; i < 4; ++i){
        cout << mask[j][i] << ' ';
        } cout << endl;
    }


        
    // 釋放記憶體
    for (int i = 0; i < 4; ++i)
        delete [] mask[i];
    delete [] mask;
}
// Bicubic 取得周圍16點
imch** imgraw::getMask(int oy, int ox){
    imch** mask = new imch*[4];
    for (int i = 0; i < 4; ++i)
        mask[i] = new imch[4];
    // 超過邊界修復
    if (oy<=0 && ox<=0){
        oy=1; ox=1;
    }else if(oy>=this->high && ox>=this->width){
        oy=this->high - 3;
        ox=this->width - 3;
    }
    // 取得周圍16點
    for (int j = 0; j < 4; ++j){
        for (int i = 0; i < 4; ++i){
            mask[j][i] = this->point_read(oy+(j-1), ox+(i-1));
        }
    }
    // 釋放記憶體
    // for (int i = 0; i < 4; ++i)
    //     delete [] mask[i];
    // delete [] mask;
    return mask;
}
// Bicubic 插值核心運算
imch imgraw::cubicInterpolate (imch* p, double x) {
    return p[1] + 0.5 * x*(p[2] - p[0] + x*(2.0*p[0] - 5.0*p[1] + 4.0*p[2] - p[3] + x*(3.0*(p[1] - p[2]) + p[3] - p[0])));
}
// Bicubic 輸入16點與插入位置，取得目標值
imch imgraw::bicubicInterpolate (imch** p, double x, double y) {
    imch* arr = new imch[4];
    for (int i = 0; i < 4; ++i)
        arr[i] = cubicInterpolate(p[i], y);
    return cubicInterpolate(arr, x);
}


// FisrtOrder調整大小
void imgraw::resize_first(float Ratio) {
    if(Ratio <= 0) {
        cout << "Ratio more than the zero." << endl;
        return;
    }
    int w=floor(this->width * Ratio);
    int h=floor(this->high * Ratio);
    imgraw img2(h, w);
    imch A, B, C, D;// 附近的四個點
    imch AB, CD, X;
    int oy, ox;// 對應到原圖的座標
    double a, b;// 公式的 a 與 b

    for(int j=0; j < h; ++j) {
        for(int i=0; i < w; ++i) {
            oy=j/Ratio; ox=i/Ratio;
            A = this->point_read(oy, ox);
            B = this->point_read(oy, ox+1);
            C = this->point_read(oy+1, ox);
            D = this->point_read(oy+1, ox+1);
            a = (i-ox*Ratio)/(Ratio);
            b = (j-oy*Ratio)/(Ratio);
            AB = (A*(1.0-a)) + (B*a);
            CD = (C*(1.0-a)) + (D*a);
            X = ((AB*(1.0-b)) + (CD*b));
            img2.point_write(j, i, X);
        }
    }
    *this = img2;
}


// ZroOrder調整大小
void imgraw::resize_zero(float Ratio) {
    if(Ratio <= 0) {
        cout << "Ratio more than the zero." << endl;
        return;
    }
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
        cout << "No File." << endl;
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
    return this->img_data[pos];
}

// 寫入記憶體單點
void imgraw::point_write(int y, int x, imch value) {
    int pos = (y*this->width)+x;
    this->img_data[pos] = value;
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
//=========================================================