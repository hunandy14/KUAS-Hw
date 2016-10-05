/**********************************************************
Name : OpenRaw 2.4
Date : 2016/08/03
By   : CharlotteHonG
Final: 2016/09/10
**********************************************************/
//=========================================================
//-------------------------Structor------------------------
//=========================================================
#include "OpenRaw_fun\Structor.cpp"
ImrMask::ImrMask(ImrSize masksize){
    this->mask.vector::resize(masksize.high * masksize.width);
    this->masksize = masksize;
}

// ImrMask::ImrMask(ImrSize masksize, imch value){
//     this->mask.vector::resize(masksize.high * masksize.width);
//     this->masksize = masksize;
// }
//=========================================================
//------------------------ImrMask--------------------------
//=========================================================
#include "OpenRaw_fun\ImrMask.cpp"
//=========================================================
//------------------------OpenRaw--------------------------
//=========================================================
#include "OpenRaw_fun\imgraw.cpp"
//=========================================================
//------------------------Operator-------------------------
//=========================================================
#include "OpenRaw_fun\Operator.cpp"
//=========================================================


ImrMask ImrMask::operator+(const ImrMask &p){
    // 獲得最大長度
    imint y = this->masksize.high>p.masksize.high?
                this->masksize.high: p.masksize.high;
    imint x = this->masksize.width>p.masksize.width?
                this->masksize.width: p.masksize.width;
    // 獲得最小長度
    imint y_min = this->masksize.high<p.masksize.high? this->masksize.high: p.masksize.high;
    imint x_min = this->masksize.width<p.masksize.width? this->masksize.width: p.masksize.width;
    // 創建暫存影像
    ImrMask temp(ImrSize(y, x));
    // 單點相加
    for (int j = 0; j < (int)y_min; ++j){
        for (int i = 0; i < (int)x_min; ++i){
            double num = (double)this->at2d(j, i)
                + (double)p.at2d(j, i);
            if (num > (double)255){
                temp.at2d(j, i) = (imch)255;
            }
            else{
                temp.at2d(j, i) = (*this)[i]+p[i];
            }
        }
    }
    return temp;
}