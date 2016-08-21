/**********************************************************
Name : 
Date : 2016/08/19
By   : CharlotteHonG
Final: 2016/08/19
**********************************************************/
#include <iostream>
#include "Historgram"
using namespace std;
using namespace imr;

#define AutoOpen 0
#define Pic_name_in "IMG.raw"
#define Pic_name_out "IMG_OUT.raw"
#define Pic_x 256
#define Pic_y 256
/*=======================================================*/
int main(int argc, char const *argv[]){
    // �Ыصe��
    imgraw img(ImrSize(Pic_y, Pic_x));
    // Ū���ɮ�
    img.read(Pic_name_in);
    // ���Y
    img.shrink(ImrIntv(100,200));
    // img.stretch(ImrIntv(1,237));
    img.pri_htg();
    // ���ܰT��
    cout << "�e���e�� = " << img.w() << endl;
    // ��X�ɮ�
    img.write(Pic_name_out);
    // �}���ɮ�
    if(AutoOpen==1)
        system(Pic_name_out);
    return 0;
}
/*=======================================================*/