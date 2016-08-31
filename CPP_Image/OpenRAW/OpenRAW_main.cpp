/**********************************************************
Name : OpenRAW.cpp
Date : 2016/08/03
By   : CharlotteHonG
Final: 2016/08/12
**********************************************************/
#include <iostream>
#include "OpenRAW"
using namespace std;
using namespace imr;

#define AutoOpen 0
#define Pic_name_in "IMG.raw"
#define Pic_name_out "IMG_OUT.raw"
#define Pic_x 256
#define Pic_y 256

int main(int argc, char const *argv[]) {
    // 創建畫布
    imgraw img(ImrSize(Pic_y, Pic_x));
    imgraw img2(ImrSize(Pic_y, Pic_x));
    // 讀取檔案
    img.read(Pic_name_in);
    // 取得遮罩
    ImrSize size_m(3,3);
    imch** mask;
    mask=img.getMask(1, 1, size_m);
    
    // mask
    for(int j = 0; j < 3; ++j){
        for(int i = 0; i < 3; ++i) {
            cout << mask[j][i];
        }cout << endl;
    }
    // 源圖
    for(int j = 0; j < 3; ++j){
        for(int i = 0; i < 3; ++i) {
            cout << img.point_read(j, i);
        }cout << endl;
    }
    // 單點操作
    // for(int j = 0; j < Pic_y; ++j){
    //     for(int i = 0; i < Pic_x; ++i) {
    //         img2.point_write(j, i, img.point_read(j, i));
    //     }
    // }
    // 提示訊息
    // cout << "畫布寬度 = " << img2.w() << endl;
    // 印出直方圖
    // img.pri_htg("Original");
    // 輸出檔案
    // img.write(Pic_name_out);
    // 開啟檔案
    if(AutoOpen==1)
        system(Pic_name_out);
    return 0;
}