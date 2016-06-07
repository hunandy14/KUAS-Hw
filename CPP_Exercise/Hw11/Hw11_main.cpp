/**********************************************************
Name : Hw11_main
Date : 2016/05/15
By   : CharlotteHonG
Final: 2016/05/15
**********************************************************/
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Hw11_main.h"
using namespace std;

int main(int argc, char const *argv[]){
    /* ��l�ưT�� */
    string filename="file.txt", Default="*";
    cout << init_message;
    cin >> filename;
    /* ��J�ɦW */
    if (filename == Default)
        filename="file.txt";
    else
        filename+=".txt";
    /* �}���ɮ�(���լO�_�i�}) */
    file_open(filename.c_str());


    /* ��� */
    char choose=0;
    while(choose!=-1){
        cout << MainMenu << "Your choose : ";
        cin >> choose;

        if (choose == '1'){;
            system("cls");
            /* ��J��� */
            cout << "�`�N���n��J�h�l��0,�p[05,01]" << endl;
            cout << "�п�J [�m�W],[�~��],[����],[���J]" << endl;
            string indata = "\n" + file_instr();
            cout << "��J����� = " << indata << endl;
            file_write(filename.c_str(),indata.c_str());
        }
        else if (choose == '2'){
            system("cls");
            /* Ū���ɮ� */
            string file_str = file_readstr(filename.c_str());
            /* ���o��� */
            int line_len = file_linelen(filename.c_str());
            /* �NŪ������ƨ̦�Ʀs�i�}�C */
            string* data_arr = file_data(file_str, line_len);
            /* �N��Ʀs�J�G��string */
            string** data_arrd = file_datad(data_arr, line_len);
            /* �ƧǸ�� */
            sort_str(data_arrd, line_len-1);
            /* �G���}�C�r�����@�r�� */
            string str_seq;
            str_seq = string_2one(data_arrd, line_len);
            cout << "[" << str_seq << "]" << endl;
            /* �g�J�ɮ� */
            file_whead(filename.c_str());
            file_write(filename.c_str(), ("\n"+str_seq).c_str());
        }
        else if (choose == '3'){
            system("cls");
            /* Ū���ɮ� */
            string file_str = file_readstr(filename.c_str());
            cout << file_str << endl;
        }

        else if (choose == 'Q' || choose == 'q'){
            choose=-1;
        }
    }
    return 0;
}