#include <iostream>
#include <fstream>
#include "StringSplit.cpp"
#include "file_inout.cpp"
using namespace std;

string MainMenu("\
\n\
=================================\n\
        MainMenu\n\
=================================\n\
    1. �s�W���\n\
    2. �ƧǸ��\n\
    3. �d�ݸ��\n\
    Q. Exit\n\
=================================\n\
");
void print_menu(){
    cout << MainMenu;
    cout << "Your choose : ";
}

int main(int argc, char const *argv[]){
    string filename="file.txt",Default="*";

    cout << "1.�p�G�S���|�۰ʫإ�" << endl;
    cout << "2.��J*�w�]�ɦW��file.txt" << endl;
    cout << "3.�|�۰ʸɰ��ɦW.txt" << endl;
    cout << "#�п�J�ɦW�G" << endl;
    cin >> filename;
    if (filename=="*"){
        filename="file.txt";
    }
    else
        filename+=".txt";
    /* �}���ɮ�(���լO�_�i�}) */
    file_open(filename.c_str());



    /* Ū���ɮ� */
    string file_str = file_readstr(filename.c_str());
    // cout << file_str << endl;

    /* ���o��� */
    int line_len = file_linelen(filename.c_str());
    // cout << line_len << endl;

    /* �NŪ������ƨ̦�Ʀs�i�}�C */
    string *data_arr = file_data(file_str,line_len);

    /* ���Φh��ƾ�,�è��X���ƭ� */
    string *strarr;
    int Field=2;
    int *data_valu = new int[line_len];
    for (int i = 1; i < line_len; ++i){
        strarr=str_split(data_arr[i].c_str());
        sscanf(strarr[Field].c_str(), "%d", &data_valu[i-1]);
        cout << "   " << data_valu[i-1] << endl;
        // strarr_print(strarr);
    }



    /* ��� */
    char choose=0;
    while(choose!=-1){
        print_menu();
        cin >> choose;
        if (choose == '1'){;
            system("cls");
            /* ��J��� */
            cout << "�п�J [�m�W],[�~��],[����],[���J]" << endl;
            string indata=file_instr();
            cout << "��J����� = " << indata << endl;
            file_write(filename.c_str(),indata.c_str());

        }
        else if (choose == '2'){
            system("cls");
        }
        else if (choose == '3'){
            system("cls");
            /* Ū���ɮ� */
            string file_str = file_readstr(filename.c_str());
            cout << file_str << endl;
        }

        else if (choose == 'Q' || choose == 'q'){
            system("cls");
            choose=-1;
        }
    }


    /* Ū���ɮ� */
    // string file_str = file_readstr(filename.c_str());
    // cout << file_str << endl;

    /* ���o��� */
    // int line_len = file_linelen(filename.c_str());
    // cout << line_len << endl;

    /* �NŪ������ƨ̦�Ʀs�i�}�C */
    // string *data_arr = file_data(file_str,line_len);

    /* ���γ��ƾ�,�H�r�������Φs�i�G���}�C */
    // string *strarr=str_split(data_arr[1].c_str());

    // strarr_print(strarr);

    // delete [] data_arr;
    return EXIT_SUCCESS;
}