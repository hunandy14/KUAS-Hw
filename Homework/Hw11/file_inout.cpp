#include <iostream>
#include <fstream>
#include <stdio.h>
using namespace std;
/*====================================================*/
int file_open(const char* filename);
string file_readstr(const char* filename);
string* file_data(string file_str,int line_len);
void file_write(const char* filename,const char* str);
string file_instr();
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
    fp.open(filename, ios::out|ios::app);//開啟檔案
    fp << str << endl;//寫入字串
    fp.close();//關閉檔案
}

string* file_data(string file_str,int line_len){
    string *data_arr = new string[line_len];
    int str_index=0;// 讀取到第幾字元了
    for (int i=0; i<line_len; ++i, str_index++){
        while ( file_str[str_index]!='\n' && str_index < 999)
            data_arr[i] += file_str[str_index++];
    }
    return data_arr;
}


int file_linelen(const char* filename){
    char line[128];
    fstream fp;
    fp.open(filename, ios::in);//開啟檔案
    string file_str;//讀近來的檔案
    int line_len=0;// 檔案總共有幾行
    while(fp.getline(line, sizeof(line), '\n')){
        file_str+=line;
        file_str+="\n";
        line_len++;
    }
    fp.close();//關閉檔案
    return line_len;
}

string file_readstr(const char* filename){
    char line[128];
    fstream fp;
    fp.open(filename, ios::in);//開啟檔案
    string file_str;//讀近來的檔案
    int line_len=0;// 檔案總共有幾行
    while(fp.getline(line, sizeof(line), '\n')){
        file_str+=line;
        file_str+="\n";
        line_len++;
    }
    fp.close();//關閉檔案
    return file_str;
}
int file_open(const char* filename){
    fstream fp;
    fp.open(filename, ios::in);//開啟檔案
    if(!fp){//如果開啟檔案失敗，fp為0；成功，fp為非0
        cout<<"No file."<<endl;
        cout<<"Creat new file."<<endl;
        fp.open(filename, ios::out);//開啟檔案
        fp << "[姓名],[年齡],[身高],[收入]\n" << endl;//寫入字串
    }
    fp.close();//關閉檔案
    return 1;
}
/*====================================================*/

