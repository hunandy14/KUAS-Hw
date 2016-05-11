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
/* ���Φr�� (�n���Ϊ��r��,���Ϊ��Ÿ�)
�r�ꪺ�榡�p srt[]="1,2";
�^�ǭȬ��}�C���Цa�}�A�}�C[0]�O���� */
string* str_split(const char* str, const char* sp);
string* str_split(const char* str);
// �C�L�r��C�O[���L0] (�C�L���r�����O�a�},�L�X��)
void strarr_print(string* strarr, int len);
// �w�]�r�����O�����L (�C�L���r�����O�a�})
void strarr_print(string* strarr);
// �^�ǰ}�C����(�r�����O�a�})
int strarr_len(string* strarr);
/* ================================================== */
// int main(int argc, char const *argv[]){
//     char str[]="18 15 65";
//     // ����
//     string *strarr = str_split(str, " ");
//     // ���o����
//     int len = strarr_len(strarr);
//     // �C�L
//     strarr_print(strarr,len);

//     delete [] strarr;
//     return 0;
// }
/* ================================================== */
string* str_split(const char* str, const char* sp){
    /* �p��r����� */
    int slen=0;
    while (str[slen]!=0 && slen<=999)
        slen++;

    /* �p��r�ꤺ�`�@���X�Ӽ� */
    int ilen=1;
    for (int i = 0; i < slen; ++i)
        if ( str[i] == sp[0])
            ilen++;

    /* �ھڪ��װt�m�O���� */
    string *ptr = new string[ilen+1];
    char s2i_temp[32];// ��@�Ӽƾڦ��
    sprintf(s2i_temp, "%d", ilen);
    ptr[0]+=s2i_temp;// [0]�O�}�C����

    /* �}�l���� */
    int index=1;
    string *temp = new string[1];
    for (int i = 0; i <= slen; ++i){
        // �J��r���ɱN�Ȧs���r��s�J�}�C
        if (str[i] == sp[0] || i==slen){
            ilen++;
            ptr[index++] += temp[0];
            // �M�Ŧr��
            delete [] temp;
            temp = new string[1];
        }
        // �@�Ӥ@�ӱ��y�s�J�Ȧs�r��
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