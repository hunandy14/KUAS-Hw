/**********************************************************
Name : ZeroOrder.cpp
Date : 2016/08/03
By   : CharlotteHonG
Final: 2016/08/03

已知小數點補法沒有平均
black算法沒辦法平均
**********************************************************/
#include <iostream>
#include <fstream>
#include <vector>
#include "OpenRAW"
using namespace std;

#define AutoOpen 1
#define Pic_name_in "IMG.raw"
#define Pic_name_out "IMG_OUT.raw"
#define Pic_x 256
#define Pic_y 256
#define Ratio 0.6

int main(int argc, char const *argv[]) {
    if(Ratio < 0) {
        cout << "Ratio more than the zero." << endl;
        return 0;
    }
    imgraw img(Pic_y, Pic_x);
    // imgraw img2(Pic_y, Pic_x);
    imgraw img2(Pic_y*Ratio, Pic_x*Ratio);
    img.read(Pic_name_in);
    //=========================================
    int apend_p=0; // 需要補的點
    int white=0; //幾個原點 (黑) 補一個新點 (白)
    int black=0; //處理放大倍率小數點，每幾個原點多補一個新點
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

        // 單點操作
        for(int j=0, yp=0; j < Pic_y; ++j) {
            limx_c=0;
            for(int i=0, xp=0; i < Pic_x; ++i) {
                // 填入原圖的點
                img2.point_write(j+yp, i+xp, img.point_read(j, i));
                // 補點 (整數) 每經一圓點補多少新點
                for(int k = 0; k < white; ++k) {
                    // k=補點位移指標，不是填入點位移指標
                    img2.point_write(j+yp, (i+xp)+k+1, img.point_read(j, i));
                } xp+=white; //填入點位移指標
                // 補點 2 (小數點倍率) 每經幾原點補一點新點
                if(black!=0 && (i+1)%black==0) { // 從0開始故多+1
                    // debug++;
                    if(limx_c<limx) {
                        limx_c+=1;
                        img2.point_write(j+yp, (i+xp)+1, img.point_read(j, i));
                        xp+=1;
                    }
                }
            }

            // 補排 (整數)
            for(int i = 0; i < white; ++i) {
                for(int k=0; k < Pic_x*Ratio; ++k)
                    img2.point_write(j+yp+1+i, k, img2.point_read(j+yp, k));
                // debug+=1;
            } yp+=white; //填入排位移指標
            // 補排 2 (小數點倍率)
            if(black!=0 && (j+1)%black==0) { // 從0開始故多+1
                if(limy_c<limy) {
                    if(white==0) { // 倍率介於1~2時
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
                    yp+=1; //填入排位移指標
                }
            }
        }
    } else { // 縮小
        int jmp=0; // 每讀幾點跳過
        jmp = (1 / (1-(float)Ratio));
        cout << "jmp=" << jmp << endl;
        limx = (int)(Pic_x*Ratio);
        limy = (int)(Pic_y*Ratio);
        for(int j = 0, yp = 0; j < Pic_y; ++j){
            // 列
            limx_c=0;
            for(int i = 0,xp = 0; i < Pic_x; ++i){
                if ((i+1)%jmp!=0){// 每隔 jmp 點就跳過
                    img2.point_write(yp, xp, img.point_read(j, i));
                    limx_c+=1;
                    xp+=1;
                    // 這裡的次數太少
                }
            }
            // 排
            if ((j+1)%jmp!=0 && limy_c< (int)(Pic_x*Ratio)-1){
                // if (limy_c<limy){
                    limy_c+=1;
                    yp+=1;
                // }
            }
        }
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
    cout << "debug = "   << debug   << endl;
    // cout << "t = "   << ((float)Ratio-(int)Ratio)   << endl;
    //=========================================



    img2.write(Pic_name_out);
    if (AutoOpen==1)
        system(Pic_name_out);
    return 0;
}