/**********************************************************
Name : OpenRAW.cpp
Date : 2016/08/03
By   : CharlotteHonG
Final: 2016/09/10
**********************************************************/

#include <iostream>
#include "Sharpen"
using namespace std;
using namespace imr;

#define AutoOpen 1
#define Pic_name_in "IMG.raw"
#define Pic_name_out "IMG_OUT.raw"
#define Pic_x 512
#define Pic_y 512

int main(int argc, char const *argv[]) {
    // 創建畫布
    imgraw img(ImrSize(Pic_y, Pic_x));
    // 讀取檔案
    img.read(Pic_name_in);
    imgraw img2=img;
    //---------------------------------------------------------
    img.pri_htg("Original");
    // 低通
    img.low_pass();
    // 收縮
    img.shrink(ImrIntv(0,120));
    // 相減
    for (int i = 0; i < Pic_y; ++i){
        for (int j = 0; j < Pic_x; ++j){
            if(img2.at2d(j, i) - img.at2d(j, i) < 0) {
                img2.at2d(j, i) = 0;
            }
            else{
                img2.at2d(j, i) -= img.at2d(j, i);
            }
        }
    }
    // 還原
    img2.stretch(ImrIntv(0,255));

    img2.pri_htg("shrink");
    //---------------------------------------------------------
    // 印出直方圖
    // img.pri_htg("Original");
    //---------------------------------------------------------
    // 提示訊息
    cout << "畫布寬度 = " << img.w() << endl;
    //---------------------------------------------------------
    // 輸出檔案
    img2.write(Pic_name_out);
    // 開啟檔案
    if(AutoOpen==1)
        system(Pic_name_out);
    return 0;
}