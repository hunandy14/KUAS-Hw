/**********************************************************
Name : Hw14_fun.cpp
Date : 2016/05/19
By   : CharlotteHonG
Final: 2016/05/19
**********************************************************/
#include <iostream>

/* setter */
template <typename T1, typename T2>
Demo<T1,T2>::Demo(){
    this->len = 0;
    this->ptr = NULL;
}
template <typename T1, typename T2>
Demo<T1,T2>::Demo(const T1 &p, const T2 &n) {
    this->ptr = p;
    this->len = n;
}
template <typename T1, typename T2>
void Demo<T1,T2>::set(const T1 &p, const T2 &n){
    this->ptr = p;
    this->len = n;
}

/* getter */
template <typename T1, typename T2>
void Demo<T1,T2>::pri(const T2 &n){
    for (int i = 0; i < n-1; ++i){
        cout << ptr[i] << ",";
    }cout << ptr[n-1] << endl;
}

template <typename T1, typename T2>
void Demo<T1,T2>::pri(){
    pri(len);
}

template <typename T1, typename T2>
T2 Demo<T1,T2>::length(){
    return len;
}

/* function */
template <typename T1, typename T2>
T2 Demo<T1,T2>::sum(){
    T2 temp = 0;
    for (int i = 0; i < len; ++i){
        temp += ptr[i];
    }
    return temp;
}

template <typename T1, typename T2>
T2 Demo<T1,T2>::product(){
    T2 temp = 1;
    for (int i = 0; i < len; ++i){
        temp *= ptr[i];
    }
    return temp;
}

template <typename T1, typename T2>
T2 Demo<T1,T2>::square_of_sum(){
    T2 temp = 0;
    for (int i = 0; i < len; ++i){
        temp += ptr[i] * ptr[i];
    }
    return temp;
}