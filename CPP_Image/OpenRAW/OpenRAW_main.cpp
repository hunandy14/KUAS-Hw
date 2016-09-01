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
    ImrSize masksize(2,2);
    img.setMaskSize(masksize);

    // std::vector<char> v(3);
    ImrMask mask(ImrSize(3,3));
    for (int j = 0; j < 9; ++j)
    {   
        mask[j]=j;
    }
    // cout << (int)mask[1] << endl;
    mask.at2d(0,0)=5;
    cout << "mask[=" << (int)mask[0] << endl;

    // mask
    // cout << endl<< "mask" << endl;
    // for(int j = 0; j < 3; ++j){
    //     for(int i = 0; i < 3; ++i) {
    //         ImrCoor ori(256,256);
    //         ImrCoor tar(j,i);
    //         cout << img.mask(ori,tar);
    //     }cout << endl;
    // }
    // ����
    // cout << endl<< "Original" << endl;
    // for(int j = 250; j < 256; ++j){
    //     for(int i = 250; i < 256; ++i) {
    //         cout << img.point_read(j, i);
    //     }cout << endl;
    // }
    // ���I�ާ@
    for(int j = 0; j < Pic_y; ++j){
        for(int i = 0; i < Pic_x; ++i) {
            img2.point_write(j, i, img.point_read(j, i));
        }
    }
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