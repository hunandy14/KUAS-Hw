/**********************************************************
Name : Hw11_main
Date : 2016/05/15
By   : CharlotteHonG
Final: 2016/05/15
**********************************************************/
#include "function\String_app.cpp"
#include "function\file_access.cpp"
#include "function\data_seq.cpp"
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
=================================\n");

string init_message("\
1.如果沒有會自動建立\n\
2.輸入*預設檔名為file.txt\n\
3.會自動補副檔名.txt\n\
#請輸入檔名：");

/*====================================================*/
/* 寫入開頭 */
void file_whead(const char* filename);
/* 清空檔案 */
void file_empty(const char* filename);
/* 寫入檔案 */
void file_write(const char* filename,const char* str);
/* 取得檔案行數 */
int file_linelen(const char* filename);
/* 讀取檔案回傳字串 */
string file_readstr(const char* filename);
/* 開啟檔案 */
int file_open(const char* filename);



/* 二維陣列字串轉單一字串 */
string string_2one(string** data, int line_len);
/* 依序將行存入string陣列 */
string* file_data(string file_str, int line_len);
/* 切割字串 */
string* str_split(const char* str, const char* sp);
string* str_split(const char* str);
/* 列印字串 */
void strarr_print(string* strarr, int len);
void strarr_print(string* strarr);
/* 4個字串結合為一個 */
string file_instr();
/******************************************
將切割好行數的string再切割存入二維string
注意不含開頭的標頭行
******************************************/
string** file_datad(string* data_arr, int line_len);
/* 陣列字串左移(開頭[0]要是陣列長度) */
void string_left(string* str);



/* 排序 */
void sort(int arr[], int len);
/* 排序字串 */
int s2i(string str);
void sort_str(string** data, int line_len);
/* 取出行 */
int* row(string* data_arr, int line_len);
/*====================================================*/