/**********************************************************
Name : Hw14_main.cpp
Date : 2016/05/19
By   : CharlotteHonG
Final: 2016/05/19
**********************************************************/
#include <iostream>
#include "fun/Hw14_fun.cpp"
/*=======================================================*/
using namespace std;
/*=======================================================*/
int main(int argc, char const *argv[]){
	fun a(element,3);
	a.pri();
	cout << "sum() = " << a.sum() << endl;
	cout << "product() = " << a.product() << endl;
	cout << "square_of_sum() = " << a.square_of_sum() << endl;
	return 0;
}
/*=======================================================*/