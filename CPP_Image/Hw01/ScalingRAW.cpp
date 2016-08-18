/**********************************************************
Name :
Date : 2016/08/03
By   : CharlotteHonG
Final: 2016/08/18
**********************************************************/
// Bicubic�վ�j�p
void imgraw::resize_bicubic(float Ratio) {
    if(Ratio <= 0) {
        cout << "Ratio more than the zero." << endl;
        return;
    }
    int w=floor(this->width * Ratio);
    int h=floor(this->high * Ratio);
    imgraw img2(h, w);
    int oy, ox; // �������Ϫ��y��
    double a, b;// ���J����Ҧ�m
    imch** mask;// �B�n(�P��16�I)
    imch X;     // �Ȧs
    for(int j = 0; j < h; ++j) {
        for(int i = 0; i < w; ++i) {
            oy=(int)j/Ratio; ox=(int)i/Ratio;
            a = (i-ox*Ratio)/(Ratio);
            b = (j-oy*Ratio)/(Ratio);
            // ���o�P��16�I
            mask = this->getMask(oy, ox);
            // �ɤJ�P��16�I�P���J����Ҧ�m
            X = bicubicInterpolate(mask, b, a);
            // �g�J�Ȧs��
            img2.point_write(j, i, X);
        }
    }
    // ��X�Ȧs
    *this = img2;
    // ����O����
    for (int i = 0; i < 4; ++i)
        delete [] mask[i];
    delete [] mask;
}
// Bicubic ���o�P��16�I
imch** imgraw::getMask(int oy, int ox){
    imch** mask = new imch*[4];
    for (int i = 0; i < 4; ++i)
        mask[i] = new imch[4];
    // ���o�P��16�I
    int foy,fox; // �״_�᪺��l�y��
    for (int j = 0; j < 4; ++j){
        for (int i = 0; i < 4; ++i){
            foy=oy+(j-1); fox=ox+(i-1);
            // �W�L����ɭ״_
            if (foy<0){foy=1;}
            // �W�L�W��ɭ״_
            if (fox<0){fox=1;}
            // �W�L�U��ɭ״_
            if(foy==this->high){foy-=2;}
            if(foy==this->high-1){foy-=1;}
            // �W�L�k��ɭ״_
            if (fox==this->width){fox-=2;}
            if (fox==this->width-1){fox-=1;}
            // ��������������
            mask[j][i] = this->point_read(foy, fox);
        }
    }
    // ����O����
    // for (int i = 0; i < 4; ++i)
    //     delete [] mask[i];
    // delete [] mask;
    return mask;
}
// Bicubic ���Ȯ֤߹B��
imch imgraw::cubicInterpolate (imch* p, double x) {
    double temp = (double)(p[1] + 0.5 * 
        x*(p[2] - p[0] +x*(2.0*p[0] - 5.0*p[1] + 4.0*p[2] - 
            p[3] + x*(3.0*(p[1] - p[2]) + p[3] - p[0]))));
    if (temp > 255){
        temp = 255;
    }else if (temp < 0){
        temp = 0;
    }
    return (imch)temp;
}
// Bicubic ��J16�I�P���J��m�A���o�ؼЭ�
imch imgraw::bicubicInterpolate (imch** p, double y, double x) {
    imch* arr = new imch[4];
    for (int i = 0; i < 4; ++i)
        arr[i] = cubicInterpolate(p[i], x);
    return cubicInterpolate(arr, y);
}


// FisrtOrder�վ�j�p
void imgraw::resize_first(float Ratio) {
    if(Ratio <= 0) {
        cout << "Ratio more than the zero." << endl;
        return;
    }
    int w=floor(this->width * Ratio);
    int h=floor(this->high * Ratio);
    imgraw img2(h, w);
    imch A, B, C, D;// ���񪺥|���I
    imch AB, CD, X;
    int oy, ox;// �������Ϫ��y��
    double a, b;// ������ a �P b

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


// ZroOrder�վ�j�p
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

// �פJ�ɮ�
void imgraw::read(string filename) {
    this->filename = filename;
    // �G�i��Ҧ��}�ɴ���
    fstream img;
    img.open(filename, ios::in | ios::binary);
    // �p�G�}���ɮץ��ѡAfp��0�F���\�Afp���D0
    if(!img) {
        img.close();
        cout << "No File." << endl;
        exit(1);
    }
    else {
        // cout << "File ok." << endl;
    } img.close();
    // �G�i��Ҧ�Ū��
    // ���o�`��
    img.open(this->filename, ios::in | ios::binary);
    img.seekg(0, ios::end);
    this->filesize = img.tellg();
    img.seekg(0, ios::beg);
    // Ū����
    this->img_data.resize(this->filesize);
    img.read((char*)&this->img_data[0], this->filesize);
    img.close();
}

// �N�O�����ƶץX
void imgraw::write(string filename) {
    // �i��Ҧ��g��
    fstream img;
    img.open(filename, ios::out | ios::binary);
    img.write((char*)&img_data[0], this->filesize);
    img.close();
}

// Ū�ɳ��I
imch imgraw::point_read(int y, int x) {
    int pos = (y*this->width)+x;
    return this->img_data[pos];
}

// �g�J�O������I
void imgraw::point_write(int y, int x, imch value) {
    int pos = (y*this->width)+x;
    this->img_data[pos] = value;
}

// �վ�e���j�p
void imgraw::resize_canvas(int y, int x) {
    this->width = x;
    this->high = y;
}

// ��o�e
int imgraw::w() {
    return this->width;
}

// ��o��
int imgraw::h() {
    return this->high;
}
//=========================================================