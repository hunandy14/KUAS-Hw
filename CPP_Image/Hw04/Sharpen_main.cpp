/**********************************************************
Name : OpenRAW.cpp
Date : 2016/08/03
By   : CharlotteHonG
Final: 2016/09/08
**********************************************************/

#include <iostream>
#include "Sharpen"
using namespace std;
using namespace imr;

#define AutoOpen 0
#define Pic_name_in "IMG.raw"
#define Pic_name_out "IMG_OUT.raw"
#define Pic_x 512
#define Pic_y 512

int main(int argc, char const *argv[]) {
    // 創建畫布
    imgraw img(ImrSize(Pic_y, Pic_x));
    imgraw orimg;
    // 讀取檔案
    img.read(Pic_name_in);
    //---------------------------------------------------------
    img.pri_htg("Original");
    // 收縮
    img.shrink(ImrIntv(100,200));
    img.pri_htg("shrink");
    //---------------------------------------------------------
    // 印出直方圖
    // img.pri_htg("Original");
    //---------------------------------------------------------
    // 提示訊息
    cout << "畫布寬度 = " << img.w() << endl;
    //---------------------------------------------------------
    // 輸出檔案
    img.write(Pic_name_out);
    // 開啟檔案
    if(AutoOpen==1)
        system(Pic_name_out);
    return 0;
}