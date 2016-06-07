/**********************************************************
Name:KUAS-Hw/Hw05
DATE:2016/03/29
Final:2016/04/01
By CharlotteHong
**********************************************************/
//=========================================================
#include <iostream>
#include <stdio.h>
#include "Hw05.cpp"
using namespace std;
//=========================================================
int main(int argc, char const *argv[]){
    /* 開頭節點 */
    node *nh=node_creat(-1);
    /* 批次匯入節點 */
    // int data[]={18,15,65,0,1,15,6,-4};
    // int len = sizeof(data)/sizeof(data[0]);
    // nodep_input(nh,data,len);
    char str[]="18,15,65,0,1,15,6,-4";
    char const *ptr=str;
    // 由外層輸入
    if (argc > 1)
    	ptr=argv[1];
    int *str_data=str_split(ptr,",")+1;
    int len = *(str_data-1);
    nodep_input(nh,str_data,len);

    /* 排序節點 */
    node_printalldata(nh);
    // node_printall(nh);
    node_short(nh);
    /* 印出節點 */
    cout << "=====================================" <<endl;
    node_printalldata(nh);
    // node_printall(nh);

    /* 釋放記憶體 */
    node_deleteall(nh);
    delete [] nh;
    delete [] (str_data-1);
    return 0;
}