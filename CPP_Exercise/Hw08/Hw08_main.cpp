/**********************************************************
Name : KUAS-Hw/Hw08
DATE : 2016/04/06
Final: 2016/06/15
By   : CharlotteHong
**********************************************************/
//=========================================================
#include <iostream>
#include <stdio.h>
#include "fun\hanoi.h"
#include "fun\doulink.h"
using namespace std;
//=========================================================
int main(int argc, char const *argv[]){
    /* 開頭節點 */
    node** ht = new node*[3];
    ht[0] = node_creat(-1);
    ht[1] = node_creat(-1);
    ht[2] = node_creat(-1);
    /* 批次匯入節點 */
    int len = 8; //幾個盤子
    int *data = new int[len];
    for (int i = 0; i < len; ++i)
        data[i] = len-i;
    nodep_input(ht[0], data, len);
    //=====================================================
    // 計算最短步數
    int setup=2;
    for (int i = 0; i < len-1; ++i){
        setup*=2;
    }setup--;
    //=====================================================
    // 開始運行
    for (int i = 0; i < setup; ++i){
        cout << "-------------------[" << i << "]" << "" << endl;
        cout << "上一步: ";hanoi_logpri(ht);
        /* 1.組牌 */
        if (hanoi_handdif(ht)==1){
            if (hanoi_defrag(ht) == 0){
                cout << "  def" << endl;
                continue;
            }
        }
        /* 2.發牌 */
        if (hanoi_checksent(ht)==1){
            if (hanoi_sent(ht) == 0){
                cout << "  sen" << endl;
                continue;
            }
        }
        /* 3.收or換 */
        // 差 (雙)
        if (hanoi_handdif(ht) % 2 == 0){
            // 沒有重複上一步的話 => 小收回
            if (hanoi_receive(ht, 0) == 0){
                cout << "  sre" << endl;
                continue;
            }
            // 重複上一步的話 => 大收
            else{
                hanoi_receive(ht, 1);
                cout << "  bre" << endl;
                continue;
            }
        }
        // 差 (單)
        else{
            // 沒有重複上一步的話 => 小換
            if (hanoi_change(ht)==0){
                cout << "  chg" << endl;
                continue;
            }
            // 重複上一步的話 => 大收
            else{
                hanoi_receive(ht, 1);
                cout << "  bre" << endl;
                continue;
            }
        }
        cout << "Nothing" << endl;
    }
    cout << "-------------------[" << setup << "]" << "" << endl;
    cout << "上一步: ";hanoi_logpri(ht);
    //=====================================================
    /* 印出節點 */
    cout << "==============================================" <<endl;
    hanoi_pri(ht);
    //=====================================================
    /* 釋放記憶體 */
    for (int i = 2; i >= 0; --i){
        node_deleteall(ht[i]);
        delete [] ht[i];
    } delete [] ht;
    return 0;
}
