/********************************************************
Name : 
Date : 2016/05/31
By   : CharlotteHonG
Final: 2016/05/31
**********************************************************/
#include <iostream>
using namespace std;

template <typename T1>
class frac{
public:
    // 建構子 
    frac();
    frac(const T1 &num, const T1 &den);
    // 運算子重載
    frac operator+(const frac &b);
    // 印出
    void pri();
    // 取得
    T1 get_num();
    T1 get_den();
private:
    T1 num;
    T1 den;
    //確定是否為有效輸入
    int flag=0;
};
/*=======================================================*/
int main(int argc, char const *argv[]){
	frac<double> a(3, 4);
	a.pri();
	frac<double> b(5, 4);
	b.pri();
	frac<double> temp;
	// temp = a+b;

	return 0;
}
/*=======================================================*/
// 建構子
template <typename T1>
frac<T1>::frac(){
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
	cout << num << "/" << den;
	cout << "(" << (double)(num/den) << ")" << endl;
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
frac<T1>::frac operator+(const frac &b){
    int den = This->den * b.den ;
    int num = This->num * b.den +
              This->den * b.num ;
    return sum(num,den);
}