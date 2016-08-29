/**********************************************************
Name : OpenRaw 2.2
Date : 2016/08/03
By   : CharlotteHonG
Final: 2016/08/25
**********************************************************/
//=========================================================
// size�غc�l
ImrSize::ImrSize(int high=0, int width=0){
    this->high  = high;
    this->width = width;
}

// imgraw�غc�l
imgraw::imgraw(ImrSize size=ImrSize(0,0)) {
    int x=size.width;
    int y=size.high;
    this->width = x;
    this->high = y;
    this->img_data.vector::resize(x*y);
    this->filesize = x*y;
}
//=========================================================
// �C�q
void imgraw::low_pass(ImrSize size=ImrSize(3,3)){
    imch** mask;
    imgraw img2(ImrSize(this->high, this->width));

    // �L�X�B�n
    // mask = this->getMask(2, 2, size, -1, -1);
    // for (int j = 0; j < size.high; ++j){
    //     for (int i = 0; i < size.width; ++i){
    //         cout << mask[j][i];
    //     }cout << endl;
    // }
    cout << "mask[1][1]" << this->point_read(2, 2) << endl;
    // int debug=0;
    for (int j = 0; j < this->high; ++j){
        for (int i = 0; i < this->width; ++i){
            mask = this->getMask(j, i, size, -1, -1);
            double temp=0;
            for (int l = 0; l < size.high; ++l){
                for (int k = 0; k < size.width; ++k){
                    temp+=(double)mask[l][k];
                }
            }
            temp/=size.high*size.width;
            // temp=mask[1][1];
            // temp=(double)this->point_read(j, i);
            // if (temp > 200){
            //     ++debug;
            // }
            img2.point_write(j,i,(imch)temp);
            // img2.point_write(j,i,this->point_read(j, i));
        }
    }
    // cout << "debug=" << debug << endl;
    *this=img2;
    // ����O����
    for (int i = 0; i < size.high ; ++i)
        delete [] mask[i];
    delete [] mask;
}
// ���o�B�n(�y��, �j�p, �B�n��������m)
imch** imgraw::getMask(int oy, int ox,
        ImrSize size=ImrSize(3,3),
        int sy=-1, int sx=-1){
    // �ЫذʺA�}�C
    imch** mask;
    mask = new imch*[size.high];
    for (int i = 0; i < size.high; ++i)
        mask[i] = new imch[size.width];
    // ���o�P��16�I
    int foy,fox; // �״_�᪺��l�y��
    for (int j = 0; j < size.high; ++j){
        for (int i = 0; i < size.width; ++i){
            foy=oy+(j+(sy)); fox=ox+(i+(sx));
            // �W�L����ɭ״_
            if (foy<0){foy=0;}
            // �W�L�W��ɭ״_
            if (fox<0){fox=0;}
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
// �J���Q���T
void imgraw::salt_pepper(unsigned int white, unsigned int black=0){
    srand((unsigned)time(NULL));
    ImrSize size(this->high, this->width);
    imgraw img2(size);
    int temp;
    // �x���I
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
    // �x���I
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
    // �x���ϤW
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
// ���ü�
int imgraw::rand_int(int low, int up){
    int temp = (int)((rand() / (RAND_MAX+1.0))
                     * (up - low) + low);
    return temp;
}
//=========================================================
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
    this->img_data.vector::at(pos) = value;
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
// �L�X�����
void imgraw::pri_htg(string title=""){
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
    // ���o��ƪ���
    string temp;
    stringstream ss;
    ss << htg_high;
    temp.clear();
    ss >> temp;
    ss.clear();
    // �L�X
    cout << endl << setw((64-3)-(title.length()/2));
    cout << title << endl;
    for (int i = 31; i >= 0; --i){
        cout << setw(temp.length()) << htg_high/32*(i+1) << " ";
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
// ���o�ƾڲέp
void imgraw::histogram(){
    int s=this->width * this->high;
    int temp;
    // �k�s
    for (int i = 0; i < 256; ++i)
        this->htg_data[i]=0;
    // ���o�ƾ�
    for (int i = 0; i < s; ++i){
        temp = (int)this->img_data.at(i);
        ++this->htg_data[temp];
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