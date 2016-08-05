/**********************************************************
Name : ZeroOrder.cpp
Date : 2016/08/03
By   : CharlotteHonG
Final: 2016/08/03
**********************************************************/
#include <iostream>
#include <fstream>
#include <vector>
#include "OpenRAW"
using namespace std;

#define Pic_name_in "IMG.raw"
#define Pic_name_out "IMG_OUT.raw"
#define Pic_x 256
#define Pic_y 256
#define Ratio 5.9

int main(int argc, char const *argv[]) {
    int aa=0;
    imgraw img(Pic_y, Pic_x);
    imgraw img2(Pic_y*Ratio+aa, Pic_x*Ratio);
    img.read(Pic_name_in);

    //=========================================
    int apend_p = Pic_x*(Ratio-1); // �ݭn�ɪ��I
    int black, white; //�X�ӭ��I (��) �ɤ@�ӷs�I (��)
    int black2=0; //�B�z��j���v�p���I�A�C�X�ӭ��I�h�ɤ@�ӷs�I
    int limx=0,limy=0;
    int limx_c=0,limy_c=0;
    int debug=0;
    if(apend_p >= Pic_x) { //���I�h
        black = 1;
        white = ((int)Ratio)-1;
        if (((float)Ratio-(int)Ratio) >= 0){
            black2 = 1/((float)Ratio-(int)Ratio);
            limx=Pic_x*((float)Ratio-(int)Ratio);
            limy=Pic_y*((float)Ratio-(int)Ratio);
        }
        // ���I�ާ@
        for(int j=0, yp=0; j < Pic_y; ++j) {

            limx_c=0;
            for(int i=0, xp=0; i < Pic_x; ++i) {
                // ��J��Ϫ��I
                img2.point_write(j+yp, i+xp, img.point_read(j, i));
                
                // ���I (���) �C�g�@���I�ɦh�ַs�I
                for(int k = 0; k < white; ++k) {
                    // k=���I�첾���СA���O��J�I�첾����
                    img2.point_write(j+yp, (i+xp)+k+1, img.point_read(j, i));
                }xp+=white; //��J�I�첾����

                // ���I 2 (�p���I���v) �C�g�X���I�ɤ@�I�s�I
                if ((i+1)%black2==0 && black2!=0){
                    if (limx_c<limx){
                        limx_c+=1;
                        img2.point_write(j+yp, (i+xp)+1, img.point_read(j, i));
                        xp+=1;
                    }
                }
            }

            // �ɱ� (���)
            for (int i = 0; i < white; ++i){
                for(int k=0; k < Pic_x*Ratio; ++k) 
                    img2.point_write(j+yp+1+i, k, img2.point_read(j+yp, k));
                // debug+=1;
            }yp+=white; //��J�Ʀ첾����

            // �ɱ� 2 (�p���I���v)
            if ((j+1)%black2==0 && black2!=0){
                if (limy_c<limy){
                    for (int i = 0; i < white; ++i){
                        if (limy_c<limy){
                            limy_c+=1;
                            for(int k=0; k < Pic_x*Ratio; ++k)
                                img2.point_write(j+yp+1+i, k, img2.point_read(j+yp, k));
                            debug+=1;
                        }
                    }
                    yp+=1; //��J�Ʀ첾����
                }
            }
        }

    }
    else { //���I��
        black = Pic_x/apend_p;
        white = 1;
    }
    cout << "pix = " << apend_p+Pic_x << endl;
    cout << "apend_p = "   << apend_p   << endl;
    cout << "Pic_x = "   << Pic_x   << endl;
    cout << "black = "   << black   << endl;
    cout << "white = "   << white   << endl;
    cout << "black2 = "   << black2   << endl;
    cout << "limx = "   << limx   << endl;
    cout << "limy = "   << limy   << endl;
    cout << "limx_c = "   << limx_c   << endl;
    cout << "limy_c = "   << limy_c   << endl;
    cout << "debug = "   << debug   << endl;
    cout << "t = "   << ((float)Ratio-(int)Ratio)   << endl;
    //=========================================

    

    img2.write(Pic_name_out);
    system(Pic_name_out);
    return 0;
}