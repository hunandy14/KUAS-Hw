/**********************************************************
Name : 
Date : 2016/08/19
By   : CharlotteHonG
Final: 2016/08/19
**********************************************************/
#include <iostream>
#include "Historgram"
using namespace std;
using namespace imr;

#define AutoOpen 0
#define Pic_name_in "IMG.raw"
#define Pic_name_out "IMG_OUT.raw"
#define Pic_x 256
#define Pic_y 256
/*=======================================================*/
int main(int argc, char const *argv[]){
    // 創建畫布
    imgraw img(ImrSize(Pic_y, Pic_x));
    // 讀取檔案
    img.read(Pic_name_in);

    img.shrink(ImrIntv(0,255));

    // 提示訊息
    cout << "畫布寬度 = " << img.w() << endl;
    // 輸出檔案
    img.write(Pic_name_out);
    // 開啟檔案
    if(AutoOpen==1)
        system(Pic_name_out);
    return 0;
}
/*=======================================================*/