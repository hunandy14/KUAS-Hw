/**********************************************************
Name :
Date : 2016/08/03
By   : CharlotteHonG
Final: 2016/08/10
**********************************************************/
// FisrtOrder�վ�j�p
void imgraw::resize_first(float Ratio){
    int w=floor(this->width * Ratio);
    int h=floor(this->high * Ratio);
    imgraw img2(h, w);
    vector<char> A(1), B(1), C(1), D(1);//���񪺥|���I
    vector<char> AB(1), CD(1), X(1), Y(1);
    int oy, ox;//�������Ϫ��y��
    double a, b;// ������a�Pb
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


// ZroOrder�վ�j�p
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

// �פJ�ɮ�
void imgraw::read(string filename) {
    this->filename = filename;
    
    // �G�i��Ҧ��}�ɴ���
    fstream img;
    img.open(filename, ios::in | ios::binary);
    
    // �p�G�}���ɮץ��ѡAfp��0�F���\�Afp���D0
    if(!img) {
        img.close();
        cout << "No file." << endl;
        exit(1);
    }
    else {
        cout << "File ok." << endl;
    } img.close();

    // �G�i��Ҧ�Ū��
    // ���o�`��
    img.open(this->filename, ios::in | ios::binary);
    img.seekg(0, ios::end);
    this->filesize = img.tellg();
    img.seekg(0, ios::beg);
    // Ū����
    this->img_data.vector::resize(this->filesize);
    img.fstream::read(&this->img_data[0], this->filesize);
    img.close();
}

// �N�O�����ƶץX
void imgraw::write(string filename) {
    // �i��Ҧ��g��
    fstream img;
    img.open(filename, ios::out | ios::binary);
    img.fstream::write(&img_data[0], this->filesize);
    img.close();
}

// Ū�ɳ��I
vector<char> imgraw::point_read(int y, int x) {
    int pos = (y*this->width)+x;
    vector<char> temp(1);
    temp[0] = this->img_data[pos];
    return temp;
}

// �g�J�O������I
void imgraw::point_write(int y, int x, vector<char> value) {
    int pos = (y*this->width)+x;
    this->img_data[pos] = value[0];
}

// �վ�e���j�p
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