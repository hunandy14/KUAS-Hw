/**********************************************************
Name : data_seq
Date : 2016/05/15
By   : CharlotteHonG
Final: 2016/05/15
**********************************************************/
#include <iostream>
using namespace std;

/* �Ƨ� */
void sort(int arr[], int len){
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

/* �ƧǦr�� */
int s2i(string str){
    int i=0;
    sscanf(str.c_str(), "%d", &i);
    return i;
}
void sort_str(string** data, int line_len){
    int list=2;
    string *st;
    for (int i=1; i<line_len; i++) {
        st = data[i];
        for (int j = i-1; j >= 0 && \
            /**/s2i(data[j][list])<s2i(st[list]); j--){
            data[j+1] = data[j];
            data[j] = st;
        }
    }
}

/* ���X�� */
int* row(string* data_arr, int line_len){
    /* ���o��ƭ� */
    string *strarr;
    int Field=2; //Ū�����@��
    int* data_valu = new int[line_len]; // Ū�������
    data_valu[0] = line_len;
    // cout << "row_" << data_valu[0] << endl;
    for (int i = 1; i < line_len; ++i){
        strarr=str_split(data_arr[i].c_str());
        sscanf(strarr[Field].c_str(), "%d", &data_valu[i]);
        // cout << "row_" << data_valu[i] << endl;
    }
    // strarr_print(strarr);
    return data_valu;
}

/*=====���==���==���==���==���==���==���==���=====*/
/* �ܺا�k�i�঳���D�A�p�G�J��@�˪� */
int* seq(int *data_valu, int *data_valu_ori, int line_len){
    /* ��X���� */
    int *data_seq = new int[line_len]; // ����
    data_seq[0]=line_len;
    sort(data_valu, line_len);
    // cout << "����";
    for (int j = 0; j < line_len-1; ++j){
        for (int i = 0; i < line_len-1; ++i){
            if(data_valu[j]==data_valu_ori[i]){
                data_seq[j+1]=i+1;
                break;
            }
        }
        cout << data_seq[j] << ",";
    }
    return data_seq;
}