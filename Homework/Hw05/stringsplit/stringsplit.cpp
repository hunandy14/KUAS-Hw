/**********************************************************
Name:String Split
DATE:2016/04/01
By CharlotteHong
**********************************************************/
#include <stdio.h>
#include <iostream>
using namespace std;
/* ================================================== */
/* 切割字串 (要切割的字串,切割的符號)
字串的格式如 srt[]="1,2";
回傳值為陣列指標地址，陣列[0]是長度 */
int* str_split(const char* str, const char* sp);
/* ================================================== */
int main(int argc, char const *argv[]){
    char str[]="18,15,65,87,15,65,45,1,3,6,-4";
    int *array=str_split(str,",");

    for (int i = 1; i <= array[0]; ++i){
        printf("[%d]", array[i]);
    }printf("\n");

    delete [] array;
    return 0;
}
/* ================================================== */
int* str_split(const char* str, const char* sp){
    // 計算字串長度
    int slen=0;
    while (str[slen]!=0 && slen<=999)
        slen++;
    // 計算字串內總共有幾個數
    int ilen=1;
    for (int i = 0; i < slen; ++i)
        if ( str[i] == sp[0]) 
            ilen++;
    // 根據長度配置記憶體
    int *ptr = new int[ilen+1];
    *ptr = (int)(ilen);
    // 開始切割
    int tempflag=0,index=1;
    char *temp = new char[1];
    for (int i = 0; i <= slen; ++i){
        if (str[i] == sp[0] || i==slen){
            ilen++;
            tempflag=0;
            // printf("temp=%c%c\n",temp[0],temp[1] );
            sscanf(temp, "%d", (ptr+index));
            index++;
            delete [] temp;
            temp = new char[1];
        }
        else {temp[tempflag++]=str[i];}
    } delete [] temp;
    return ptr;
}
/* ================================================== */