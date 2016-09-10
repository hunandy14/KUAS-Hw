/**********************************************************
Name : OpenRAW.cpp
Date : 2016/08/03
By   : CharlotteHonG
Final: 2016/09/08
**********************************************************/

#include <iostream>
#include "Noise"
using namespace std;
using namespace imr;

#define AutoOpen 1
#define Pic_name_in "IMG.raw"
#define Pic_name_out "IMG_OUT.raw"
#define Pic_x 256
#define Pic_y 256
int main(int argc, char const *argv[]) {
        // 創建畫布
    imgraw img(ImrSize(Pic_y, Pic_x));
    imgraw img_ori=img;
    // imgraw img2(ImrSize(Pic_y, Pic_x));
    // 讀取檔案
    img.read(Pic_name_in);
    img.pri_htg("Original");
//---------------------------------------------------------
    // 胡椒鹽
    // img.salt_pepper(1);
    // 低通
    // img.low_pass();
    // 中值
    // img.median_filter();
    // 高斯
    img.gaussian();
//---------------------------------------------------------
    // 提示訊息
    cout << "畫布寬度 = " << img.w() << endl;
    // 印出直方圖
    img.pri_htg("After");
    // 輸出檔案
    img.write(Pic_name_out);
    // 開啟檔案
    if(AutoOpen==1)
        system(Pic_name_out);
    return 0;
}