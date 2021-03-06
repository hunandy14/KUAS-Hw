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
#include <string>
#include <math.h>
#include "OpenRAW"
using namespace std;

#define AutoOpen 0
#define Pic_name_in "IMG.raw"
#define Pic_name_out "IMG_OUT.raw"
#define Pic_x 256
#define Pic_y 256
#define Ratio 1.3

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
    
    // img.resize_zero(Ratio);
    // 寫檔
    img.write(Pic_name_out);
    // 開檔
    if (AutoOpen==1)
        system(Pic_name_out);
    return 0;
}