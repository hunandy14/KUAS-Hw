/**********************************************************
Name : OpenRAW_getmask �����d��
Date : 2016/10/04
By   : CharlotteHonG
Final: 2016/10/05
**********************************************************/
#include <iostream>
#include "OpenRAW"
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
    // �]�w�B�n
    img.setMaskSize(ImrSize(4,4));
    // ���oMask�}�C�α��� getMask(���I��m)
    ImrMask mask = img.getMask(ImrCoor(1,1));
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