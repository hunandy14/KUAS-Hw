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
#define Ratio 3.5


int GCD(int a, int b) {
    if(b) while((a %= b) && (b %= a));
    return a + b;
}


int main(int argc, char const *argv[]) {
    imgraw img(Pic_y, Pic_x);
    imgraw img2(Pic_y*Ratio, Pic_x*Ratio);
    img.read(Pic_name_in);

    //=========================================
    int apend_p = Pic_x*(Ratio-1); // 需要補的點
    int black, white; //幾個原點 (黑) 補一個新點 (白)
    if(apend_p >= Pic_x) { //補點多
        black = 1;
        white = apend_p/Pic_x;
        // 單點操作
        for(int j=0, yp=0; j < Pic_y; ++j) {
            for(int i=0, xp=0; i < Pic_x; ++i) {
                img2.point_write(j+yp, i+xp, img.point_read(j, i));
                xp+=white; //跳著填入
                // 補同樣的點
                for(int k = 0; k < white; ++k) {
                    img2.point_write(j+yp, (i+xp)+k+2, img.point_read(j, i));
                }
            }
            // 補排(複製上一排)
            for (int i = 0; i < white; ++i){
                for(int k=0; k < Pic_x*Ratio; ++k) {
                    img2.point_write(j+yp+1+i, k, img2.point_read(j+yp, k));
                }
            }
            yp+=white; //跳著填入
        }

    }
    else { //補點少
        black = Pic_x/apend_p;
        white = 1;
    }
    cout << "apend_p = " << apend_p << endl;
    cout << "Pic_x = "   << Pic_x   << endl;
    cout << "black = "   << black   << endl;
    cout << "white = "   << white   << endl;
    //=========================================

    

    img2.write(Pic_name_out);
    system(Pic_name_out);
    return 0;
}