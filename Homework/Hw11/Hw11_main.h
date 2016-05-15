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
    1. �s�W���\n\
    2. �ƧǸ��\n\
    3. �d�ݸ��\n\
    Q. Exit\n\
=================================\n");

string init_message("\
1.�p�G�S���|�۰ʫإ�\n\
2.��J*�w�]�ɦW��file.txt\n\
3.�|�۰ʸɰ��ɦW.txt\n\
#�п�J�ɦW�G");

/*====================================================*/
/* �g�J�}�Y */
void file_whead(const char* filename);
/* �M���ɮ� */
void file_empty(const char* filename);
/* �g�J�ɮ� */
void file_write(const char* filename,const char* str);
/* ���o�ɮצ�� */
int file_linelen(const char* filename);
/* Ū���ɮצ^�Ǧr�� */
string file_readstr(const char* filename);
/* �}���ɮ� */
int file_open(const char* filename);



/* �G���}�C�r�����@�r�� */
string string_2one(string** data, int line_len);
/* �̧ǱN��s�Jstring�}�C */
string* file_data(string file_str, int line_len);
/* ���Φr�� */
string* str_split(const char* str, const char* sp);
string* str_split(const char* str);
/* �C�L�r�� */
void strarr_print(string* strarr, int len);
void strarr_print(string* strarr);
/* 4�Ӧr�굲�X���@�� */
string file_instr();
/******************************************
�N���Φn��ƪ�string�A���Φs�J�G��string
�`�N���t�}�Y�����Y��
******************************************/
string** file_datad(string* data_arr, int line_len);
/* �}�C�r�ꥪ��(�}�Y[0]�n�O�}�C����) */
void string_left(string* str);



/* �Ƨ� */
void sort(int arr[], int len);
/* �ƧǦr�� */
int s2i(string str);
void sort_str(string** data, int line_len);
/* ���X�� */
int* row(string* data_arr, int line_len);
/*====================================================*/