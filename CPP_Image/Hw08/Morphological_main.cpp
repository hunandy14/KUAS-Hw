/**********************************************************
Name : OpenRAW_main
Date : 2016/08/03
By   : CharlotteHonG
Final: 2016/10/05
**********************************************************/

#include <iostream>
#include "Morphological"
using namespace std;
using namespace imr;

#define AutoOpen 1
#define Pic_name_in "MorphologicalOperations_500x500.raw"
#define Pic_name_out "IMG_OUT.raw"
#define Pic_x 500
#define Pic_y 500

int main(int argc, char const *argv[]) {
    // �Ыصe��
    imgraw img(ImrSize(Pic_y, Pic_x));
    // Ū���ɮ�
    img.read(Pic_name_in);
    //---------------------------------------------------------
    int ch=0;
    // �d�ݮĪG
    if(ch==0){
        // �G��
        img.binarizae();
        // ����
        img.dilation();
        img.dilation();
        // �I�k
        img.erosion();
        img.erosion();
    }
    // ���ҥ\��
    if(ch==1){
        // �G��(�ɽu, ��R��, ����)
        img.binarizae(128, 32, 0);
        // ����(��R��, �ؼмv���ƭ�)
        img.dilation(255, 32);
        // �I�k(��R��, �ؼмv���ƭ�)
        img.erosion(128, 255);
    }
    //---------------------------------------------------------
    // ���ܰT��
    img.info();
    //---------------------------------------------------------
    // ��X�ɮ�
    img.write(Pic_name_out);
    // �}���ɮ�
    if(AutoOpen==1){
        string temp = "start \"\" ";
        temp += Pic_name_out;
        system(temp.c_str());
    }
    return 0;
}