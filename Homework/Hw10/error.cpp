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
    // �غc�l 
    frac();
    frac(const T1 &num, const T1 &den);
    // �B��l����
    frac operator+(const frac &a, const frac &b);
    // �L�X
    void pri();
    // ���o
    T1 get_num();
    T1 get_den();
private:
    T1 num;
    T1 den;
    //�T�w�O�_�����Ŀ�J
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
// �غc�l
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
// �L�X
template <typename T1>
void frac<T1>::pri(){
	if (flag==0){
		cout << "pri() Error!" << endl;
		return;
	}
	cout << num << "/" << den;
	cout << "(" << (double)(num/den) << ")" << endl;
}

// ���o
template <typename T1>
T1 frac<T1>::get_num(){
	return this->num;
}
template <typename T1>
T1 frac<T1>::get_den(){
	return this->den;
}

// �B��l����
template <typename T1>
frac<T1>::frac operator+(const frac &a, const frac &b){
    int den = a.get_den() * b.get_den() ;
    int num = a.get_num() * b.get_den() +
              a.get_den() * b.get_num() ;
    return sum(num,den);
}