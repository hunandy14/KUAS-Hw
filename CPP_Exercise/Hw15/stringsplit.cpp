/**********************************************************
Name:String Split
DATE:2016/04/01
By CharlotteHong
**********************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;
/* ================================================== */
/* 切割字串 (要切割的字串,切割的符號)
字串的格式如 srt[]="1,2";
回傳值為陣列指標地址，陣列[0]是長度 */
string* str_split(const char* str, const char* sp);
string* str_split(const char* str);
// 列印字串列別[跳過0] (列印的字串類別地址,印幾個)
void strarr_print(string* strarr, int len);
// 預設字串類別為全印 (列印的字串類別地址)
void strarr_print(string* strarr);
// 回傳陣列長度(字串類別地址)
int strarr_len(string* strarr);
/* ================================================== */
// int main(int argc, char const *argv[]){
//     char str[]="18 15 65";
//     // 切割
//     string *strarr = str_split(str, " ");
//     // 取得長度
//     int len = strarr_len(strarr);
//     // 列印
//     strarr_print(strarr,len);

//     delete [] strarr;
//     return 0;
// }
/* ================================================== */
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

void strarr_print(string* strarr, int len){
    for (int i = 1; i <= len-1; ++i){
        cout << strarr[i] << ",";
    }cout << strarr[len];
    cout << endl;
}

void strarr_print(string* strarr){
    strarr_print(strarr, atoi(strarr[0].c_str()));
}

int strarr_len(string* strarr){
    int len = atoi(strarr[0].c_str());
    return len;
}
/* ================================================== */