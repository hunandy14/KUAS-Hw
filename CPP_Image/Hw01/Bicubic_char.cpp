/**********************************************************
Name : Bicubic_char.cpp
Date : 2016/08/16
By   : CharlotteHonG
Final: 2016/08/17
**********************************************************/
#include <iostream>
using namespace std;
typedef unsigned char imch;

// Bicubic char
imch cubicInterpolate (imch* p, double x) {
    return p[1] + 0.5 * x*(p[2] - p[0] + x*(2.0*p[0] - 5.0*p[1] + 4.0*p[2] - p[3] + x*(3.0*(p[1] - p[2]) + p[3] - p[0])));
}
imch bicubicInterpolate (imch** p, double x, double y) {
    imch* arr = new imch[4];
    for (int i = 0; i < 4; ++i)
        arr[i] = cubicInterpolate(p[i], y);
    return cubicInterpolate(arr, x);
}
int main(int argc, char const *argv[]){
    imch p_char[4][4] = {
        {'.', '(', '*', ','},
        {'-', ',', '(', '*'},
        {'*', '*', '*', '('},
        {'-', ',', '0', '('}
    };//(0.1,0.2) => 43
    // 動態陣列
    imch** mask = new imch*[4];
    for (int i = 0; i < 4; ++i){
        mask[i] = new imch[4];
        mask[i] = p_char[i];
    }
    // 查看陣列
    for (int j = 0; j < 4; ++j){
        for (int i = 0; i < 4; ++i){
            cout << mask[j][i] << ' ';   
        }cout << endl;
    }
    // 插值結果
    cout << (int)bicubicInterpolate(mask, 0.1, 0.2) << endl;
    // 釋放記憶體
    for (int i = 0; i < 4; ++i)
        delete [] mask[i];
    delete [] mask;
}