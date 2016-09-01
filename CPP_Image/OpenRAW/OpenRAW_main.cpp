/**********************************************************
Name : OpenRAW.cpp
Date : 2016/08/03
By   : CharlotteHonG
Final: 2016/08/12
**********************************************************/
#include <iostream>
#include "OpenRAW"
using namespace std;
using namespace imr;

#define AutoOpen 0
#define Pic_name_in "IMG.raw"
#define Pic_name_out "IMG_OUT.raw"
#define Pic_x 256
#define Pic_y 256

int main(int argc, char const *argv[]) {
    // �Ыصe��
    imgraw img(ImrSize(Pic_y, Pic_x));
    imgraw img2(ImrSize(Pic_y, Pic_x));
    // Ū���ɮ�
    img.read(Pic_name_in);
    // ���o�B�n
    ImrSize masksize(3,3);
    img.setMaskSize(masksize);
    ImrCoor ori(1,1);
    ImrCoor tar(0,0);
    img.mask(ori,tar);
    // img.mask();
    // imch** mask;
    // mask=img.getMask(1, 1, size_m);
    
    // mask
    // for(int j = 0; j < 3; ++j){
    //     for(int i = 0; i < 3; ++i) {
    //         cout << mask[j][i];
    //     }cout << endl;
    // }
    // ����
    // for(int j = 0; j < 3; ++j){
    //     for(int i = 0; i < 3; ++i) {
    //         cout << img.point_read(j, i);
    //     }cout << endl;
    // }
    // ���I�ާ@
    // for(int j = 0; j < Pic_y; ++j){
    //     for(int i = 0; i < Pic_x; ++i) {
    //         img2.point_write(j, i, img.point_read(j, i));
    //     }
    // }
    // ���ܰT��
    // cout << "�e���e�� = " << img2.w() << endl;
    // �L�X�����
    // img.pri_htg("Original");
    // ��X�ɮ�
    // img.write(Pic_name_out);
    // �}���ɮ�
    if(AutoOpen==1)
        system(Pic_name_out);
    return 0;
}