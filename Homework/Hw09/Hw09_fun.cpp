/**********************************************************
Name : Hw09_fun.cpp
Date : 2016/05/24
By   : CharlotteHonG
Final: 2016/05/24
**********************************************************/
#include <iostream>
#include <string>
using namespace std;

void print_menu(){
    cout << MainMenu;
    cout << "Your choose : ";
}
void st_input(st* stru, const string name, \
    const string num, int point){
    stru->name=name;
    stru->num=num;
    stru->point=point;
    stru->active=1;
}
void st_print(st* stru){
    cout << "名字 = " << stru->name;
    cout << ", 學號 = " << stru->num;
    cout << ", 分數 = " << stru->point << endl;
}
void print_multist(int len, st* stru){
    st* temp = stru;
    for (int i = 0; i < len; ++i){
        while (1){
            if (temp->active==2)
                break;
            if (temp->active==1)
                break;
            temp++;
        }
        if (temp->active==2)
            break;
        cout << "[" << i << "]";
        cout << "名字 = " << temp->name;
        cout << ", 學號 = " << temp->num;
        cout << ", 分數 = " << temp->point << endl;
        temp++;
    }
}
void print_multist(st* stru){
    print_multist(stlen,stru);
}
void st_delete(st* stru,int id){
    st* temp = stru;
    for (int i = 0; i < stlen; ++i){
        while (1){
            if (temp->active==2)
                break;
            if (temp->active==1)
                break;
            temp++;
        }
        if (temp->active==2)
            break;

        if (i==id){
            temp->active=0;
        }
        temp++;
    }
}
//=========================================================
