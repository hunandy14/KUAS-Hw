/**********************************************************
Name : Hw09_main.cpp
Date : 2016/05/02
By   : CharlotteHonG
Final: 2016/05/24
**********************************************************/
#include <iostream>
#include <string>
#include "Hw09_fun.h"
using namespace std;
//=========================================================
int main(int argc, char const *argv[]){
    char choose=0;
    // 宣告學生
    st n[stlen+1], *np[stlen+1];
    n[stlen].active=2;//最後一個
    // 連結地址
    for (int i = 0; i < stlen; ++i){
        np[i]=&n[i];
    }
    // 預設學生
    st_input(np[0],"CharlotteHong","4a10h026",100);
    st_input(np[1],"hunandy14","4a10h027",100);
    // st_print(np[0]);

    // 選單
    int count=2;
    string s1,s2;
    int s3;
    while(choose!=-1){
        print_menu();
        cin >> choose;
        if (choose == '1'){
            system("cls");
            print_multist(np[0]);
        }
        else if (choose == '2'){
            cout << "請輸入[名字][學號][分數]:";
            cin >> s1 >> s2 >> s3;
            // cout << s1 << s2 << s3 << endl;
            st_input(np[count],s1,s2,s3);
            system("cls");
            cout << "你輸入了 => ";
            st_print(np[count]);
            count++;
        }
        else if (choose == '3'){
            system("cls");
            print_multist(np[0]);
            cout << "請輸入要刪除的[編號]:";
            int deln;
            cin >> deln;
            cout << "你刪除了 => ";
            st_print(np[deln]);
            st_delete(np[0],deln);
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