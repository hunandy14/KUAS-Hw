/**********************************************************
Name : OpenRaw 2.4
Date : 2016/08/03
By   : CharlotteHonG
Final: 2016/09/25
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
imgraw::imgraw(ImrSize size) {
    imint x = size.width;
    imint y = size.high;
    this->width = x;
    this->high = y;
    this->img_data.vector::resize(x*y);
    this->filesize = x*y;
    this->masksize = ImrSize(0,0);
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
const imch& ImrMask::at2d(size_t y, size_t x) const{
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
imch& imgraw::maskVal(ImrCoor ori, ImrCoor mas, 
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
    return this->at2d((pos.y), (pos.x));
}
const imch& imgraw::maskVal(ImrCoor ori, ImrCoor mas, 
        ImrCoor shi=ImrCoor(-1,-1)) const{
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
    return this->at2d((pos.y), (pos.x));
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

/*
     ##   ##                             ##
     ##   ##                             ##
     ##   ##   #####   ##   ##   ######  ######
     #######  ##   ##  ##   ##  ##   ##  ##   ##
     ##   ##  ##   ##  ##   ##  ##   ##  ##   ##
     ##   ##  ##   ##  ##  ###   ######  ##   ##
     ##   ##   #####    ### ##       ##  ##   ##
                                 #####
*/
void ImrMask::info(string title){
    cout << title << endl;
    for (int j = 0; j < (int)masksize.high; ++j){
        for (int i = 0; i < (int)masksize.width; ++i){
            cout << (int)this->at2d(j, i) << " ";
        }cout << endl;
    }cout << endl;
}
// ��t����(�֭�, �ǰt�C��, �I���C��)
void imgraw::sobel(int thr, imch value=128, imch bg=32){
    ImrMask p;
    imgraw s=*this;
    for (int j = 0; j < (int)this->high; ++j){
        for (int i = 0; i < (int)this->width; ++i){
            // �֤߹B�� 1
            // this->setMaskSize(ImrSize(3, 3));
            // p = this->getMask(ImrCoor(j, i));

            // double s1=
            //         (p[0]+2*p[1]+p[2])
            //        -(p[6]+2*p[7]+p[8]);
            // double s2=
            //         (p[2]+2*p[5]+p[8])
            //        -(p[0]+2*p[3]+p[6]);

            // �֤߹B�� 2
            ImrCoor ori(j, i);
            double s1 = 
                (
                  s.maskVal(ori, ImrCoor(0, 0)) +
                  2*s.maskVal(ori, ImrCoor(0, 1)) +
                  s.maskVal(ori, ImrCoor(0, 2))
                ) -
                (
                  s.maskVal(ori, ImrCoor(2, 0)) +
                  2*s.maskVal(ori, ImrCoor(2, 1)) +
                  s.maskVal(ori, ImrCoor(2, 2))
                );
            double s2 =
                (
                  s.maskVal(ori, ImrCoor(0, 2)) +
                  2*s.maskVal(ori, ImrCoor(1, 2)) +
                  s.maskVal(ori, ImrCoor(2, 2))
                ) -
                (
                  s.maskVal(ori, ImrCoor(0, 0)) +
                  2*s.maskVal(ori, ImrCoor(1, 0)) +
                  s.maskVal(ori, ImrCoor(2, 0))
                );

            // �P�_�֭�
            double sobel = abs(s1)+abs(s2);
            if(thr >= (int)sobel) {
                this->at2d(j, i) = (imch)bg;
            }else{
                this->at2d(j, i) = (imch)value;
            }
        }
    }
}
// ���N�ҽu��(�u����, �u���C��, soble�ǰt�C��)
void imgraw::hough(imint n, imch line_value=255, imch match_value=128){
    int h = (int)this->high;
    int w = (int)this->width;
    // �̤j���
    int big = h>w? h: w;
    // �̤j�Z��
    int maxdis = (int)(big*sqrt(2)+1);
    // �Ыؽw�s(2���O���F������)
    imgraw P(ImrSize(2*maxdis, 180));
    // �M��Ҧ����I��P��
    for (int j = 0; j < (int)this->high; ++j){
        for (int i = 0; i < (int)this->width; ++i){
            // ����I
            if (this->at2d(j, i) == match_value){
                // �O���Ҧ����ת�P��
                for (int k = 0; k < 180; ++k){
                    int ang = k;
                    int dis = j*sin(ang*PI/180) +
                              i*cos(ang*PI/180);
                    // �����ơA�h�[�FD�A����n��^��
                    P.at2d(dis+maxdis, ang) += 1;
                }
            }
        }
    }
    // �]�w�̤j����
    P.set_Maxdis(maxdis);

    for (int i = 0; i < (int)n; ++i){   
        // �䭫�Ƴ̦h�����y�� (�Z��, ����)
        // ImrCoor polar = P.get_P();
        // �ھڧ�쪺���y��ø��
        // this->draw_line(polar);
        this->draw_line(ImrCoor(P.get_P()), line_value);
    }
}

