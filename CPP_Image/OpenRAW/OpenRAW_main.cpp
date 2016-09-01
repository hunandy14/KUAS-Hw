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
    // �]�w�B�n
    img.setMaskSize(ImrSize(4,4));
    //---------------------------------------------------------
    // ���oMask�}�C�α��� 
    ImrMask mask;
    // getMask(���I��m)
    mask = img.getMask(ImrCoor(1,1));
    // img.getMask(ImrCoor(1,1));
    for (int j = 0, c = 0; j < 3; ++j){
        for (int i = 0; i < 3; ++i){
            cout << mask[++c];
        }cout << endl;
    }
    // ��Ϥ��
    cout << endl<< "Original" << endl;
    for(int j = 0; j < 4; ++j){
        for(int i = 0; i < 4; ++i) {
            cout << img.point_read(j, i);
        }cout << endl;
    } 
    //---------------------------------------------------------
    // Ū��Mask�Ϊk(�W�L��ɷ|�����)
    // cout << endl<< "mask" << endl;
    // for(int j = 0; j < 3; ++j){
    //     for(int i = 0; i < 3; ++i) {
    //         ImrCoor ori(255,255);
    //         ImrCoor mas(j,i);
    //         // maskVal(���I�A�B�n�I)
    //         cout << img.maskVal(ori,mas);
    //     }cout << endl;
    // }
    // ��Ϥ��
    // cout << endl<< "Original" << endl;
    // for(int j = 250; j < 256; ++j){
    //     for(int i = 250; i < 256; ++i) {
    //         cout << img.point_read(j, i);
    //     }cout << endl;
    // }
    //---------------------------------------------------------
    // ���I�ާ@
    // for(int j = 0; j < Pic_y; ++j){
    //     for(int i = 0; i < Pic_x; ++i) {
    //         img2.point_write(j, i, img.point_read(j, i));
    //     }
    // }
    //---------------------------------------------------------
    // �L�X�����
    // img.pri_htg("Original");
    //---------------------------------------------------------
    // ���ܰT��
    cout << "�e���e�� = " << img2.w() << endl;
    //---------------------------------------------------------
    // ��X�ɮ�
    // img.write(Pic_name_out);
    // �}���ɮ�
    if(AutoOpen==1)
        system(Pic_name_out);
    return 0;
}