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
// ImrPolar �B��l����
imint& ImrPolar::operator[](const size_t __n){
    return this->polar[__n];
}
const imint& ImrPolar::operator[](const size_t __n) const{
    return this->polar[__n];
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