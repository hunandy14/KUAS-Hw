/**********************************************************
Name : 
Date : 2016/05/19
By   : CharlotteHonG
Final: 2016/05/19
**********************************************************/
#include <iostream>
#include "fun/Hw14_fun"
/*=======================================================*/
int main(int argc, char const *argv[]){
    Demo<int*, int> arr;
    arr.set(element,3);
    cout << "print         = ";arr.pri();
    cout << "length        = " << arr.length() << endl;
    cout << "sum           = " << arr.sum() << endl;
    cout << "product       = " << arr.product() << endl;
    cout << "square_of_sum = " << arr.square_of_sum() << endl;
	return 0;
}