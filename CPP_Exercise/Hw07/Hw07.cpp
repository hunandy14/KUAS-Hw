/**********************************************************
Name:KUAS-Hw/Hw07
DATE:2016/03/27
By CharlotteHong
**********************************************************/

//=========================================================
#include <iostream>
using namespace std;
//=========================================================
void printstr(string str);
void string_modify(string* str);
void string_upper(string* str);
void string_lower(string* str);
void print_menu();
void string_msingle(string* str);
//=========================================================
string MainMenu("\
\n\
=================================\n\
        MainMenu\n\
=================================\n\
    1. modify String ALL.\n\
    2. modify to Upper case.\n\
    3. modify to Lower case.\n\
    4. modify String single.\n\
    Q. Exit\n\
=================================\n\
");

string instr=("CharlotteHong");
//=========================================================
int main(int argc, char const *argv[]){
    char choose=0;

    while(choose!=-1){
        print_menu();
        cin >> choose;
        if (choose == '1'){
            string_modify(&instr);
            system("cls");
            choose=0;
        }
        else if (choose == '2'){
            system("cls");
            string_upper(&instr);
        }
        else if (choose == '3'){
            system("cls");
            string_lower(&instr);
        }

        else if (choose == '4'){
            string_msingle(&instr);
            system("cls");
        }

        else if (choose == 'Q' || choose == 'q'){
            system("cls");
            choose=-1;
        }
    }

    cout << endl;
    return 0;
}
//=========================================================
void string_msingle(string* str){
    int num=0;
    char ch[1];
    cout << "Input index(lenth:0~" << str[0].length()-1 << "):" ;
    cin >> num ;
    cout << "Input one char : ";
    cin >> ch[0];
    str[0][num]=ch[0];
}

void print_menu(){
    cout << MainMenu;
    printstr(instr);
    cout << "Your choose : ";
}

void string_upper(string* str){
    for (int i = 0; i < (int)str[0].length(); ++i)
        str[0][i]=toupper(str[0][i]);
}

void string_lower(string* str){
    for (int i = 0; i < (int)str[0].length(); ++i)
        str[0][i]=tolower(str[0][i]);
}

void printstr(string str){
    cout << "String = " << str <<endl;
}

void string_modify(string* str){
    cout << "Input new string :";
    cin >> *str;
}
//=========================================================