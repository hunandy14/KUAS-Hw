/**********************************************************
Name : 
Date : 2016/05/31
By   : CharlotteHonG
Final: 2016/06/01
**********************************************************/
#include <iostream>
#include "Hw10_fun.h"

// 建構子
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
// 印出
template <typename T1>
void frac<T1>::pri(){
	if (flag==0){
		cout << "pri() Error!" << endl;
		return;
	}
	cout << "[" << mix << ":";
	cout << num << "/" << den << "]";
	double temp = static_cast<double>(num)/ 
				  static_cast<double>(den);
	cout << " (" << temp << ")" << endl;
}

// 取得
template <typename T1>
T1 frac<T1>::get_num(){
	return this->num;
}
template <typename T1>
T1 frac<T1>::get_den(){
	return this->den;
}

// 運算子重載
template <typename T1>
frac<T1> frac<T1>::operator+(const frac &p){
	frac<T1> temp;
	
	frac<T1> t1,t2;
	// t1=this->impro();
	// t1.pri();
	// t2=p.impro();
	// t2.pri();

	temp.num = this->num * p.den+
			   this->den * p.num;
	temp.den = this->den * p.den;
	// temp.mix = this->mix;
	temp.flag = this->flag;
    return temp;
}
template <typename T1>
frac<T1> frac<T1>::operator-(const frac &p){
	frac<T1> temp;
	temp.num = this->num * p.den-
			   this->den * p.num;
	temp.den = this->den * p.den;
	// temp.mix = this->mix;
	temp.flag = this->flag;
    return temp;
}
template <typename T1>
frac<T1> frac<T1>::operator*(const frac &p){
	frac<T1> temp;
	temp.num = this->num * p.num;
	temp.den = this->den * p.den;
	// temp.mix = this->mix;
	temp.flag = this->flag;
    return temp;
}
template <typename T1>
frac<T1> frac<T1>::operator/(const frac &p){
	frac<T1> temp;
	temp.num = this->num * p.den;
	temp.den = this->den * p.num;
	// temp.mix = this->mix;
	temp.flag = this->flag;
    return temp;
}

// 分數轉換
template <typename T1> // 假分數
frac<T1> frac<T1>::impro(){
	frac<T1> temp;
	temp.mix = 0;
	temp.num = this->mix*this->den + this->num;
	temp.den = this->den;
	temp.flag = this->flag;
	return temp;
}
template <typename T1> // 帶分數
frac<T1> frac<T1>::mixed(){
	frac<T1> temp;
	temp.mix = this->num / this->den;
	temp.num = this->num % this->den;
	temp.den = this->den;
	temp.flag = this->flag;
	return temp;
}