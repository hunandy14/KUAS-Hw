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
    cout << "�п�J��ӼơA�{���N�^�ǭp�⵲�G" << endl;
    cout << "�Ĥ@�Ӭ��p��" << endl;
    cout << "�ĤG�Ӭ����w���p��" << endl << endl;

    cin >> num[0] >> num[1];
    // printf("%f and %f\n\n",num[0],num[1]);
    cout << "���檺����=\n";

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