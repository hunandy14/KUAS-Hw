#include <stdio.h>
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int data=99;
	char str[32];
	string str2;
	sprintf(str, "%d", data);
	cout << "str = " << str << endl;

	return 0;
}