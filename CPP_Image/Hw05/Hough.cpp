/**********************************************************
Name : OpenRaw 2.4
Date : 2016/08/03
By   : CharlotteHonG
Final: 2016/09/25
**********************************************************/
//=========================================================
//-------------------------建構子---------------------------
//=========================================================
#include "OpenRaw\Structor.cpp"
//=========================================================
//------------------------ImrMask--------------------------
//=========================================================
#include "OpenRaw\ImrMask.cpp"
void ImrMask::info(string title){
    cout << title << endl;
    for (int j = 0; j < (int)masksize.high; ++j){
        for (int i = 0; i < (int)masksize.width; ++i){
            cout << (int)this->at2d(j, i) << " ";
        }cout << endl;
    }cout << endl;
}
//=========================================================
//------------------------OpenRaw--------------------------
//=========================================================
#include "OpenRaw\imgraw.cpp"
//=========================================================
//-----------------------運算子重載-------------------------
//=========================================================
#include "OpenRaw\Operator.cpp"
//=========================================================
void ImrCoor::info(){
    cout << this->y << ", " << this->x << endl;
}
/*
    ###               ######
     #  #    # #####  #     #  ####  #        ##   #####
     #  ##  ## #    # #     # #    # #       #  #  #    #
     #  # ## # #    # ######  #    # #      #    # #    #
     #  #    # #####  #       #    # #      ###### #####
     #  #    # #   #  #       #    # #      #    # #   #
    ### #    # #    # #        ####  ###### #    # #    #
*/
// 以二維方式讀取或寫入
imint & ImrPolar::at2d(size_t y, size_t x){
    size_t pos = (y*this->ang) + x;
    return this->polar[pos];
}
// 找重複最多的P點，回傳目標的 (距離, 角度)
ImrCoor ImrPolar::get_P(imint n, imint min=0){ 
    // 最大距離
    int maxdis=this->dis;
    // 紀錄重複性最高的P
    int tar;
    // 找重複最多的P點
    int temp=min;
    for (int i = 0; i < maxdis*180; ++i){
        if (temp <= (int)(*this)[i] && 
            (int)(*this)[i] < this->P_limit){
            // 紀錄(重複幾次的數據)
            temp = (int)(*this)[i];
            // 紀錄(極座標數據)
            tar = i;
        }
    }
    // 更新最高點(下次避開)
    this->P_limit = temp;
    // 轉換成極座標
    int dis = tar/180 - maxdis/2;
    int ang = tar%180;
    return ImrCoor(dis, ang);
}
/*
     ##   ##                             ##
     ##   ##                             ##
     ##   ##   #####   ##   ##   ######  ######
     #######  ##   ##  ##   ##  ##   ##  ##   ##
     ##   ##  ##   ##  ##   ##  ##   ##  ##   ##
     ##   ##  ##   ##  ##  ###   ######  ##   ##
     ##   ##   #####    ### ##       ##  ##   ##
                                 #####
*/
// 找霍夫線條(線條數, 線條顏色, soble匹配顏色)
void imgraw::hough(imint n, imch line_value=255, imch match_value=128){
    int h = (int)this->high;
    int w = (int)this->width;
    // 最大邊長
    int big = h>w? h: w;
    // 最大距離
    int maxdis = (int)(big*sqrt(2)+1);
    // 創建緩存(2倍是為了取正數)
    ImrPolar P(ImrSize(2*maxdis, 180));
    // 尋找所有白點的P值
    for (int j = 0; j < (int)this->high; ++j){
        for (int i = 0; i < (int)this->width; ++i){
            // 找白點
            if (this->at2d(j, i) == match_value){
                // 記錄所有角度的P值
                for (int k = 0; k < 180; ++k){
                    int ang = k;
                    int dis = j*sin(ang*PI/180) +
                              i*cos(ang*PI/180);
                    // 取正數，多加了D，之後要減回來
                    P.at2d(dis+maxdis, ang) += 1;
                }
            }
        }
    }
    // 尚未優化
    ImrCoor po;
    for (int i = 0; i < (int)n; ++i){
        // 尋找線條
        po = P.get_P(n, 0);
        // 查看極座標
        // cout << "polar ="; po.info();
        // 畫圖
        // this->draw_line(po, line_value);
    }
}
// 畫線(待優化)
void imgraw::draw_line(ImrCoor polar, imch value){
    for (int j = 0; j < (int)this->high; ++j){
        for (int i = 0; i < (int)this->width; ++i){
            int dis = (int)(i*cos(polar.x*PI/180)) +
                      (int)(j*sin(polar.x*PI/180));
            if( dis == polar.y) {
                this->at2d(j, i) = value;
            }
        }
    }
}
// 邊緣偵測(閥值, 匹配顏色, 背景顏色)
void imgraw::sobel(int thr, imch value=128, imch bg=32){
    ImrMask p;
    imgraw s=*this;
    for (int j = 0; j < (int)this->high; ++j){
        for (int i = 0; i < (int)this->width; ++i){
            // 核心運算 1
            // this->setMaskSize(ImrSize(3, 3));
            // p = this->getMask(ImrCoor(j, i));

            // double s1=
            //         (p[0]+2*p[1]+p[2])
            //        -(p[6]+2*p[7]+p[8]);
            // double s2=
            //         (p[2]+2*p[5]+p[8])
            //        -(p[0]+2*p[3]+p[6]);

            // 核心運算 2
            ImrCoor ori(j, i);
            double s1 = 
                (
                  s.maskVal(ori, ImrCoor(0, 0)) +
                  2*s.maskVal(ori, ImrCoor(0, 1)) +
                  s.maskVal(ori, ImrCoor(0, 2))
                ) -
                (
                  s.maskVal(ori, ImrCoor(2, 0)) +
                  2*s.maskVal(ori, ImrCoor(2, 1)) +
                  s.maskVal(ori, ImrCoor(2, 2))
                );
            double s2 =
                (
                  s.maskVal(ori, ImrCoor(0, 2)) +
                  2*s.maskVal(ori, ImrCoor(1, 2)) +
                  s.maskVal(ori, ImrCoor(2, 2))
                ) -
                (
                  s.maskVal(ori, ImrCoor(0, 0)) +
                  2*s.maskVal(ori, ImrCoor(1, 0)) +
                  s.maskVal(ori, ImrCoor(2, 0))
                );

            // 判斷閥值
            double sobel = abs(s1)+abs(s2);
            if(thr >= (int)sobel) {
                this->at2d(j, i) = (imch)bg;
            }else{
                this->at2d(j, i) = (imch)value;
            }
        }
    }
}