/**********************************************************
Name : OpenRAW.cpp
Date : 2016/08/03
By   : CharlotteHonG
Final: 2016/09/08
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
    //---------------------------------------------------------
    // �]�w�B�n
    img.setMaskSize(ImrSize(4,4));
    // ���oMask�}�C�α��� getMask(���I��m)
    ImrMask mask;
    mask = img.getMask(ImrCoor(1,1));
    cout << endl<< "setMaskSize" << endl;
    for (int j = 0, c = 0; j <4; ++j){
        for (int i = 0; i <4; ++i, c++){
            cout << (int)mask[c] << " ";
            // cout << mask.at2d(j,i);
        }cout << endl;
    }
    // ��Ϥ��
    cout << endl<< "Original" << endl;
    for(int j = 0; j < 4; ++j){
        for(int i = 0; i < 4; ++i) {
            cout << (int)img.at2d(j, i) << " ";
        }cout << endl;
    } 
    // �Ƨ�
    mask.sort();
    cout << endl<< "sort" << endl;
    for (int j = 0, c = 0; j < 4; ++j){
        for (int i = 0; i < 4; ++i, c++){
            cout << (int)mask[c] << " ";
            // cout << mask.at2d(j,i);
        }cout << endl;
    }
    //---------------------------------------------------------
    // Ū��Mask�Ϊk(�W�L��ɷ|�����)
    cout << endl<< "maskVal" << endl;
    for(int j = 0; j < 3; ++j){
        for(int i = 0; i < 3; ++i) {
            ImrCoor ori(0,0);
            ImrCoor mas(j,i);
            // maskVal(���I�A�B�n�I)
            cout << img.maskVal(ori,mas);
        }cout << endl;
    }
    // ��Ϥ��
    cout << endl<< "Original" << endl;
    for(int j = 250; j < 256; ++j){
        for(int i = 250; i < 256; ++i) {
            cout << img.at2d(j,i);
        }cout << endl;
    }
    //---------------------------------------------------------
    // ���I�ާ@
    for(int j = 0; j < Pic_y; ++j){
        for(int i = 0; i < Pic_x; ++i) {
            // �T�ا@�k(�O�d�ª�����k)
            // img2.point_write(j, i, img.point_read(j, i));
            // img2[j*(Pic_x)+i]=img[j*(Pic_x)+i];
            img2.at2d(j,i)=img.at2d(j,i);
        }
    }
    //---------------------------------------------------------
    // �L�X�����
    img2.pri_htg("Original");
    //---------------------------------------------------------
    // ���ܰT��
    cout << "�e���e�� = " << img2.w() << endl;
    //---------------------------------------------------------
    // ��X�ɮ�
    img2.write(Pic_name_out);
    // �}���ɮ�
    if(AutoOpen==1)
        system(Pic_name_out);
    return 0;
}