/********************************************************
Name : 
Date : 2016/05/31
By   : CharlotteHonG
Final: 2016/06/01
**********************************************************/
#include <iostream>
#include "Hw10_fun.cpp"
/*=======================================================*/
int main(int argc, char const *argv[]){
    frac<int> a(1, 1, 2);
    cout<<"a      :";a.pri();
    frac<int> b(1, 2);
    cout<<"b      :";b.pri();
    frac<int> c(2, 1, 3);
    cout<<"c      :";c.pri();

    frac<int> temp;
    temp = a+b;
    cout << endl << "a+b    :";
    temp.pri();

    cout << "impro  :";
    temp = c.impro();
    temp.pri();
    cout << "mixed  :";
    temp = temp.mixed();
    temp.pri();
    return 0;
}
/*=======================================================*/