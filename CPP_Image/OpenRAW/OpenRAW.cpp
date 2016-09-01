/**********************************************************
Name : OpenRaw 2.21
Date : 2016/08/03
By   : CharlotteHonG
Final: 2016/08/25
**********************************************************/
// ImrMask�ظѺc�l
// ImrMask::ImrMask(){
// }
// ImrMask::~ImrMask(){
// }

// ImrSize�غc�l
ImrSize::ImrSize(imint high=0, imint width=0){
    this->high  = high;
    this->width = width;
}

// ImrCoor�غc�l
ImrCoor::ImrCoor(imint y=0, imint x=0){
    this->y = y;
    this->x = x;
}

// imgraw�غc�l
imgraw::imgraw(ImrSize size=ImrSize(0,0)) {
    imint x = size.width;
    imint y = size.high;
    this->width = x;
    this->high = y;
    this->img_data.vector::resize(x*y);
    this->filesize = x*y;
    this->masksize = ImrSize(0,0);
}
//=========================================================
// ���o�B�n��
imch imgraw::mask(ImrCoor ori, ImrCoor tar, 
        int sy=-1, int sx=-1){
    // �P�_�B�n�j�p�O�_��l��
    if (this->masksize.high == 0 
        && this->masksize.width == 0){
        cout << "masksize uninit." << endl;
        return 0;
    }
    imch temp=0;
    ImrCoor pos;
    // pos=ori+tar;
    // this->point_read()
    return temp;
}
// �]�w�B�n
void imgraw::setMaskSize(ImrSize masksize){
    this->masksize = masksize;
}
// ���o�B�n�a�}
// imch** imgraw::getMask(int oy, int ox,
        // ImrSize size=ImrSize(3,3), int sy=-1, int sx=-1){
    // �ЫذʺA�}�C
    // imch** mask;
    // mask = new imch*[(int)size.high];
    // for (int i = 0; i < (int)size.high; ++i)
        // mask[i] = new imch[(int)size.width];
    // ���o�P��16�I
    // int foy,fox; // �״_�᪺��l�y��
    // for (int j = 0; j < size.high; ++j){
    //     for (int i = 0; i < size.width; ++i){
    //         foy=oy+(j+(sy)); fox=ox+(i+(sx));
    //         // �W�L��ɭ״_

    //         // ��������������
    //         mask[j][i] = this->point_read(foy, fox);
    //     }
    // }
    // ����O����
    // for (int i = 0; i < 4; ++i)
    //     delete [] mask[i];
    // delete [] mask;
    // return mask;
// }
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
        // cout << "File ok." << endl;
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
imch imgraw::point_read(imint y, imint x) {
    imint pos = (y*this->width)+x;
    return this->img_data.at(pos);
}

// �g�J�O������I
void imgraw::point_write(imint y, imint x, imch value) {
    imint pos = (y*this->width)+x;
    this->img_data.vector::at(pos) = value;
}

// �վ�e���j�p
void imgraw::resize_canvas(ImrSize size) {
    imint x = size.width;
    imint y = size.high;
    // cout << "x=" << x << endl;
    // cout << "y=" << y << endl;
    this->width = x;
    this->high = y;
}

// ��o�e
imint imgraw::w() {
    return this->width;
}

// ��o��
imint imgraw::h() {
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
// ���o�ƾڲέp(�ƭ�0~255���X��)
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
    for (int j = 0; j < (int)this->high; ++j){
        for (int i = 0; i < (int)this->width; ++i){
            temp = this->point_read(j,i);
            if (temp > this->max){
                this->max = temp;
            }else if (temp < this->min){
                this->min = temp;
            }
        }
    }
}
