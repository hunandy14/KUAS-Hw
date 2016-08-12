/**********************************************************
Name : ZeroOrder.cpp
Date : 2016/08/03
By   : CharlotteHonG
Final: 2016/08/03

�w���p���I�ɪk�S������
black��k�S��k����
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
    // �Ыصe��
    imgraw img(Pic_y, Pic_x);
    // Ū��
    img.read(Pic_name_in);
    // ���j�p
    
    // img.resize_zero(Ratio);
    // �g��
    img.write(Pic_name_out);
    // �}��
    if (AutoOpen==1)
        system(Pic_name_out);
    return 0;
}