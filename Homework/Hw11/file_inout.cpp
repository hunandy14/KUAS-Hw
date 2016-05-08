#include <iostream>
#include <fstream>
#include <stdio.h>
using namespace std;
/*====================================================*/
string head="[姓名],[年齡],[身高],[收入]";
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
    fp << endl << str;//寫入字串
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
        fp.close();//關閉檔案
        cout<<"No file."<<endl;
        cout<<"Creat new file."<<endl;
        fp.open(filename, ios::out);//開啟檔案
        fp << head << endl;//寫入字串
    }
    fp.close();//關閉檔案
    return 1;
}

void write_seq(string filename, string* data_arr, int *data_seq){
    int line_len = data_seq[0];
    // cout << data_arr[0] << endl;
    fstream fp;
    fp.open(filename, ios::out);//開啟檔案
    fp << head << endl;//寫入字串
    // cout << data_seq[0] << endl;
    for (int i = 1; i < line_len-1; ++i){
        fp << data_arr[data_seq[i]] << endl;
        // cout << data_arr[data_seq[i]] << endl;
        // cout << data_seq[i] << endl;
    }
    fp << data_arr[data_seq[line_len-1]];
    // cout << data_arr[data_seq[line_len-1]] << endl;
    fp.close();//關閉檔案
}
/*====================================================*/

