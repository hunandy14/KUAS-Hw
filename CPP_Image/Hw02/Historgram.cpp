/**********************************************************
Name : OpenRaw 2.1
Date : 2016/08/03
By   : CharlotteHonG
Final: 2016/08/19
**********************************************************/
// Imrintv�غc�l
ImrIntv::ImrIntv(int min, int max){
    this->min = min;
    this->max = max;
}

// size�غc�l
ImrSize::ImrSize(int high=0, int width=0){
    this->high  = high;
    this->width = width;
}

//========================================================
void imgraw::pri_htg(){
    // ���o�ƾ�
    this->histogram();
    // ���Y�ƾ�
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
    // ��̰���
    int htg_high=0;
    for (int i = 0; i < 32; ++i){
        if (htg_comp[i]>htg_high){
            htg_high = htg_comp[i];
        }
    }
    // �ഫ����
    int htg_rate[32]={0};
    for (int i = 0; i < 32; ++i){
        htg_rate[i] = (int)((double)htg_comp[i]/(double)htg_high*32);
    }
    // �ഫ�r��
    string str[32][32];
    for (int j = 0; j < 32; ++j){
        for (int i = 0; i < htg_rate[j]; ++i){
            str[j][i]+=" �m";
        }
    }
    // �L�X
    for (int i = 31; i >= 0; --i){
        cout << setw(3) << (i+1) << " ";
        for (int j = 0; j < 32; ++j){
            cout << setw(3) <<str[j][i];
        }
        cout << endl;   
    }
    // �ƾڻ�����
    cout << setw(3) << "";
    for (int i = 0; i < 32/2; ++i){
        cout << setw(6) << (i+1)*16;  
    }
    cout << "" << endl;
}

void imgraw::histogram(){
    int s=this->width * this->high;
    int temp;
    // �k�s
    for (int i = 0; i < 256; ++i)
        htg_data[i]=0;
    // ���o�ƾ�
    for (int i = 0; i < s; ++i){
        temp = (int)this->img_data.at(i);
        ++this->htg_data[temp];
    }
}

// �٭�
void imgraw::stretch(ImrIntv intv){
    // ���o�ƾڷ���
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
// ���Y
void imgraw::shrink(ImrIntv intv){
    // ���o�ƾڷ���
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
// ���o�ƾڷ���
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
// imgraw�غc�l
imgraw::imgraw(ImrSize size=ImrSize(0,0)) {
    int x=size.width;
    int y=size.high;
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
    return this->img_data.at(pos);
}

// �g�J�O������I
void imgraw::point_write(int y, int x, imch value) {
    int pos = (y*this->width)+x;
    this->img_data.at(pos) = value;
}

// �վ�e���j�p
void imgraw::resize_canvas(ImrSize size) {
    int x = size.width;
    int y = size.high;
    // cout << "x=" << x << endl;
    // cout << "y=" << y << endl;
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