/**********************************************************
Name : Hw09_main.cpp
Date : 2016/05/02
By   : CharlotteHonG
Final: 2016/05/24
**********************************************************/
#include <iostream>
#include <string>
#include "Hw09_fun.cpp"
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
    st_input(np[0],"CharlotteHong","4a10h026",100);
    st_input(np[1],"hunandy14","4a10h027",100);
    // st_print(np[0]);

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
            st_input(np[count],s1,s2,s3);
            system("cls");
            cout << "�A��J�F => ";
            st_print(np[count]);
            count++;
        }
        else if (choose == '3'){
            system("cls");
            print_multist(np[0]);
            cout << "�п�J�n�R����[�s��]:";
            int deln;
            cin >> deln;
            cout << "�A�R���F => ";
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