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
#include "Hw15_fun.cpp"
//=========================================================
int main(int argc, char const *argv[]){
    while(choose!=-1){
        cout << MainMenu << endl;
        cin >> choose;
        if (choose == '1'){
            system("cls");
            cout << "1. ��J�Ʀr�r�� (1) => �^��r��(One)" << endl;
            str_in.erase();
            cin >> str_in;
            cout << endl << one(str_in) << endl;
        }
        else if (choose == '2'){
            system("cls");
            cout << "2. ��J��r�r�� �̨C�r��̨C2����}" << endl;
            str_in.erase();
            cin >> str_in;
            cout << endl << two(str_in,2) << endl;
        }
        else if (choose == '3'){
            system("cls");
            cout << "3. ��J��r�r�� �H�ťչj�} => �^�Ǥl�r�ꪺ����" \
                << endl;
            cout << "�Цb�����B��J[�_��:]�@�������r�� =>" << endl;
            str_in.erase();
            getline(cin,str_in,':');
            str_in=str_in.substr(1);// ��������(����o���󦳸���)
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