/**********************************************************
Name : Hw11_main
Date : 2016/05/15
By   : CharlotteHonG
Final: 2016/05/15
**********************************************************/
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Hw11_main.h"
using namespace std;

int main(int argc, char const *argv[]){
    /* 初始化訊息 */
    string filename="file.txt", Default="*";
    cout << init_message;
    cin >> filename;
    /* 輸入檔名 */
    if (filename == Default)
        filename="file.txt";
    else
        filename+=".txt";
    /* 開啟檔案(測試是否可開) */
    file_open(filename.c_str());


    /* 選單 */
    char choose=0;
    while(choose!=-1){
        cout << MainMenu << "Your choose : ";
        cin >> choose;

        if (choose == '1'){;
            system("cls");
            /* 輸入資料 */
            cout << "注意不要輸入多餘的0,如[05,01]" << endl;
            cout << "請輸入 [姓名],[年齡],[身高],[收入]" << endl;
            string indata = "\n" + file_instr();
            cout << "輸入的資料 = " << indata << endl;
            file_write(filename.c_str(),indata.c_str());
        }
        else if (choose == '2'){
            system("cls");
            /* 讀取檔案 */
            string file_str = file_readstr(filename.c_str());
            /* 取得行數 */
            int line_len = file_linelen(filename.c_str());
            /* 將讀取的資料依行數存進陣列 */
            string* data_arr = file_data(file_str, line_len);
            /* 將資料存入二維string */
            string** data_arrd = file_datad(data_arr, line_len);
            /* 排序資料 */
            sort_str(data_arrd, line_len-1);
            /* 二維陣列字串轉單一字串 */
            string str_seq;
            str_seq = string_2one(data_arrd, line_len);
            cout << "[" << str_seq << "]" << endl;
            /* 寫入檔案 */
            file_whead(filename.c_str());
            file_write(filename.c_str(), ("\n"+str_seq).c_str());
        }
        else if (choose == '3'){
            system("cls");
            /* 讀取檔案 */
            string file_str = file_readstr(filename.c_str());
            cout << file_str << endl;
        }

        else if (choose == 'Q' || choose == 'q'){
            choose=-1;
        }
    }
    return 0;
}