#include <iostream>
#include <iomanip>
#include <string>
#include <math.h>
#include <sstream>
using namespace std;

int GCD(int a,int b);
int LCM(int a,int b);

int main(int argc, char const *argv[]){
    int num[2]={16,24},ans=0.0;
    cout << "叫块ㄢ计祘Α盢肚璸衡挡狦" << endl;
    cout << "1. 程そ计" << endl;
    cout << "2. 程そ计" << endl << endl;

    cin >> num[0] >> num[1];
    // printf("%f and %f\n\n",num[0],num[1]);
    
    cout << "矗ユ氮=\n";
    cout << "程そ计" << GCD(num[0],num[1]) << endl;
    cout << "程そ计" << LCM(num[0],num[1]) << endl;

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