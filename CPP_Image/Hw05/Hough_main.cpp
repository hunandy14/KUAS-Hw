/**********************************************************
Name : OpenRAW.cpp
Date : 2016/08/03
By   : CharlotteHonG
Final: 2016/09/25
**********************************************************/

#include <iostream>
#include "Hough"
using namespace std;
using namespace imr;

#define AutoOpen 0
#define Pic_name_in "Hough_868X600.raw"
#define Pic_name_out "IMG_OUT.raw"
#define Pic_x 868
#define Pic_y 600

int main(int argc, char const *argv[]) {
    // 讀取檔案
    // imgraw img(ImrSize(512, 512));
    // img.read("LENA.RAW");
    imgraw img(ImrSize(Pic_y, Pic_x));
    img.read(Pic_name_in);
    //---------------------------------------------------------
    // 邊緣偵測
    img.sobel(450);
    // 霍夫運算
    img.hough(500);
    //---------------------------------------------------------
    // 提示訊息
    cout << "畫布寬度 = " << img.w() << " x " << img.h() << endl;
    // 輸出檔案
    img.write(Pic_name_out);
    // 開啟檔案
    if(AutoOpen==1){
        system(Pic_name_out);
    }
    return 0;
}