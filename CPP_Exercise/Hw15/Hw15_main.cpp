/**********************************************************
Name:KUAS-Hw/Hw15
Date:2016/05/10
Final:2016/05/11
By CharlotteHong
**********************************************************/
#include <iostream>
#include <sstream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include "Hw15_fun.h"
//=========================================================
int main(int argc, char const *argv[]){
    while(choose!=-1){
        cout << MainMenu << endl;
        cin >> choose;
        if (choose == '1'){
            system("cls");
            cout << "1. 輸入數字字串 (1) => 英文字串(One)" << endl;
            str_in.erase();
            cin >> str_in;
            cout << endl << one(str_in) << endl;
        }
        else if (choose == '2'){
            system("cls");
            cout << "2. 輸入文字字串 依每字串依每2位分開" << endl;
            str_in.erase();
            cin >> str_in;
            cout << endl << two(str_in,2) << endl;
        }
        else if (choose == '3'){
            system("cls");
            cout << "3. 輸入文字字串 以空白隔開 => 回傳子字串的長度" \
                << endl;
            cout << "請在結尾處輸入[冒號:]作為結束字符 =>" << endl;
            str_in.erase();
            getline(cin,str_in,':');
            str_in=str_in.substr(1);// 消除跳行(不曉得為何有跳行)
            string str_out = three(str_in);
            cout << str_out << endl;
        }

        else if (choose == 'Q' || choose == 'q'){
            system("cls");
            choose=-1;
        }
    }
    return 0;
}