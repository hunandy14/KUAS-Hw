/**********************************************************
Name : Bicubic_char.cpp
Date : 2016/08/16
By   : CharlotteHonG
Final: 2016/08/17
**********************************************************/
#include <iostream>
using namespace std;
typedef unsigned char imch;

// Bicubic ���Ȯ֤߹B��
imch cubicInterpolate (imch* p, double x) {
    double temp = (double)(p[1] + 0.5 * 
        x*(p[2] - p[0] +x*(2.0*p[0] - 5.0*p[1] + 4.0*p[2] - 
            p[3] + x*(3.0*(p[1] - p[2]) + p[3] - p[0]))));
    if (temp > 255){temp = 255;}
    else if (temp < 0){temp = 0;}
    return (imch)temp;
}
// Bicubic ��J16�I�P���J��m�A���o�ؼЭ�
imch bicubicInterpolate (imch** p, double y, double x) {
    imch* arr = new imch[4];
    for (int i = 0; i < 4; ++i)
        arr[i] = cubicInterpolate(p[i], x);
    return cubicInterpolate(arr, y);
}
int main(int argc, char const *argv[]){
    imch p_char[4][4] = {
        {'.', '(', '*', ','},
        {'-', ',', '(', '*'},
        {'*', '*', '*', '('},
        {'-', ',', '0', '('}
    };//(0.1,0.2) => 43
    // �ʺA�}�C
    imch** mask = new imch*[4];
    for (int i = 0; i < 4; ++i){
        mask[i] = new imch[4];
        mask[i] = p_char[i];
    }
    // �d�ݰ}�C
    for (int j = 0; j < 4; ++j){
        for (int i = 0; i < 4; ++i){
            cout << mask[j][i] << ' ';   
        }cout << endl;
    }
    // ���ȵ��G
    cout << (int)bicubicInterpolate(mask, 0.1, 0.2) << endl;
    // ����O����
    for (int i = 0; i < 4; ++i)
        delete [] mask[i];
    delete [] mask;
}