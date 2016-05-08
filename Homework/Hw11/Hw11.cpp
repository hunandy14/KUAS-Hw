#include <iostream>
#include <fstream>
#include "StringSplit.cpp"
using namespace std;


int main(int argc, char const *argv[]){
    char filename[]="file.txt";
    fstream fp;
    char line[128];
    fp.open(filename, ios::in);//開啟檔案
    if(!fp)//如果開啟檔案失敗，fp為0；成功，fp為非0
        cout<<"Fail to open file: "<<filename<<endl;

    /* 讀取檔案 */
    string file_str;//讀近來的檔案
    int line_len=0;// 檔案總共有幾行
    while(fp.getline(line, sizeof(line), '\n')){
        file_str+=line;
        file_str+="\n";
        line_len++;
    }

    /* 將讀取的資料依行數存進陣列 */
    int str_index=0;// 讀取到第幾字元了
    string *data_arr = new string[line_len];
    for (int i=0; i<line_len; ++i, str_index++){
        while ( file_str[str_index]!='\n' && str_index < 999)
            data_arr[i] += file_str[str_index++];
    }

    /* 切割數據將逗號切出 */
    // cout << data_arr[0].c_str() << endl;
    string *strarr=str_split(data_arr[1].c_str());
    strarr_print(strarr);

    fp.close();//關閉檔案
    delete [] data_arr;
    return EXIT_SUCCESS;
}