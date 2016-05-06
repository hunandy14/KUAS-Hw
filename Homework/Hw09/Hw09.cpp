/**********************************************************
Name:KUAS-Hw/Hw09
DATE:2016/05/02
By CharlotteHong
**********************************************************/

//=========================================================
#include <iostream>
#include <string>
using namespace std;
//=========================================================
#define stlen 10
typedef struct Stust_index st;
struct Stust_index{
    string name;
    string num;
    int point;
    int active = 0;

};
//=========================================================
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
//=========================================================
void print_menu();
void input_st(st* stru, const string name, \
    const string num, int point){
    stru->name=name;
    stru->num=num;
    stru->point=point;
    stru->active=1;
}
void print_st(st* stru){
    cout << "�W�r = " << stru->name;
    cout << ", �Ǹ� = " << stru->num;
    cout << ", ���� = " << stru->point << endl;
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
        cout << "�W�r = " << temp->name;
        cout << ", �Ǹ� = " << temp->num;
        cout << ", ���� = " << temp->point << endl;
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
int main(int argc, char const *argv[]){
    char choose=0;
    // �ŧi�ǥ�
    st n[stlen+1], *np[stlen+1];
    n[stlen].active=2;//�̫�@��
    // �s���a�}
    for (int i = 0; i < stlen; ++i){
        np[i]=&n[i];
    }
    // �w�]�ǥ�
    input_st(np[0],"CharlotteHong","4a10h026",100);
    input_st(np[1],"hunandy14","4a10h027",100);
    // print_st(np[0]);

    // ���
    int count=1;
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
            cout << "�п�J[�W�r][�Ǹ�][����]:";
            cin >> s1 >> s2 >> s3;
            // cout << s1 << s2 << s3 << endl;
            input_st(np[count],s1,s2,s3);
            system("cls");
            cout << "�A��J�F => ";
            print_st(np[count]);
            count++;
        }
        else if (choose == '3'){
            system("cls");
            print_multist(np[0]);
            cout << "�п�J�n�R����[�s��]:";
            int deln;
            cin >> deln;
            cout << "�A�R���F => ";
            print_st(np[deln]);
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
void print_menu(){
    cout << MainMenu;
    cout << "Your choose : ";
}
//=========================================================