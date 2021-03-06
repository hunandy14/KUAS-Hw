/**********************************************************
Name : OpenRAW_maskVal 說明範例
Date : 2016/10/04
By   : CharlotteHonG
Final: 2016/10/13
**********************************************************/
#include <iostream>
#include "OpenRAW_fun\OpenRAW"
// Visual Studio 編譯需刪除該行與該檔案
#include "OpenRAW.cpp" // GCC單檔編譯用
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
    // 讀取檔案
    img.read(Pic_name_in);
    //---------------------------------------------------------
    // 讀取Mask用法(超過邊界會補邊界)
    cout << endl<< "maskVal" << endl;
    for(int j = 51; j < 54; ++j){
        for(int i = 51; i < 54; ++i) {
            ImrCoor ori(0,0);
            ImrCoor mas(j,i);
            // maskVal(原點，遮罩點)
            cout << setw(4) << (int)img.maskVal(ori,mas);
        }cout << endl;
    }
    // 原圖比較
    cout << endl<< "Original" << endl;
    for(int j = 50; j < 54; ++j){
        for(int i = 50; i < 54; ++i) {
            cout << setw(4) << (int)img.at2d(j,i);
        }cout << endl;
    }
    //---------------------------------------------------------
    // 提示訊息
    img.info();
    //---------------------------------------------------------
    // 輸出檔案
    img.write(Pic_name_out);
    // 開啟檔案
    if(AutoOpen==1)
        system(Pic_name_out);
    return 0;
}