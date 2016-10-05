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
    // ��o�̤j����
    imint y = this->masksize.high>p.masksize.high?
                this->masksize.high: p.masksize.high;
    imint x = this->masksize.width>p.masksize.width?
                this->masksize.width: p.masksize.width;
    // ��o�̤p����
    imint y_min = this->masksize.high<p.masksize.high? this->masksize.high: p.masksize.high;
    imint x_min = this->masksize.width<p.masksize.width? this->masksize.width: p.masksize.width;
    // �ЫؼȦs�v��
    ImrMask temp(ImrSize(y, x));
    // ���I�ۥ[
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