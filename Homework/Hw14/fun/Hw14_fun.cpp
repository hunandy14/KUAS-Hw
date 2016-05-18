/**********************************************************
Name : Hw14_fun.cpp
Date : 2016/05/19
By   : CharlotteHonG
Final: 2016/05/19
**********************************************************/
#include <iostream>
#include "Hw14_fun.h"
using namespace std;

fun::fun(int* arr ,int n){
	ptr = arr;
	len = n;
}

void fun::set(int* arr, int n){
	ptr = arr;
	len = n;
}

void fun::pri(int n){
    cout << "arr[] = ";
	for (int i = 0; i < n-1; ++i){
		cout << ptr[i] << ", ";
	}cout << ptr[n] << endl;
}

void fun::pri(){
    cout << "arr[] = ";
	for (int i = 0; i < len-1; ++i){
        cout << ptr[i] << ", ";
    }cout << ptr[len] << endl;
}

int fun::sum(){
    int temp = 0;
    for (int i = 0; i < len; ++i){
        temp += ptr[i];
    }
    return temp;
}
int fun::product(){
    int temp = 1;
    for (int i = 0; i < len; ++i){
        temp *= ptr[i];
    }
    return temp;
}
int fun::square_of_sum(){
    int temp = 0;
    for (int i = 0; i < len; ++i){
        temp += ptr[i] * ptr[i];
    }
    return temp;
}