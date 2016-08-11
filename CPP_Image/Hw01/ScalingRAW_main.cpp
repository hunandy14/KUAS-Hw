/**********************************************************
Name : ScalingRAW.cpp
Date : 2016/08/03
By   : CharlotteHonG
Final: 2016/08/10
**********************************************************/
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <math.h>
#include "ScalingRAW"
using namespace std;

#define AutoOpen 1
#define Pic_name_in "IMG.raw"
#define Pic_name_out "IMG_OUT.raw"
#define Pic_x 256
#define Pic_y 256
#define Ratio 3

int main(int argc, char const *argv[]) {
    if(Ratio < 0) {
        cout << "Ratio more than the zero." << endl;
        return 0;
    }
    // 創建畫布
    imgraw img(Pic_y, Pic_x);
    // 讀檔
    img.read(Pic_name_in);
    // 更改大小
    img.resize_first(Ratio);
    // 寫檔
    img.write(Pic_name_out);
    cout << "img.w()=" << img.w() << endl;
        
    // 開檔
    if(AutoOpen==1)
        system(Pic_name_out);
    return 0;
}