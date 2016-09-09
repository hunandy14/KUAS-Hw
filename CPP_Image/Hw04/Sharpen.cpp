/**********************************************************
Name : OpenRaw 2.31
Date : 2016/08/03
By   : CharlotteHonG
Final: 2016/09/08
**********************************************************/
// ImrSize�غc�l
ImrSize::ImrSize(imint high=0, imint width=0){
    this->high  = high;
    this->width = width;
}

// ImrCoor�غc�l
ImrCoor::ImrCoor(int y=0, int x=0){
    this->y = y;
    this->x = x;
}

// ImrMask�غc�l
ImrMask::ImrMask(ImrSize masksize=ImrSize(0,0)){
    this->mask.vector::resize(masksize.high * masksize.width);
    this->masksize = masksize;
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
// Imrintv�غc�l
ImrIntv::ImrIntv(imint min, imint max){
    this->min = min;
    this->max = max;
}
/*
    ###               #     #
     #  #    # #####  ##   ##   ##    ####  #    #
     #  ##  ## #    # # # # #  #  #  #      #   #
     #  # ## # #    # #  #  # #    #  ####  ####
     #  #    # #####  #     # ######      # #  #
     #  #    # #   #  #     # #    # #    # #   #
    ### #    # #    # #     # #    #  ####  #    #
*/
// �Ƨǰ}�C(���סA�_�l�I)
void ImrMask::sort(size_t len=0, size_t start=0) {
    imch temp;
    imch* arr = &this->mask[start];
    if (len == 0){
        len = this->masksize.high*this->masksize.width; 
    }
    // // ���J�ƧǪk
    for (int i=1, j; i<(int)len; i++) {
        temp = arr[i];
        for (j=i-1; j>=0 && arr[j]>temp; j--)
            arr[j + 1] = arr[j];
        arr[j + 1] = temp;
    }
}
// �H�G���覡Ū���μg�J
imch& ImrMask::at2d(size_t y, size_t x){
    size_t pos = (y*this->masksize.width) + x;
    return this->mask[pos];
}
/*
       ##

     ####     ### ##    ######  ## ###    ######  ##   ##
       ##     ## # ##  ##   ##  ###      ##   ##  ## # ##
       ##     ## # ##  ##   ##  ##       ##   ##  ## # ##
       ##     ## # ##   ######  ##       ##  ###  ## # ##
     ######   ##   ##       ##  ##        ### ##   ## ##
                        #####
*/
// ���o�B�n�� (���I�A�B�n�y�СA�첾)
imch imgraw::maskVal(ImrCoor ori, ImrCoor mas, 
        ImrCoor shi=ImrCoor(-1,-1)){
    // ���o������m
    ImrCoor pos = ori + mas + shi;
    // �ץ���t
    if (pos.y <0){
        pos.y = 0;
    }
    if (pos.y > (int)this->high-1){
        pos.y = (int)this->high-1;
    }
    if (pos.x <0){
        pos.x = 0;
    }
    if (pos.x > (int)this->width-1){
        pos.x = (int)this->width-1;
    }
    // �^�ǥ��T��m���ƭ�
    return this->point_read((pos.y), (pos.x));
}
// ���o�B�n�A�^�Ǥ@���}�C(���I��m�A�첾����)
ImrMask imgraw::getMask(ImrCoor ori, 
        ImrCoor shi = ImrCoor(-1,-1)){
    if (this->masksize.high == 0
        && this->masksize.width == 0){
        cout << "Error! Uninit masksize." << endl;
        return ImrMask();
    }
    // �ЫذʺA�}�C
    ImrMask mask;
    mask = ImrMask(this->masksize);
    // �ƻs�B�n
    for (int j = 0; j < (int)this->masksize.high; ++j){
        for (int i = 0; i < (int)this->masksize.width; ++i){
            // �B�n��m
            ImrCoor mas(j,i);
            // �ƻs�B�n�ƭ�
            mask.at2d(j,i)=this->maskVal(ori, mas, shi);
        }
    }
    // �L�X
    // for (int j = 0; j < 3; ++j){
    //     for (int i = 0; i < 3; ++i){
    //         cout << mask.at2d(j,i);
    //     }cout << endl;
    // }
    // return ImrMask();
    return mask;
}

// �]�w�B�n
void imgraw::setMaskSize(ImrSize masksize){
    this->masksize = masksize;
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

// Ū�ɳ��I(�ˬd���)
imch imgraw::point_read(imint y, imint x) {
    imint pos = (y*this->width)+x;
    return this->img_data.at(pos);
}
// �g�J�O������I(�ˬd���)
void imgraw::point_write(imint y, imint x, imch value) {
    imint pos = (y*this->width)+x;
    this->img_data.vector::at(pos) = value;
}
// �H�G���覡Ū���μg�J(�ˬd���)
imch& imgraw::at2d(size_t y, size_t x){
    size_t pos = (y*this->width)+x;
    return this->img_data.at(pos);
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
/*
            __  ___  __   __   __
    |__| | /__`  |  /  \ / _` |__)  /\   |\/|
    |  | | .__/  |  \__/ \__> |  \ /~~\  |  |

*/
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
/*-------------------------------------------------------*/

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
// ����
void imgraw::equalization(){
    // ���o�ƾڲέp
    this->histogram();
    // ��̷���
    this->extremum();
    // ���o����
    int n = this->width * this->high;
    // ���o���l
    double grand=0,S[255];
    for (int j = 0; j < 255; ++j){
        grand += this->htg_data[j];
        S[j] = grand/n;
    }
    // �ɤJ�ƾ�
    double temp;
    for (int i = 0; i < n; ++i){
        temp = S[(int)img_data.at(i)];
        img_data.at(i) = (int)(temp * (double)this->max);
    }
}
//=========================================================
//-----------------------�B��l����-------------------------
//=========================================================
// ImrCoor�B��l����
ImrCoor ImrCoor::operator+(const ImrCoor &p){
    ImrCoor temp;
    temp.y = this->y + p.y;
    temp.x = this->x + p.x;
    return temp;
}
ImrCoor ImrCoor::operator-(const ImrCoor &p){
    ImrCoor temp;
    temp.y = this->y - p.y;
    temp.x = this->x - p.x;
    return temp;
}
ImrCoor ImrCoor::operator*(const ImrCoor &p){
    ImrCoor temp;
    temp.y = this->y * p.y;
    temp.x = this->x * p.x;
    return temp;
}
ImrCoor ImrCoor::operator/(const ImrCoor &p){
    ImrCoor temp;
    temp.y = (int)((double)this->y / (double)p.y);
    temp.x = (int)((double)this->x / (double)p.x);
    return temp;
}
// ImrMask �B��l����
imch& ImrMask::operator[](const size_t __n){
    return this->mask[__n];
}
// imgraw �B��l����
imch& imgraw::operator[](const size_t __n){
    return this->img_data[__n];
}