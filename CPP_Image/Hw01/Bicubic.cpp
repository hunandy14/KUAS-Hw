#include <iostream>
using namespace std;

// Bicubic
double cubicInterpolate (double p[4], double x);
double bicubicInterpolate (double p[4][4], double x, double y);
// Bicubic char
unsigned char cubicInterpolate_char (
    unsigned char p[4], double x);
unsigned char bicubicInterpolate_char (
    unsigned char p[4][4], double x, double y);



int main(int argc, char const *argv[]){
    double p[4][4] = {
        {46,40,42,44},
        {45,44,40,42},
        {42,42,42,40},
        {45,44,48,40}
    };

    unsigned char p_char[4][4] = {
        {'.', '(', '*', ','},
        {'-', ',', '(', '*'},
        {'*', '*', '*', '('},
        {'-', ',', '0', '('}
    };

    for (int j = 0; j < 4; ++j){
        for (int i = 0; i < 4; ++i){
            cout << (double)p_char[j][i] << ',';   
        }cout << endl;
    }

    cout << (double)bicubicInterpolate_char(p_char, 0.1, 0.2) << endl;
    // cout << bicubicInterpolate(p, 0.1, 0.2) << endl;
}



// Bicubic
double cubicInterpolate (double p[4], double x) {
    return p[1] + 0.5 * x*(p[2] - p[0] + x*(2.0*p[0] - 5.0*p[1] + 4.0*p[2] - p[3] + x*(3.0*(p[1] - p[2]) + p[3] - p[0])));
}
double bicubicInterpolate (double p[4][4], double x, double y) {
    double arr[4];
    for (int i = 0; i < 4; ++i)
        arr[i] = cubicInterpolate(p[i], y);
    return cubicInterpolate(arr, x);
}

// Bicubic char
unsigned char cubicInterpolate_char (unsigned char p[4], double x) {
    return p[1] + 0.5 * x*(p[2] - p[0] + x*(2.0*p[0] - 5.0*p[1] + 4.0*p[2] - p[3] + x*(3.0*(p[1] - p[2]) + p[3] - p[0])));
}
unsigned char bicubicInterpolate_char (unsigned char p[4][4], double x, double y) {
    unsigned char arr[4];
    for (int i = 0; i < 4; ++i)
        arr[i] = cubicInterpolate_char(p[i], y);
    return cubicInterpolate_char(arr, x);
}