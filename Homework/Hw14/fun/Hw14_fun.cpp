/**********************************************************
Name : Hw14_fun.cpp
Date : 2016/05/19
By   : CharlotteHonG
Final: 2016/05/19
**********************************************************/
#include <iostream>
#include "Hw14_fun.h"

template <typename T1, typename T2>
class Demo {
    public:
        /* setter */
        Demo(){
            this->ptr = NULL;
            this->len = 0;
        }
        Demo(const T1 &p, const T2 &n) {
            this->ptr = p;
            this->len = n;
        }
        void set(const T1 &p, const T2 &n){
            this->ptr = p;
            this->len = n;
        }
        /* getter */
        void pri(const T2 &n){
            for (int i = 0; i < n-1; ++i){
                cout << ptr[i] << ",";
            }cout << ptr[n-1] << endl;
        }
        void pri(){
            pri(len);
        }
        T2 length(){
            return len;
        }
        /* function */
        T2 sum(){
            T2 temp = 0;
            for (int i = 0; i < len; ++i){
                temp += ptr[i];
            }
            return temp;
        }
        T2 product(){
            T2 temp = 1;
            for (int i = 0; i < len; ++i){
                temp *= ptr[i];
            }
            return temp;
        }
        T2 square_of_sum(){
            T2 temp = 0;
            for (int i = 0; i < len; ++i){
                temp += ptr[i] * ptr[i];
            }
            return temp;
        }

    private:
        T1 ptr;
        T2 len;
};
