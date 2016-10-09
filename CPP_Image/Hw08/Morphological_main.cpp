/**********************************************************
Name : OpenRAW_main
Date : 2016/08/03
By   : CharlotteHonG
Final: 2016/10/05
**********************************************************/

#include <iostream>
#include "Morphological"
using namespace std;
using namespace imr;

#define AutoOpen 1
#define Pic_name_in "MorphologicalOperations_500x500.raw"
#define Pic_name_out "IMG_OUT.raw"
#define Pic_x 500
#define Pic_y 500

int main(int argc, char const *argv[]) {
    // 創建畫布
    imgraw img(ImrSize(Pic_y, Pic_x));
    // 讀取檔案
    img.read(Pic_name_in);
    //---------------------------------------------------------
    img.binarizae(128, 32, 0);
    // 膨脹
    img.dilation(255, 32);
    // 縮小
    // img.erosion(255, 32);
    //---------------------------------------------------------
    // 提示訊息
    img.info();
    //---------------------------------------------------------
    // 輸出檔案
    img.write(Pic_name_out);
    // 開啟檔案
    if(AutoOpen==1){
        string temp = "start \"\" ";
        temp += Pic_name_out;
        system(temp.c_str());
    }
    return 0;
}