/**********************************************************
Name : OpenRAW_histogram �����d��
Date : 2016/10/04
By   : CharlotteHonG
Final: 2016/10/13
**********************************************************/
#include <iostream>
#include "OpenRAW_fun\OpenRAW"
// Visual Studio �sĶ�ݧR���Ӧ�P���ɮ�
#include "OpenRAW.cpp" // GCC���ɽsĶ��
using namespace std;
using namespace imr;

#define AutoOpen 1
#define Pic_name_in "IMG.raw"
#define Pic_name_out "IMG_OUT.raw"
#define Pic_x 256
#define Pic_y 256

int main(int argc, char const *argv[]) {
    // �Ыصe��
    imgraw img(ImrSize(Pic_y, Pic_x));
    // Ū���ɮ�
    img.read(Pic_name_in);
    //---------------------------------------------------------
    // �L�X�����
    img.pri_htg("Original");
    //---------------------------------------------------------
    // ���ܰT��
    img.info();
    //---------------------------------------------------------
    // ��X�ɮ�
    img.write(Pic_name_out);
    // �}���ɮ�
    if(AutoOpen==1)
        system(Pic_name_out);
    return 0;
}