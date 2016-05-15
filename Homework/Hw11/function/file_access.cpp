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
string head="[姓名],[年齡],[身高],[收入]";
/*====================================================*/
/* 寫入開頭 */
void file_whead(const char* filename){
    fstream fp;
    fp.open(filename, ios::out);//開啟檔案
    fp << head;//寫入字串
    fp.close();//關閉檔案
}

/* 清空檔案 */
void file_empty(const char* filename){
    fstream fp;
    fp.open(filename, ios::out);//開啟檔案
    fp << "";//寫入字串
    fp.close();//關閉檔案
}

/* 寫入檔案 */
void file_write(const char* filename,const char* str){
    fstream fp;
    fp.open(filename, ios::out|ios::app);//開啟檔案
    fp << str;//寫入字串
    fp.close();//關閉檔案
}

/* 取得檔案行數 */
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

/* 讀取檔案回傳字串 */
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

/* 開啟檔案 */
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
/*=====棄用==棄用==棄用==棄用==棄用==棄用==棄用==棄用=====*/
/*依順序寫入*/
void write_seq(string filename, string* data_arr, int *data_seq){
    int line_len = data_seq[0];
    // cout << data_arr[0] << endl;
    fstream fp;
    fp.open("seq.txt", ios::out);//開啟檔案
    fp << head << endl;//寫入字串
    // cout << data_seq[0] << endl;
    // cout << data_arr[data_seq[0]] << endl;
    for (int i = 0; i < line_len; ++i){
        // fp << data_arr[data_seq[i]] << endl;
        // cout << data_arr[data_seq[i]] << endl;
        // cout << data_seq[i] << endl;
    }
    // fp << data_arr[data_seq[line_len-1]];
    // cout << data_arr[data_seq[line_len-1]] << endl;
    fp.close();//關閉檔案
}
/*====================================================*/

