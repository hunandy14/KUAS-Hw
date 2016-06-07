/********************************************************
Name : 
Date : 2016/05/31
By   : CharlotteHonG
Final: 2016/06/01
**********************************************************/
#include <iostream>
#include "Hw10_fun"
/*=======================================================*/
int main(int argc, char const *argv[]){
    frac<int> a(2, 2, 3);
    cout<<"a      :";a.pri();
    frac<int> b(1, 5, 6);
    cout<<"b      :";b.pri();

    frac<int> temp;
    temp = a+b;
    cout << "a+b    :";temp.pri();
    temp = a-b;
    cout << "a-b    :";temp.pri();
    temp = a*b;
    cout << "a*b    :";temp.pri();
    temp = a/b;
    cout << "a/b    :";temp.pri();

    frac<int> c(2, 2, 6);
    cout<< endl <<"c      :";c.pri();
    cout << "impro  :";
    temp = c.impro();
    temp.pri();
    cout << "mixed  :";
    temp = temp.mixed();
    temp.ep(2).as().pri();
    return 0;
}
/*=======================================================*/