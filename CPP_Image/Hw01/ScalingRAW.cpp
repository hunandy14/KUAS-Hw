/**********************************************************
Name :
Date : 2016/08/03
By   : CharlotteHonG
Final: 2016/08/10
**********************************************************/
// FisrtOrder�վ�j�p
// void imgraw::resize_zero(float Ratio){

// }

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
    img.write(&img_data[0], this->filesize);
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