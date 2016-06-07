/**********************************************************
Name:KUAS-Hw/Hw02
DATE:2016/03/27
By CharlotteHong
**********************************************************/

#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int main(int argc, char const *argv[]){
    double num[2],ans=0.0;
    cout << "請輸入兩個數，程式將回傳計算結果" << endl;
    cout << "第一個為數字" << endl;
    cout << "第二個為指數 " << endl  << endl;

    cin >> num[0] >> num[1];

    ans=pow(num[0],num[1]);
    cout << "提交的答案=" << ans;

    cout << endl;
    return 0;
}