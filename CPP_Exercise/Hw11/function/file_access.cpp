/**********************************************************
Name : file_access
Date : 2016/05/15
By   : CharlotteHonG
Final: 2016/05/15
**********************************************************/
#include <iostream>
#include <fstream>
using namespace std;
/*====================================================*/
string head="[�m�W],[�~��],[����],[���J]";
/*====================================================*/
/* �g�J�}�Y */
void file_whead(const char* filename){
    fstream fp;
    fp.open(filename, ios::out);//�}���ɮ�
    fp << head;//�g�J�r��
    fp.close();//�����ɮ�
}

/* �M���ɮ� */
void file_empty(const char* filename){
    fstream fp;
    fp.open(filename, ios::out);//�}���ɮ�
    fp << "";//�g�J�r��
    fp.close();//�����ɮ�
}

/* �g�J�ɮ� */
void file_write(const char* filename,const char* str){
    fstream fp;
    fp.open(filename, ios::out|ios::app);//�}���ɮ�
    fp << str;//�g�J�r��
    fp.close();//�����ɮ�
}

/* ���o�ɮצ�� */
int file_linelen(const char* filename){
    char line[128];
    fstream fp;
    fp.open(filename, ios::in);//�}���ɮ�
    string file_str;//Ū��Ӫ��ɮ�
    int line_len=0;// �ɮ��`�@���X��
    while(fp.getline(line, sizeof(line), '\n')){
        file_str+=line;
        file_str+="\n";
        line_len++;
    }
    fp.close();//�����ɮ�
    return line_len;
}

/* Ū���ɮצ^�Ǧr�� */
string file_readstr(const char* filename){
    char line[128];
    fstream fp;
    fp.open(filename, ios::in);//�}���ɮ�
    string file_str;//Ū��Ӫ��ɮ�
    int line_len=0;// �ɮ��`�@���X��
    while(fp.getline(line, sizeof(line), '\n')){
        file_str+=line;
        file_str+="\n";
        line_len++;
    }
    fp.close();//�����ɮ�
    return file_str;
}

/* �}���ɮ� */
int file_open(const char* filename){
    fstream fp;
    fp.open(filename, ios::in);//�}���ɮ�
    if(!fp){//�p�G�}���ɮץ��ѡAfp��0�F���\�Afp���D0
        fp.close();//�����ɮ�
        cout<<"No file."<<endl;
        cout<<"Creat new file."<<endl;
        fp.open(filename, ios::out);//�}���ɮ�
        fp << head << endl;//�g�J�r��
    }
    fp.close();//�����ɮ�
    return 1;
}
/*=====���==���==���==���==���==���==���==���=====*/
/*�̶��Ǽg�J*/
void write_seq(string filename, string* data_arr, int *data_seq){
    int line_len = data_seq[0];
    // cout << data_arr[0] << endl;
    fstream fp;
    fp.open("seq.txt", ios::out);//�}���ɮ�
    fp << head << endl;//�g�J�r��
    // cout << data_seq[0] << endl;
    // cout << data_arr[data_seq[0]] << endl;
    for (int i = 0; i < line_len; ++i){
        // fp << data_arr[data_seq[i]] << endl;
        // cout << data_arr[data_seq[i]] << endl;
        // cout << data_seq[i] << endl;
    }
    // fp << data_arr[data_seq[line_len-1]];
    // cout << data_arr[data_seq[line_len-1]] << endl;
    fp.close();//�����ɮ�
}
/*====================================================*/

