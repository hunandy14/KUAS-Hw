/**********************************************************
Name :
Date : 2016/08/03
By   : CharlotteHonG
Final: 2016/08/12
**********************************************************/
// Bicubic�վ�j�p
int debug2=0;
void imgraw::resize_bicubic(float Ratio) {
    int w=floor(this->width * Ratio);
    int h=floor(this->high * Ratio);
    imgraw img2(h, w);
    int oy, ox;// �������Ϫ��y��
    double a, b;// ������ a �P b
    imch** mask;
    imch X;
    int debug=0;
    for(int j = 0; j < h; ++j) {
        for(int i = 0; i < w; ++i) {
            oy=(int)j/Ratio; ox=(int)i/Ratio;
            a = (i-ox*Ratio)/(Ratio);
            b = (j-oy*Ratio)/(Ratio);
            // this->point_read(oy, ox);
            mask=this->getMask(oy, ox);
            X = bicubicInterpolate(mask, b, a);
            // X = X>=255? X=255: X<0? X=0: X;
            if (X == 255){
                // X=0;
                // ++debug;
            }else if (X < 0){
                // X=255;
                // ++debug;
            }

            // cout << this->point_read(j, i) << ' ';
            img2.point_write(j, i, X);
        }
        // cout << endl;
    }
    // cout << "debug=" << debug << endl;
    cout << "debug2=" << debug2 << endl;
    imch t=255;
    cout << "t = " << (int)t  << '|' << t << endl;
    ++t;
    ++t;
    cout << "t = " << (int)t  << '|' << t << endl;

        
    // mask=this->getMask(0, 0);
    // cout << "mask = " << endl;
    // for (int j = 0; j < 4; ++j){
    //     for (int i = 0; i < 4; ++i){
    //     cout << (int)mask[j][i] << ' ';
    //     } cout << endl;
    // }
    // cout << "bi = " << (int)bicubicInterpolate(mask,1,1) << endl;

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
    // �W�L��ɭ״_
    if (oy<=0 && ox<=0){
        oy=1; ox=1;
    }else if(oy>=this->high && ox>=this->width){
        oy=this->high - 3;
        ox=this->width - 3;
    }
    // ���o�P��16�I
    for (int j = 0; j < 4; ++j){
        for (int i = 0; i < 4; ++i){
            mask[j][i] = this->point_read(oy+(j-1), ox+(i-1));
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
    temp = temp>255? temp=255:temp<0? temp=0:temp;
    return (imch)temp;
}
// Bicubic ��J16�I�P���J��m�A���o�ؼЭ�
imch imgraw::bicubicInterpolate (imch** p, double x, double y) {
    imch* arr = new imch[4];
    for (int i = 0; i < 4; ++i)
        arr[i] = cubicInterpolate(p[i], y);
    return cubicInterpolate(arr, x);
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