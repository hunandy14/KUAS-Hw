/**********************************************************
Name : OpenRAW.cpp
Date : 2016/08/03
By   : CharlotteHonG
Final: 2016/08/03
**********************************************************/
#include <iostream>
#include <fstream>
#include <vector>
#include "OpenRAW"
using namespace std;

#define Pic_name_in "in.raw"
#define Pic_name_out "out.raw"

int main(int argc, char const *argv[]){
    imgraw img(Pic_name_in);
    img.read();
    img.write(Pic_name_out);
    return 0;
}

