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

#define AutoOpen 1
#define Pic_name_in "IMG.raw"
#define Pic_name_out "IMG_OUT.raw"
#define Pic_x 256
#define Pic_y 256
/*=======================================================*/
int main(int argc, char const *argv[]){
    // �Ыصe��
    ImrSize size(Pic_y, Pic_x);
    imgraw img(size);
    // Ū���ɮ�
    img.read(Pic_name_in);
    img.pri_htg("Original");
    // ���Y
    img.shrink(ImrIntv(100,200));
    img.pri_htg("shrink");
    // �٭�
    // img.stretch(ImrIntv(1,237));
    // img.pri_htg();
    // ����
    img.equalization();
    img.pri_htg("equalization");
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