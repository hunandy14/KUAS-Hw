/**********************************************************
Name : String_app
Date : 2016/05/15
By   : CharlotteHonG
Final: 2016/05/15
**********************************************************/
#include <stdlib.h>
#include <string>
#include <iostream>
using namespace std;
/* ================================================== */
/* 二維陣列字串轉單一字串 */
string string_2one(string** data, int line_len){
    string str;
    int row=0;
    sscanf(data[0][0].c_str(), "%d", &row);
    // cout << data[1][2] << endl;
    // cout << row << endl;
    for (int j = 0; j < line_len-1; ++j){
        for (int i = 1; i < row; ++i){
            str += data[j][i] + ",";
        } str += data[j][row];
        if (j < line_len-1-1)
            str += "\n";
    }
    return str;
}

/* 依序將行存入string陣列 */
string* file_data(string file_str, int line_len){
    string *data_arr = new string[line_len];
    int str_index=0;// 讀取到第幾字元了
    for (int i=0; i<line_len; ++i, str_index++){
        while ( file_str[str_index]!='\n' && str_index < 999)
            data_arr[i] += file_str[str_index++];
    }
    return data_arr;
}

/* 切割字串 */
string* str_split(const char* str, const char* sp){
    /* 計算字串長度 */
    int slen=0;
    while (str[slen]!=0 && slen<=999)
        slen++;

    /* 計算字串內總共有幾個數 */
    int ilen=1;
    for (int i = 0; i < slen; ++i)
        if ( str[i] == sp[0])
            ilen++;

    /* 根據長度配置記憶體 */
    string *ptr = new string[ilen+1];
    char s2i_temp[32];// 單一個數據位數
    sprintf(s2i_temp, "%d", ilen);
    ptr[0]+=s2i_temp;// [0]是陣列長度


    /* 開始切割 */
    int index=1;
    string *temp = new string[1];
    for (int i = 0; i <= slen; ++i){
        // 遇到逗號時將暫存的字串存入陣列
        if (str[i] == sp[0] || i==slen){
            ilen++;
            ptr[index++] += temp[0];
            // 清空字串
            delete [] temp;
            temp = new string[1];
        }
        // 一個一個掃描存入暫存字串
        else {temp[0]+=str[i];}
    } delete [] temp;
    return ptr;
}
string* str_split(const char* str){
    return str_split(str,",");
}

/* 列印字串 */
void strarr_print(string* strarr, int len){
    for (int i = 1; i <= len-1; ++i){
        cout << strarr[i] << ",";
    }cout << strarr[len];
    cout << endl;
}
void strarr_print(string* strarr){
    strarr_print(strarr, atoi(strarr[0].c_str()));
}

/* 4個字串結合為一個 */
string file_instr(){
    string indata[5];
    cin >> indata[1] >> indata[2] >> indata[3] >> indata[4];
    indata[0] += indata[1]+","+indata[2]+ \
                    ","+indata[3]+","+indata[4];
    // cout << indata[0] << endl;
    return indata[0];
}

/******************************************
將切割好行數的string再切割存入二維string
注意不含開頭的標頭行
******************************************/
string** file_datad(string* data_arr, int line_len){
    /* 取得 row */
    string *head = str_split(data_arr[0].c_str());
    int row=0;
    sscanf(head[0].c_str(), "%d", &row);
    delete [] head;
    // cout << row << endl;

    /* 創建string二維陣列 */
    string** data_arrd=NULL;
    data_arrd = new string*[line_len];

    /* 開始切割(不含開頭) */
    for (int i = 0; i < line_len-1; ++i){
        data_arrd[i]=str_split(data_arr[i+1].c_str());
        // string_left(data_arrd[i]);
    }
    return data_arrd;
}
/* ================================================== */
/* 陣列字串左移(開頭[0]要是陣列長度) */
void string_left(string* str){
    int row=0;
    sscanf(str[0].c_str(), "%d", &row);
    string len=str[0];
    for (int i = 0; i < row; ++i){
        // cout << str[i]
        str[i]=str[i+1];
    }str[row]=len;
}
/* ================================================== */