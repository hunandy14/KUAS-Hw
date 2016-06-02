/**********************************************************
Name : 
Date : 2016/05/31
By   : CharlotteHonG
Final: 2016/06/01
**********************************************************/
#include <iostream>
#include "Hw10_fun.h"

// ������
template <typename T1>
frac<T1>::frac(){
    this->mix = 0;
    this->num = 0;
    this->den = 1;
    this->flag = 1;
}
template <typename T1>
frac<T1>::frac(const T1 &num, const T1 &den){
    if (den==0){
        cout << "Error dum don't at 0." << endl;
        this->flag = 0;
        return;
    }
    this->mix = 0;
    this->num = num;
    this->den = den;
    this->flag = 1;
}
template <typename T1>
frac<T1>::frac(const T1 &mix, const T1 &num, const T1 &den){
    if (den==0){
        cout << "Error dum don't at 0." << endl;
        this->flag = 0;
        return;
    }
    this->mix = mix;
    this->num = num;
    this->den = den;
    this->flag = 1;
}
// ӡ��
template <typename T1>
void frac<T1>::pri(){
    if (flag==0){
        cout << "pri() Error!" << endl;
        return;
    }
    cout << "[" << this->mix << ":";
    cout << num << "/" << this->den << "]";
    double temp = static_cast<double>
                    (this->impro().num)/
                  static_cast<double>
                    (this->impro().den);
    cout << " (" << temp << ")" << endl;
}

// ȡ��
template <typename T1>
T1 frac<T1>::get_num(){
    return this->num;
}
template <typename T1>
T1 frac<T1>::get_den(){
    return this->den;
}

// �\�������d
template <typename T1>
frac<T1> frac<T1>::operator+(const frac &p){
    frac<T1> temp;
    temp.num = this->impro().num * p.impro().den+
               this->impro().den * p.impro().num;
    temp.den = this->impro().den * p.impro().den;
    temp.mix = this->impro().mix;
    temp.flag = this->flag;
    temp = temp.as().mixed();
    return temp;
}
template <typename T1>
frac<T1> frac<T1>::operator-(const frac &p){
    frac<T1> temp;
    temp.num = this->impro().num * p.impro().den-
               this->impro().den * p.impro().num;
    temp.den = this->impro().den * p.impro().den;
    temp.mix = this->impro().mix;
    temp.flag = this->flag;
    temp = temp.as().mixed();
    return temp;
}
template <typename T1>
frac<T1> frac<T1>::operator*(const frac &p){
    frac<T1> temp;
    temp.num = this->impro().num * p.impro().num;
    temp.den = this->impro().den * p.impro().den;
    temp.mix = this->impro().mix;
    temp.flag = this->flag;
    temp = temp.as().mixed();
    return temp;
}
template <typename T1>
frac<T1> frac<T1>::operator/(const frac &p){
    frac<T1> temp;
    temp.num = this->impro().num * p.impro().den;
    temp.den = this->impro().den * p.impro().num;
    temp.mix = this->impro().mix;
    temp.flag = this->flag;
    temp = temp.as().mixed();
    return temp;
}

// �֔��D�Q
template <typename T1> // �ٷ֔�
frac<T1> frac<T1>::impro() const{
    frac<T1> temp;
    temp.mix = 0;
    temp.num = this->mix*this->den + this->num;
    temp.den = this->den;
    temp.flag = this->flag;
    temp = temp.as();
    return temp;
}
template <typename T1> // ���֔�
frac<T1> frac<T1>::mixed() const{
    frac<T1> temp;
    temp.mix = this->num / this->den;
    temp.num = this->num % this->den;
    temp.den = this->den;
    temp.flag = this->flag;
    temp = temp.as();
    return temp;
}

// ���ɼs�ֵĳ���
template <typename T1>
T1 frac<T1>::gcd() const{
    T1 a = this->num; 
    T1 b = this->den;
    if(b){
        while((a %= b) && (b %= a));
    }
    return a + b;
}
// �s��
template <typename T1>
frac<T1> frac<T1>::as(T1 n) const{
    // �ѽ������������
    if (this->num == this->num / this->gcd())
        return *this;
    // ���^�ɳ���󔵣��Ԅ�У��
    if (n > this->gcd())
        n = this->gcd();
    frac temp = *this;
    temp.num = this->num / n;
    temp.den = this->den / n;
    return temp;
}
template <typename T1>
frac<T1> frac<T1>::as() const{
    T1 n = this->gcd();
    return this->as(n);
}
// �U��
template <typename T1>
frac<T1> frac<T1>::ep(T1 n) const{
    frac temp = *this;
    temp.num = this->num * n;
    temp.den = this->den * n;
    return temp;
}