// �e�u(���u��)
void imgraw::draw_line(ImrCoor polar, imch value){
    for (int j = 0; j < (int)this->high; ++j){
        for (int i = 0; i < (int)this->width; ++i){
            int dis = (int)(i*cos(polar.x*PI/180)) +
                      (int)(j*sin(polar.x*PI/180));
            if( dis == polar.y) {
                this->at2d(j, i) = value;
            }
        }
    }
}

// �䭫�Ƴ̦h��P�I�A�^�ǥؼЪ� (�Z��, ����)
/*
1. �ݥ�set_Maxdis()
2.����k�����img�����O��ƨөI�s
*/
ImrCoor imgraw::get_P(){ 
    int dis=0, ang=0;
    // �̤j�Z��
    int maxdis=this->high;
    // �䭫�Ƴ̦h��P�I
    int target;
    int temp=0;
    for (int i = 0; i < maxdis*180; ++i){
        if (temp < (int)(*this)[i] && (int)(*this)[i] < this->P_limit){
            temp = (int)(*this)[i];
            target = i;
        }
    }this->P_limit=temp;
    // �o�̪�dis�٨S�B�z���[�W�h��D
    dis=target/180 - maxdis/2;
    ang=target%180;
    return ImrCoor(dis, ang);
}
void imgraw::set_Maxdis(int maxdis){
    this->P_limit=2*maxdis*180;
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
const imch& imgraw::at2d(size_t y, size_t x) const{
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
            temp = this->at2d(j,i);
            if (temp > this->max){
                this->max = temp;
            }else if (temp < this->min){
                this->min = temp;
            }
        }
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
const imch& ImrMask::operator[](const size_t __n) const{
    return this->mask[__n];
}
// imgraw �B��l����
imch& imgraw::operator[](const size_t __n){
    return this->img_data[__n];
}
const imch& imgraw::operator[](const size_t __n) const{
    return this->img_data[__n];
}
imgraw imgraw::operator+(const imgraw &p){
    // ��o�̤j����
    imint y = this->high>p.high? this->high: p.high;
    imint x = this->width>p.width? this->width: p.width;
    // �ЫؼȦs�v��
    imgraw temp(ImrSize(y, x));
    // ���o�v���`����
    int len = (int)this->high * (int)this->width;
    // ���I�ۥ[
    for (int i = 0; i < len; ++i){
        if ((double)(*this)[i]+(double)p[i] > (double)255){
            temp[i] = (imch)255;
        }
        else{
            temp[i] = (*this)[i]+p[i];
        }
    }
    return temp;
}
imgraw imgraw::operator+(const imch value){
    // ��o�̤j����
    imint y = this->high;
    imint x = this->width;
    // �ЫؼȦs�v��
    imgraw temp(ImrSize(y, x));
    // ���o�v���`����
    int len = (int)this->high * (int)this->width;
    // ���I�ۥ[
    for (int i = 0; i < len; ++i){
        if ((double)(*this)[i]+value > (double)255){
            temp[i] = (imch)255;
        }
        else{
            temp[i] = (*this)[i]+value;
        }
    }
    return temp;
}
imgraw imgraw::operator-(const imgraw &p){
    // ��o�̤j����
    imint y = this->high>p.high? this->high: p.high;
    imint x = this->width>p.width? this->width: p.width;
    // �ЫؼȦs�v��
    imgraw temp(ImrSize(y, x));
    // ���o�v���`����
    int len = (int)this->high * (int)this->width;
    // ���I�۴�
    for (int i = 0; i < len; ++i){
        if ((double)(*this)[i]-(double)p[i] < 0){
            temp[i] = (imch)0;
        }
        else{
            temp[i] = (*this)[i]-p[i];
        }
    }
    return temp;
}
imgraw imgraw::operator-(const imch value){
    // ��o�̤j����
    imint y = this->high;
    imint x = this->width;
    // �ЫؼȦs�v��
    imgraw temp(ImrSize(y, x));
    // ���o�v���`����
    int len = (int)this->high * (int)this->width;
    // ���I�ۥ[
    for (int i = 0; i < len; ++i){
        if ((double)(*this)[i]-value < (double)0){
            temp[i] = (imch)0;
        }
        else{
            temp[i] = (*this)[i]-value;
        }
    }
    return temp;
}