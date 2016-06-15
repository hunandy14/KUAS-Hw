/**********************************************************
Name : 
Date : 2016/06/15
By   : CharlotteHonG
Final: 2016/06/15
**********************************************************/
#include <iostream>
#include <stdio.h>
#include "doulink.h"
using namespace std;
//=========================================================
int hanoi_checkmove(node* nh1, node* nh2){
    if (nodep_final(nh1)->link == NULL){
        // cout << "hanoi_move Error!!" << endl;
        // cout << "   n1 is link head." << endl;
        return 0;
    }
    if (nodep_final(nh2)->link != NULL){
        if (nodep_final(nh1)->data > nodep_final(nh2)->data){
            // cout << "hanoi_move Error!!" << endl;
            // cout << "   n1 value > n2." << endl;
            return 0;
        }
    }
    return 1;
}

void hanoi_move(node* nh1, node* nh2){
    if (hanoi_checkmove(nh1,nh2)==0)
        return;
    hanoi_logwri(nh1, nh2);
    node* temp = nodep_final(nh1);
    nodep_unlink(temp);
    nodep_link(nodep_final(nh2), temp);
}

int hanoi_lenth(node** ht){
    int len=0;
    for (int i = 0; i < 3; ++i)
        len += node_lenth(ht[i]);
    return len;
}

int hanoi_sent(node** ht){
    // 單數
    if (hanoi_lenth(ht)%2 == 1){
        if (hanoi_checkmove(ht[0],ht[2]) == 1){
            // 如果重複上一步的話(另一個收也算)
            if (hanoi_logchk(ht[0],ht[2])==1 ||
                hanoi_logchk(ht[0],ht[1])==1)
                return 1;
            hanoi_move(ht[0],ht[2]);
        }else if (hanoi_checkmove(ht[0],ht[1]) == 1){
            // 如果重複上一步的話(另一個收也算)
            if (hanoi_logchk(ht[0],ht[1])==1 ||
                hanoi_logchk(ht[0],ht[2])==1)
                return 1;
            hanoi_move(ht[0],ht[1]);
        }else {
            cout << "hanoi_sent Error!" << endl;
            
        }
    }
    // 雙數
    if (hanoi_lenth(ht)%2 == 0) {
        if (hanoi_checkmove(ht[0],ht[1])==1){
            // 如果重複上一步的話(另一個收也算)
            if (hanoi_logchk(ht[0],ht[1])==1 ||
                hanoi_logchk(ht[0],ht[2])==1)
                return 1;
            hanoi_move(ht[0],ht[1]);
        }else if (hanoi_checkmove(ht[0],ht[2]) == 1){
            // 如果重複上一步的話(另一個收也算)
            if (hanoi_logchk(ht[0],ht[2])==1 ||
                hanoi_logchk(ht[0],ht[1])==1)
                return 1;
            hanoi_move(ht[0],ht[2]);
        }else{
            cout << "hanoi_sent Error!" << endl;
            
        }
    }
    return 0;
}

int hanoi_receive(node** ht, int mode){
    if (mode==0){ //小收回
        if (nodep_final(ht[1])->data > \
            nodep_final(ht[2])->data){
            if (hanoi_logchk(ht[2],ht[0])==1)
                return 1;
            hanoi_move(ht[2],ht[0]);
        }else{
            if (hanoi_logchk(ht[1],ht[0])==1)
                return 1;
            hanoi_move(ht[1],ht[0]);
        }
    }
    if (mode==1){ //大收回
        if (nodep_final(ht[1])->data < \
            nodep_final(ht[2])->data){
            if (hanoi_logchk(ht[2],ht[0])==1)
                return 1;
            hanoi_move(ht[2],ht[0]);
        }else{
            if (hanoi_logchk(ht[1],ht[0])==1)
                return 1;
            hanoi_move(ht[1],ht[0]);
        }
    }
    return 0;
}

int hanoi_handdif(node** ht, int mode){
    int temp=nodep_final(ht[1])->data;
    temp-=nodep_final(ht[2])->data;
    if (temp < 0 && mode!=-1)
        temp += (0 - temp)*2;
    return temp;
}

int hanoi_handdif(node** ht){
    return hanoi_handdif(ht, 0);
}

int hanoi_defrag(node** ht){
    if (hanoi_handdif(ht,-1) == 1){
        //如果重複上一個步驟的話
        if (hanoi_logchk(ht[2],ht[1])==1)
            return 1;
        hanoi_move(ht[2],ht[1]);
    }
    else if (hanoi_handdif(ht,-1) == -1){
        //如果重複上一個步驟的話
        if (hanoi_logchk(ht[1],ht[2])==1)
            return 1;
        hanoi_move(ht[1],ht[2]);
    }
    else
        cout << "defrag Error!" << endl;
    return 0;
}

int hanoi_change(node** ht){
    if (hanoi_handdif(ht,-1) > 0){
        // cout << "test1=" << hanoi_logchk(ht[2],ht[1]) << endl;
        if (hanoi_logchk(ht[2],ht[1])==1)
            return 1;
        hanoi_move(ht[2],ht[1]);
    }
    else if (hanoi_handdif(ht,-1) < 0){
        // cout << "test2=" << hanoi_logchk(ht[1],ht[2]) << endl;
        if (hanoi_logchk(ht[1],ht[2])==1)
            return 1;
        hanoi_move(ht[1],ht[2]);
    }
    else{
        cout << "change Error!" << endl;
    }
    return 0;
}

int hanoi_checksent(node** ht){
    if (hanoi_checkmove(ht[0],ht[2]) == 1 || \
        hanoi_checkmove(ht[0],ht[1]) == 1){
        return 1;
    }
    return 0;
}

void hanoi_logwri(node* nh1, node* nh2){
    stlog[1]=nh1;
    stlog[2]=nh2;
}

int hanoi_logchk(node* nh1, node* nh2){
    if (stlog[1] == nh2 && stlog[2] == nh1){
        return 1;
    }
    return 0;
}

void hanoi_logpri(node** ht){
    for (int i = 0; i < 3; ++i){
        if (ht[i]==stlog[1]){
            cout << i << ">>";
            break;
        }
    }

    for (int i = 0; i < 3; ++i){
        if (ht[i]==stlog[2]){
            cout << i;
            break;
        }
    }cout << endl;
}

void hanoi_pri(node** ht){
    for (int i = 0; i < 3; ++i){
        cout << "[" << i+1 << "]" << " => ";
        node_printalldata(ht[i]);
    }
}
//=========================================================