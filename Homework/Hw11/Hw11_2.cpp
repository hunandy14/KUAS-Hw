#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
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
    int Field=2; //Ū�����@��
    int *data_valu = new int[line_len]; // Ū�������
    for (int i = 1; i < line_len; ++i){
        strarr=str_split(data_arr[i].c_str());
        sscanf(strarr[Field].c_str(), "%d", &data_valu[i-1]);
        // istringstream is(strarr[Field]);
        // is>>data_valu[i];
        // cout << "   " << data_valu[i-1] << endl;
        // strarr_print(strarr);
    }

    /* ��XŪ���檺�j��p�Ƨ� */
    int data_temp, data_big=0, data_small=0;
    //��X�̤j��
    data_temp=data_valu[0];
    for (int i = 1; i < line_len-1; ++i){//�Ĥ@�椣�O�ƾ�
        if (data_temp <= data_valu[i]){
            data_temp=data_valu[i];
            data_big=i;
        }
    }
    // cout << data_big << endl;
    //��X�̤p��
    data_temp=data_valu[0];
    for (int i = 1; i < line_len-1; ++i){//�Ĥ@�椣�O�ƾ�
        if (data_temp >= data_valu[i]){
            data_temp=data_valu[i];
            data_small=i;
        }
    }
    // cout << data_small << endl;

    // ��X����
    int *data_seq = new int[line_len]; // Ū������ȱƧ�
    data_temp = data_valu[data_small];
    // cout << data_temp << endl;
    data_seq[0]=data_big;
    for (int j = 1; j < 4; ++j){
        for (int i = 0; i < line_len-1; ++i){
            // cout << data_valu[i] << endl;
            cout << data_valu[data_seq[j-1]] << endl;
            // �˴��O�_�j�󵥩�w�g���J���ƭ�
            if (data_valu[i] >= data_valu[data_seq[j-1]]){
                i++; //���L
            }
            if (data_temp <= data_valu[i]){
                data_temp=data_valu[i];
                data_seq[j]=i;
            }
            // cout << "data_temp=" << data_valu[i] << endl;
            // cout << "data_temp[data_seq[0]]=" << data_valu[data_seq[0]] << endl;
            // cout << data_valu[data_seq[0]] << endl;
        }
        // cout << data_valu[data_seq[j]] << endl;
        // cout << data_valu[data_seq[1]] << endl;
        // cout << data_seq[j] << endl;
        cout << "----" << endl;
    }
    // cout << data_seq[line_len-1] << endl;



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