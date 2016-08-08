/**********************************************************
Name : ZeroOrder.cpp
Date : 2016/08/03
By   : CharlotteHonG
Final: 2016/08/03

�w���p���I�ɪk�S������
black��k�S��k����
**********************************************************/
#include <iostream>
#include <fstream>
#include <vector>
#include "OpenRAW"
using namespace std;

#define AutoOpen 0
#define Pic_name_in "IMG.raw"
#define Pic_name_out "IMG_OUT.raw"
#define Pic_x 256
#define Pic_y 256
#define Ratio 0.25

int main(int argc, char const *argv[]) {
    if(Ratio < 0) {
        cout << "Ratio more than the zero." << endl;
        return 0;
    }
    imgraw img(Pic_y, Pic_x);
    imgraw img2(Pic_y*Ratio, Pic_x*Ratio);
    img.read(Pic_name_in);
    //=========================================
    int apend_p=0; // �ݭn�ɪ��I
    int white=0; //�X�ӭ��I (��) �ɤ@�ӷs�I (��)
    int black=0; //�B�z��j���v�p���I�A�C�X�ӭ��I�h�ɤ@�ӷs�I
    int limx=0,limy=0, limx_c=0,limy_c=0;
    int debug=0;

    apend_p = Pic_x*(Ratio-1);
    if(Ratio>1) {
        white = ((int)Ratio)-1;
        if(((float)Ratio-(int)Ratio) > 0) {
            black = 1/((float)Ratio-(int)Ratio);
            cout << "**" << (int)Ratio <<endl;
            limx = Pic_x * ((float)Ratio-(int)Ratio);
            limy = Pic_y * ((float)Ratio-(int)Ratio);
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
                } xp+=white; //��J�I�첾����
                // ���I 2 (�p���I���v) �C�g�X���I�ɤ@�I�s�I
                if(black!=0 && (i+1)%black==0) { // �q0�}�l�G�h+1
                    // debug++;
                    if(limx_c<limx) {
                        limx_c+=1;
                        img2.point_write(j+yp, (i+xp)+1, img.point_read(j, i));
                        xp+=1;
                    }
                }
            }

            // �ɱ� (���)
            for(int i = 0; i < white; ++i) {
                for(int k=0; k < Pic_x*Ratio; ++k)
                    img2.point_write(j+yp+1+i, k, img2.point_read(j+yp, k));
                // debug+=1;
            } yp+=white; //��J�Ʀ첾����
            // �ɱ� 2 (�p���I���v)
            if(black!=0 && (j+1)%black==0) { // �q0�}�l�G�h+1
                if(limy_c<limy) {
                    if(white==0) { // ���v����1~2��
                        if(limy_c<limy) {
                            limy_c+=1;
                            for(int k=0; k < Pic_x*Ratio; ++k)
                                img2.point_write(j+yp+1, k, img2.point_read(j+yp, k));
                        }
                    }
                    else {
                        for(int i = 0; i < white; ++i) {
                            if(limy_c<limy) {
                                limy_c+=1;
                                for(int k=0; k < Pic_x*Ratio; ++k)
                                    img2.point_write(j+yp+1+i, k, img2.point_read(j+yp, k));
                            }
                            // debug+=1;
                        }
                    }
                    yp+=1; //��J�Ʀ첾����
                }
            }
        }
    } else { // �Y�p
        int jmp=3; // �CŪ�X�I���L
        // jmp = (1 / (1-(float)Ratio)) * (1-(float)Ratio);
        cout << "jmp=" << jmp << endl;

        for(int j = 0, yp = 0; j < (int)(Pic_y*Ratio); ++j){
            // �C
            for(int i = 0,xp = 0; i < (int)(Pic_x*Ratio); ++i){
                if ((i+1)%jmp==0){// �C�j jmp �I�N���L
                    ++xp;
                    debug++;
                }
                img2.point_write(j, i, img.point_read(j+yp, i+xp));
            }img2.point_write(j, (int)(Pic_x*Ratio), img.point_read(j+yp, Pic_x));

            // ��
            if ((j+1)%jmp==0){
                ++yp;
            }
        }
        // �ɳ̫�@��
        // for(int i = 0,xp = 0; i < (int)(Pic_x*Ratio); ++i){
        //     if ((i+1)%jmp==0){// �C�j jmp �I�N���L
        //         ++xp;
        //         debug++;
        //     }
        //     img2.point_write((int)(Pic_x*Ratio)-1, i, img.point_read(Pic_x-1, i+xp));
        // }
        // img2.point_write((int)(Pic_x*Ratio)-1, (int)(Pic_x*Ratio)-1,
        //     img.point_read(Pic_y-1, Pic_x-1));
    }

    cout << "pix = " << (int)(Pic_x*Ratio) << endl;
    cout << "apend_p = "   << apend_p   << endl;
    cout << "Pic_x = "   << Pic_x   << endl;
    cout << "white = "   << white   << endl;
    cout << "black = "   << black   << endl;
    cout << "limx = "   << limx   << endl;
    cout << "limy = "   << limy   << endl;
    cout << "limx_c = "   << limx_c   << endl;
    cout << "limy_c = "   << limy_c   << endl;
    cout << "debug = "   << debug/(int)(Pic_y*Ratio)   << endl;
    cout << "t = "   << ((float)Ratio-(int)Ratio)   << endl;
    //=========================================



    img2.write(Pic_name_out);
    // if (AutoOpen==1)
        system(Pic_name_out);
    return 0;
}