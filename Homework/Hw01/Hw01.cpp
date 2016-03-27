/**********************************************************
Name:KUAS-Hw/Hw01
DATE:2016/03/27
By CharlotteHong
**********************************************************/

#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[]){
    char str[]="HelloWord";
    int array[10];

    for (int i = 0; i < 9; ++i){
        cout << str[i] << "=" << (int)str[i] << ",";
        array[i]=(int)str[i];
    }
    cout << endl;

    for (int i = 0; i < 9; ++i){
        cout << (char)array[i];
    }
    cout << endl;

    return 0;
}