/**********************************************************
Name : OpenRaw 2.5.1
Date : 2016/08/03
By   : CharlotteHonG
Final: 2016/10/05
**********************************************************/
//=========================================================
//-------------------------Structor------------------------
//=========================================================
#include "OpenRaw_fun\Structor.cpp"
//=========================================================
//------------------------ImrSize--------------------------
//=========================================================
#include "OpenRaw_fun\ImrSize.cpp"
//=========================================================
//------------------------ImrMask--------------------------
//=========================================================
#include "OpenRaw_fun\ImrMask.cpp"
//=========================================================
//------------------------ImrCoor--------------------------
//=========================================================
#include "OpenRaw_fun\ImrCoor.cpp"
//=========================================================
//------------------------imgraw---------------------------
//=========================================================
#include "OpenRaw_fun\imgraw.cpp"
//=========================================================
//------------------------Operator-------------------------
//=========================================================
#include "OpenRaw_fun\Operator.cpp"
//=========================================================


void imgraw::wavelet(imint value=1){
    ImrMask a(ImrSize(4, 4));
    ImrMask b(ImrSize(4, 4));
    ImrMask c(ImrSize(4, 4));

    vector<imint> v={
        20, 26, 18, 24,
        32, 36, 30, 38,
        40, 42, 36, 46, 
        26, 28, 34, 42
    };

    int t=0;
    for(auto&& i : v) {
        a[t++] = i;
    }
    // row
    int w=4;
    for (int j=0, p=0; j < w; ++j){
        // 左邊
        for (int i = 0; i < w/2; ++i){
            // cout << "a=" << (int)a.at2d(j, (i*2)) << endl;
            b[p] = round(
                ((double)a.at2d(j, (i*2))
                +(double)a.at2d(j, (i*2)+1)) /2 
            );
            ++p;
        }
        // 右邊
        for (int i = 0; i < w/2; ++i){
            // cout << "a=" << (int)a.at2d(j, (i*2)) << endl;
            b[p] = round(
                ((double)a.at2d(j, (i*2))
                -(double)a.at2d(j, (i*2)+1)) /2 
            );
            // b[p]+=128;
            ++p;
        }
    }
    // col
    int h=4;
    for (int j=0, p=0; j < h; ++j){
        p=0;
        // 上面
        for (int i = 0; i < h/2; ++i){
            a.at2d(p, j) = round(
                ((double)b.at2d((i*2), j)
                +(double)b.at2d((i*2)+1, j)) /2 
            );
            ++p;
        }
        // 下面
        for (int i = 0; i < h/2; ++i){
            a.at2d(p, j) = round(
                ((double)b.at2d((i*2), j)
                -(double)b.at2d((i*2)+1, j)) /2 
            );
            ++p;
        }
    }




    cout << endl;
    a.info();
    cout << endl;
    b.info();
}