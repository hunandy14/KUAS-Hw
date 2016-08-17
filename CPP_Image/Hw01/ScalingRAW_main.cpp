/**********************************************************
Name : ScalingRAW.cpp
Date : 2016/08/03
By   : CharlotteHonG
Final: 2016/08/12
**********************************************************/
#include <iostream>
#include "ScalingRAW"
using namespace std;

#define AutoOpen 1
#define Pic_name_in "IMG.raw"
#define Pic_name_out "IMG_OUT.raw"
#define Pic_x 256
#define Pic_y 256
#define Ratio 2

int main(int argc, char const *argv[]) {
    // 創建畫布
    imgraw img(Pic_y, Pic_x);
    // 讀取檔案
    img.read(Pic_name_in);
    // 更改大小
    // img.resize_zero(Ratio);
    // img.resize_first(Ratio);
    img.resize_bicubic(Ratio);
    // 輸出檔案
    img.write(Pic_name_out);
    // 提示訊息
    cout << "畫布寬度 = " << img.w() << endl;
    // 開啟檔案
    if(AutoOpen==1)
        system(Pic_name_out);
    return 0;
}