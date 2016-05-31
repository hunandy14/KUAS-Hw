/********************************************************
Name : 
Date : 2016/05/31
By   : CharlotteHonG
Final: 2016/05/31
**********************************************************/
#include <iostream>
#include "Hw10_fun.cpp"
/*=======================================================*/
int main(int argc, char const *argv[]){
	frac<int> a(2, 3);
	a.pri();
	frac<int> b(3, 4);
	b.pri();
	frac<int> temp;
	temp = a-b;
	temp.pri();
	// frac<int> c(2, 1, 3);
	// c.pri();
	return 0;
}
/*=======================================================*/