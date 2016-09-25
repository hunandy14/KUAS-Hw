/**********************************************************
Name : OpenRaw 2.4
Date : 2016/08/03
By   : CharlotteHonG
Final: 2016/09/25
**********************************************************/
//=========================================================
//-------------------------�غc�l---------------------------
//=========================================================
#include "OpenRaw\Structor.cpp"
//=========================================================
//------------------------ImrMask--------------------------
//=========================================================
#include "OpenRaw\ImrMask.cpp"
//=========================================================
//------------------------OpenRaw--------------------------
//=========================================================
#include "OpenRaw\imgraw.cpp"
//=========================================================
//-----------------------�B��l����-------------------------
//=========================================================
#include "OpenRaw\Operator.cpp"
//=========================================================
/*
    ###               ######
     #  #    # #####  #     #  ####  #        ##   #####
     #  ##  ## #    # #     # #    # #       #  #  #    #
     #  # ## # #    # ######  #    # #      #    # #    #
     #  #    # #####  #       #    # #      ###### #####
     #  #    # #   #  #       #    # #      #    # #   #
    ### #    # #    # #        ####  ###### #    # #    #
*/
// �H�G���覡Ū���μg�J
imint & ImrPolar::at2d(size_t y, size_t x){
    size_t pos = (y*this->ang) + x;
    return this->polar[pos];
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
void ImrMask::info(string title){
    cout << title << endl;
    for (int j = 0; j < (int)masksize.high; ++j){
        for (int i = 0; i < (int)masksize.width; ++i){
            cout << (int)this->at2d(j, i) << " ";
        }cout << endl;
    }cout << endl;
}
// ��t����(�֭�, �ǰt�C��, �I���C��)
void imgraw::sobel(int thr, imch value=128, imch bg=32){
    ImrMask p;
    imgraw s=*this;
    for (int j = 0; j < (int)this->high; ++j){
        for (int i = 0; i < (int)this->width; ++i){
            // �֤߹B�� 1
            // this->setMaskSize(ImrSize(3, 3));
            // p = this->getMask(ImrCoor(j, i));

            // double s1=
            //         (p[0]+2*p[1]+p[2])
            //        -(p[6]+2*p[7]+p[8]);
            // double s2=
            //         (p[2]+2*p[5]+p[8])
            //        -(p[0]+2*p[3]+p[6]);

            // �֤߹B�� 2
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

            // �P�_�֭�
            double sobel = abs(s1)+abs(s2);
            if(thr >= (int)sobel) {
                this->at2d(j, i) = (imch)bg;
            }else{
                this->at2d(j, i) = (imch)value;
            }
        }
    }
}
// ���N�ҽu��(�u����, �u���C��, soble�ǰt�C��)
void imgraw::hough(imint n, imch line_value=255, imch match_value=128){
    int h = (int)this->high;
    int w = (int)this->width;
    // �̤j���
    int big = h>w? h: w;
    // �̤j�Z��
    int maxdis = (int)(big*sqrt(2)+1);
    // �Ыؽw�s(2���O���F������)
    ImrPolar P(ImrSize(2*maxdis, 180));
    // �M��Ҧ����I��P��
    for (int j = 0; j < (int)this->high; ++j){
        for (int i = 0; i < (int)this->width; ++i){
            // ����I
            if (this->at2d(j, i) == match_value){
                // �O���Ҧ����ת�P��
                for (int k = 0; k < 180; ++k){
                    int ang = k;
                    int dis = j*sin(ang*PI/180) +
                              i*cos(ang*PI/180);
                    // �����ơA�h�[�FD�A����n��^��
                    P.at2d(dis+maxdis, ang) += 1;
                }
            }
        }
    }
    // �Ыؽu��
    ImrCoor polar;
    polar = P.get_P(n, 0);
    this->draw_line(polar, line_value);

    // for (int i = 0; i < (int)n; ++i){   
    //     �䭫�Ƴ̦h�����y�� (�Z��, ����)
    //     ImrCoor polar = P.get_P();
    //     �ھڧ�쪺���y��ø��
    //     this->draw_line(polar, line_value);
    //     this->draw_line(ImrCoor(P.get_P()), line_value);
    // }
}

// �䭫�Ƴ̦h��P�I
void ImrPolar::getarr_P(imint n, imint min=0){ 
    // �̤j�Z��
    int maxdis=this->dis;
    // �������Ʃʫe�X����P (P_tar[P_tar[0]]���̤j)
    P_tar.resize(n+1);
    // �䭫�Ƴ̦h��P�I
    int temp=min, c=0;
    for (int i = 0; i < maxdis*180; ++i){
        if (temp <= (int)(*this)[i] && 
            (int)(*this)[i] < this->P_limit){
            temp = (int)(*this)[i];
            // ����
            P_tar[++c] = i;
            if(c == (int)n) {
                c=0;
            }
        }
    }
    // ��s�̰��I(�U���׶})
    this->P_limit = temp;
    // �[�J����
    P_tar[0] = c;
}

// �䭫�Ƴ̦h��P�I�A�^�ǥؼЪ� (�Z��, ����)
ImrCoor ImrPolar::get_P(imint n, imint min=0){ 
    // �̤j�Z��
    int maxdis=this->dis;
    // �������Ʃʫe�X����P (P_tar[P_tar[0]]���̤j)
    P_tar.resize(n+1);
    // �䭫�Ƴ̦h��P�I
    int temp=min, c=0;
    for (int i = 0; i < maxdis*180; ++i){
        if (temp <= (int)(*this)[i] && 
            (int)(*this)[i] < this->P_limit){
            temp = (int)(*this)[i];
            // ����
            P_tar[++c] = i;
            if(c == (int)n) {
                c=0;
            }
        }
    }
    // ��s�̰��I(�U���׶})
    this->P_limit = temp;
    // �[�J����
    P_tar[0] = c;
    int dis = P_tar[c]/180 - maxdis/2;
    int ang = P_tar[c]%180;
    return ImrCoor(dis, ang);
}

// �e�u(���u��)
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