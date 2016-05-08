#include <iostream>
using namespace std;

void sort(int arr[], int len) {
    int i, j;
    int temp;
    for (i = 1; i < len; i++) {
        temp = arr[i];
        for (j = i - 1; j >= 0 && arr[j] < temp; j--){
            arr[j + 1] = arr[j];
            arr[j] = temp;
        }
    }
}

int* seq(int *data_valu, int *data_valu_ori, int line_len){
    /* 找出順序 */
    int *data_seq = new int[line_len]; // 順序
    data_seq[0]=line_len;
    sort(data_valu, line_len);
    // cout << "順序";
    for (int j = 0; j < line_len-1; ++j){
        for (int i = 0; i < line_len-1; ++i){
            if(data_valu[j]==data_valu_ori[i]){
                data_seq[j+1]=i+1;
                break;
            }
        }
        // cout << data_seq[j] << ",";
    }
    return data_seq;
}

int* row(string* data_arr, int line_len){
    /* 取得行數值 */
    string *strarr;
    int Field=2; //讀取哪一行
    int* data_valu = new int[line_len]; // 讀取的行值
    int* data_valu_ori = new int[line_len]; // 讀取的行值
    for (int i = 1; i < line_len; ++i){
        strarr=str_split(data_arr[i].c_str());
        sscanf(strarr[Field].c_str(), "%d", &data_valu[i-1]);
        data_valu_ori[i-1] = data_valu[i-1];
        // istringstream is(strarr[Field]);
        // is>>data_valu[i];
        // cout << "   " << data_valu[i-1] << endl;
    }
    // strarr_print(strarr);
    return data_valu;
}