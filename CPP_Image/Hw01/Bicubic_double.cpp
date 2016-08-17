/**********************************************************
Name : Bicubic_double.cpp
Date : 2016/08/16
By   : CharlotteHonG
Final: 2016/08/17
**********************************************************/
#include <iostream>
using namespace std;
typedef unsigned char imch;

// Bicubic
double cubicInterpolate (double p[4], double x);
double bicubicInterpolate (double p[4][4], double x, double y);


int main(int argc, char const *argv[]){
    double p[4][4] = {
        {46,40,42,44},
        {45,44,40,42},
        {42,42,42,40},
        {45,44,48,40}
    };
    
    cout << bicubicInterpolate(p, 0.1, 0.2) << endl;
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
