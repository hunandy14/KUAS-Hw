/**********************************************************
Name : string_creator.cpp
Date : 2016/05/15
By   : CharlotteHonG
Final: 2016/05/15
**********************************************************/
#include <iostream>
#include <string>
using namespace std;
/*=======================================================*/
string** string_creator(int col, int row){
	string** ptr = NULL;
	ptr = new string*[col];
	for (int i = 0; i < col; ++i)
		ptr[i] = new string[row];
	return ptr;
}
string* string_creator(int row){
	string* ptr = NULL;
	ptr = new string[row];
	return ptr;
}
// int main(int argc, char const *argv[]){
// 	/* 創建方法 - 注意星號數量 */
// 	string *str1=string_creator(16);
// 	string **str2=string_creator(4, 2);
	
// 	/* 使用範例1 */
// 	str1[15]="[str1]Charloote";
// 	cout << "str1[15]      = ";
// 	cout << str1[15] << endl;
// 	cout << "str1[15][4]   = ";
// 	cout << str1[15][4] << endl;
// 	// 歸還
// 	delete [] str1;

// 	/* 使用範例2 */
// 	str2[3][1]="[str2]Charloote";
// 	cout << "str2[3][1]    = ";
// 	cout << str2[3][1] << endl;
// 	cout << "str2[3][1][4] = ";
// 	cout << str2[3][1][4] << endl;
// 	// 歸還
// 	delete [] str2;
// 	return 0;
// }
/*=======================================================*/