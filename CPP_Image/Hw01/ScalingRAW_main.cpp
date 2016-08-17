/**********************************************************
Name : ScalingRAW.cpp
Date : 2016/08/03
By   : CharlotteHonG
Final: 2016/08/12
**********************************************************/
#include <iostream>
#include "ScalingRAW"
using namespace std;

#define AutoOpen 1
#define Pic_name_in "IMG.raw"
#define Pic_name_out "IMG_OUT.raw"
#define Pic_x 256
#define Pic_y 256
#define Ratio 2

int main(int argc, char const *argv[]) {
    // �Ыصe��
    imgraw img(Pic_y, Pic_x);
    // Ū���ɮ�
    img.read(Pic_name_in);
    // ���j�p
    // img.resize_zero(Ratio);
    // img.resize_first(Ratio);
    img.resize_bicubic(Ratio);
    // ��X�ɮ�
    img.write(Pic_name_out);
    // ���ܰT��
    cout << "�e���e�� = " << img.w() << endl;
    // �}���ɮ�
    if(AutoOpen==1)
        system(Pic_name_out);
    return 0;
}