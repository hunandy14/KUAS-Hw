/**********************************************************
Name : OpenRAW.cpp
Date : 2016/08/03
By   : CharlotteHonG
Final: 2016/09/12
**********************************************************/

#include <iostream>
#include "Hough"
using namespace std;
using namespace imr;

#define AutoOpen 1
#define Pic_name_in "Hough_868X600.raw"
#define Pic_name_out "IMG_OUT.raw"
#define Pic_x 868
#define Pic_y 600

int main(int argc, char const *argv[]) {
    // Ū���ɮ�
    // imgraw img(ImrSize(512, 512));
    // img.read("LENA.RAW");
    imgraw img(ImrSize(Pic_y, Pic_x));
    img.read(Pic_name_in);
    //---------------------------------------------------------
    img.sobel(450);
    //---------------------------------------------------------
    // ���ܰT��
    cout << "�e���e�� = " << img.w() << " x " << img.h() << endl;
    // ��X�ɮ�
    img.write(Pic_name_out);
    // �}���ɮ�
    if(AutoOpen==1)
        system(Pic_name_out);
    return 0;
}