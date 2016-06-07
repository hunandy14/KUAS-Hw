/**********************************************************
Name : Hw09_fun.h
Date : 2016/05/24
By   : CharlotteHonG
Final: 2016/05/24
**********************************************************/
#ifndef HW09_FUN_H
#define HW09_FUN_H

#define stlen 10
using namespace std;

typedef struct Stust_index st;
struct Stust_index{
    string name;
    string num;
    int point;
    int active = 0;
};

string MainMenu("\
\n\
=================================\n\
        MainMenu\n\
=================================\n\
    1. �d�ݩҦ��ǥ�\n\
    2. �s�W�ǥ�\n\
    3. �R���ǥ�\n\
    Q. Exit\n\
=================================\n\
");

void print_menu();
void st_input(st* stru, const string name, \
    const string num, int point);
void st_print(st* stru);
void print_multist(int len, st* stru);
void print_multist(st* stru);
void st_delete(st* stru,int id);
//=========================================================
#include "Hw09_fun.cpp"

#endif
