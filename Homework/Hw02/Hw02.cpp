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
    cout << "�п�J��ӼơA�{���N�^�ǭp�⵲�G" << endl;
    cout << "�Ĥ@�Ӭ��Ʀr" << endl;
    cout << "�ĤG�Ӭ����� " << endl  << endl;

    cin >> num[0] >> num[1];

    ans=pow(num[0],num[1]);
    cout << "���檺����=" << ans;

    cout << endl;
    return 0;
}