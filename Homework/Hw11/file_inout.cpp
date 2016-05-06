#include <iostream>
#include <fstream>
#include <stdio.h>
using namespace std;
/*====================================================*/
int file_open(const char* filename);
string file_readstr(const char* filename);
string* file_data(string file_str,int line_len);
void file_write(const char* filename,const char* str);
/*====================================================*/
string file_instr(){
    string indata[5];
    cin >> indata[1] >> indata[2] >> indata[3] >> indata[4];
    indata[0] += indata[1]+","+indata[2]+ \
                    ","+indata[3]+","+indata[4];
    // cout << indata[0] << endl;
    return indata[0];
}

void file_write(const char* filename,const char* str){
    fstream fp;
    fp.open(filename, ios::out|ios::app);//�}���ɮ�
    fp << str << endl;//�g�J�r��
    fp.close();//�����ɮ�
}

string* file_data(string file_str,int line_len){
    string *data_arr = new string[line_len];
    int str_index=0;// Ū����ĴX�r���F
    for (int i=0; i<line_len; ++i, str_index++){
        while ( file_str[str_index]!='\n' && str_index < 999)
            data_arr[i] += file_str[str_index++];
    }
    return data_arr;
}


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
int file_open(const char* filename){
    fstream fp;
    fp.open(filename, ios::in);//�}���ɮ�
    if(!fp){//�p�G�}���ɮץ��ѡAfp��0�F���\�Afp���D0
        cout<<"No file."<<endl;
        cout<<"Creat new file."<<endl;
        fp.open(filename, ios::out);//�}���ɮ�
        fp << "[�m�W],[�~��],[����],[���J]\n" << endl;//�g�J�r��
    }
    fp.close();//�����ɮ�
    return 1;
}
/*====================================================*/

