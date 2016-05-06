#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "StringSplit.cpp"
#include "file_inout.cpp"
using namespace std;

string MainMenu("\
\n\
=================================\n\
        MainMenu\n\
=================================\n\
    1. 新增資料\n\
    2. 排序資料\n\
    3. 查看資料\n\
    Q. Exit\n\
=================================\n\
");
void print_menu(){
    cout << MainMenu;
    cout << "Your choose : ";
}

int main(int argc, char const *argv[]){
    string filename="file.txt",Default="*";

    cout << "1.如果沒有會自動建立" << endl;
    cout << "2.輸入*預設檔名為file.txt" << endl;
    cout << "3.會自動補副檔名.txt" << endl;
    cout << "#請輸入檔名：" << endl;
    cin >> filename;
    if (filename=="*"){
        filename="file.txt";
    }
    else
        filename+=".txt";
    /* 開啟檔案(測試是否可開) */
    file_open(filename.c_str());



    /* 讀取檔案 */
    string file_str = file_readstr(filename.c_str());
    // cout << file_str << endl;

    /* 取得行數 */
    int line_len = file_linelen(filename.c_str());
    // cout << line_len << endl;

    /* 將讀取的資料依行數存進陣列 */
    string *data_arr = file_data(file_str,line_len);

    /* 切割多行數據,並取出欄位數值 */
    string *strarr;
    int Field=2; //讀取哪一行
    int *data_valu = new int[line_len]; // 讀取的行值
    for (int i = 1; i < line_len; ++i){
        strarr=str_split(data_arr[i].c_str());
        sscanf(strarr[Field].c_str(), "%d", &data_valu[i-1]);
        // istringstream is(strarr[Field]);
        // is>>data_valu[i];
        // cout << "   " << data_valu[i-1] << endl;
        // strarr_print(strarr);
    }

    /* 找出讀取行的大到小排序 */
    int data_temp, data_big=0, data_small=0;
    //找出最大值
    data_temp=data_valu[0];
    for (int i = 1; i < line_len-1; ++i){//第一行不是數據
        if (data_temp <= data_valu[i]){
            data_temp=data_valu[i];
            data_big=i;
        }
    }
    // cout << data_big << endl;
    //找出最小值
    data_temp=data_valu[0];
    for (int i = 1; i < line_len-1; ++i){//第一行不是數據
        if (data_temp >= data_valu[i]){
            data_temp=data_valu[i];
            data_small=i;
        }
    }
    // cout << data_small << endl;

    // 找出順序
    int *data_seq = new int[line_len]; // 讀取的行值排序
    data_temp = data_valu[data_small];
    // cout << data_temp << endl;
    data_seq[0]=data_big;
    for (int j = 1; j < 4; ++j){
        for (int i = 0; i < line_len-1; ++i){
            // cout << data_valu[i] << endl;
            cout << data_valu[data_seq[j-1]] << endl;
            // 檢測是否大於等於已經收入的數值
            if (data_valu[i] >= data_valu[data_seq[j-1]]){
                i++; //跳過
            }
            if (data_temp <= data_valu[i]){
                data_temp=data_valu[i];
                data_seq[j]=i;
            }
            // cout << "data_temp=" << data_valu[i] << endl;
            // cout << "data_temp[data_seq[0]]=" << data_valu[data_seq[0]] << endl;
            // cout << data_valu[data_seq[0]] << endl;
        }
        // cout << data_valu[data_seq[j]] << endl;
        // cout << data_valu[data_seq[1]] << endl;
        // cout << data_seq[j] << endl;
        cout << "----" << endl;
    }
    // cout << data_seq[line_len-1] << endl;



    /* 選單 */
    char choose=0;
    while(choose!=-1){
        print_menu();
        cin >> choose;
        if (choose == '1'){;
            system("cls");
            /* 輸入資料 */
            cout << "請輸入 [姓名],[年齡],[身高],[收入]" << endl;
            string indata=file_instr();
            cout << "輸入的資料 = " << indata << endl;
            file_write(filename.c_str(),indata.c_str());

        }
        else if (choose == '2'){
            system("cls");
        }
        else if (choose == '3'){
            system("cls");
            /* 讀取檔案 */
            string file_str = file_readstr(filename.c_str());
            cout << file_str << endl;
        }

        else if (choose == 'Q' || choose == 'q'){
            system("cls");
            choose=-1;
        }
    }


    /* 讀取檔案 */
    // string file_str = file_readstr(filename.c_str());
    // cout << file_str << endl;

    /* 取得行數 */
    // int line_len = file_linelen(filename.c_str());
    // cout << line_len << endl;

    /* 將讀取的資料依行數存進陣列 */
    // string *data_arr = file_data(file_str,line_len);

    /* 切割單行數據,以逗號為分割存進二維陣列 */
    // string *strarr=str_split(data_arr[1].c_str());

    // strarr_print(strarr);

    // delete [] data_arr;
    return EXIT_SUCCESS;
}