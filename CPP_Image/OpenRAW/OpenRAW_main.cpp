/**********************************************************
Name : OpenRAW.cpp
Date : 2016/08/03
By   : CharlotteHonG
Final: 2016/08/12
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

int main(int argc, char const *argv[]) {
    imgraw img(Pic_y, Pic_x);
    imgraw img2(Pic_y, Pic_x);
    img.read(Pic_name_in);

    // 單點操作
    for(int j = 0; j < Pic_y; ++j){
        for(int i = 0; i < Pic_x; ++i) {
            // cout << img.point_read(j, i) << endl;
            img2.point_write(j, i, img.point_read(j, i));
        }
    }
    
    img2.write(Pic_name_out);
    system(Pic_name_out);
    return 0;
}