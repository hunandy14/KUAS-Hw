/**********************************************************
Name:KUAS-Hw/Hw03
DATE:2016/03/27
By CharlotteHong
**********************************************************/

#include <iostream>
#include <iomanip>
#include <string>
#include <math.h>
#include <sstream>
using namespace std;

int lennum(float num);
string float2str(float num);

int main(int argc, char const *argv[]){
    float num[2]={0.123456,0.001},ans=0.0;
    cout << "請輸入兩個數，程式將回傳計算結果" << endl;
    cout << "第一個為小數" << endl;
    cout << "第二個為限定的小數" << endl << endl;

    cin >> num[0] >> num[1];
    // printf("%f and %f\n\n",num[0],num[1]);
    cout << "提交的答案=\n";

    for (int i = 0; i < lennum(num[0]); ++i){
    	if (i<lennum(num[1])){
    		cout << float2str(num[0])[i];
    	}
    	else{
    		cout << "0";
    	}
    }

    cout << endl;
    return 0;
}

int lennum(float num){
	stringstream ss;
	ss<<num;
	string str;
	ss>>str;
	ss.clear();
	return str.length();
}

string float2str(float num){
	stringstream ss;
	ss<<num;
	string str;
	ss>>str;
	ss.clear();
	return str;
}