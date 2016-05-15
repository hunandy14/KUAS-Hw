/**********************************************************
Name : Hw16.cpp
Date : 2016/05/15
By   : CharlotteHonG
Final: 2016/05/15
**********************************************************/
#include <iostream>
#define floor 13
using namespace std;

enum of_flag{underflow, overflow};
unsigned long stratum(int n);

int main(int argc, char const *argv[]){
    unsigned long num;
    try{
        for (int i = 0; i <= floor; ++i){
            num = stratum(i);
            cout << "[" << i << "!]";
            cout << num << endl;
        }
    }catch(of_flag e){
        if(e == underflow){
            cout<<"overflow!"<<endl;
            exit(-1);
        }if(e == overflow){
            cout<<"overflow!"<<endl;
            exit(-1);
        }
    }
    return 0;
}

unsigned long stratum(int n){
    unsigned long long num=1, limit=4294967295;
    for (int i = 1  ; i <= n; ++i){
        num*=i;
        if(num > limit ){
            cout << "[" << i << "!]";
            throw overflow;
        }
        if(num < 0){
            cout << "[" << i << "!]";
            throw underflow;
        }
    }
    return num;
}
/*=======================================================*/