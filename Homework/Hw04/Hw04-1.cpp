/**********************************************************
Name:KUAS-Hw/Hw04-1
DATE:2016/03/27
Final:2016/04/010
By CharlotteHong
**********************************************************/
#include <iostream>
using namespace std;

int GCD(int a,int b);
int LCM(int a,int b);

int main(int argc, char const *argv[]){
    int num[2];
    cout << "�п�J��ӼơA�{���N�^�ǭp�⵲�G" << endl;
    cout << "1. �̤j���]��" << endl;
    cout << "2. �̤p������" << endl << endl;

    cin >> num[0] >> num[1];
    cout << "���檺����=\n";
    cout << "�̤j���]��" << GCD(num[0],num[1]) << endl;
    cout << "�̤p������" << LCM(num[0],num[1]) << endl;

    cout << endl;
    return 0;
}

int GCD(int a,int b){
    if ( a % b == 0)
        return b;
    else
        return GCD ( b,a % b);
}

int LCM(int a,int b){
    int temp_lcm;
    temp_lcm=a*b/GCD(a,b);
    return temp_lcm;
}