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
    /* �}�Y�`�I */
    node** ht = new node*[3];
    ht[0] = node_creat(-1);
    ht[1] = node_creat(-1);
    ht[2] = node_creat(-1);
    /* �妸�פJ�`�I */
    int len = 8; //�X�ӽL�l
    int *data = new int[len];
    for (int i = 0; i < len; ++i)
        data[i] = len-i;
    nodep_input(ht[0], data, len);
    //=====================================================
    // �p��̵u�B��
    int setup=2;
    for (int i = 0; i < len-1; ++i){
        setup*=2;
    }setup--;
    //=====================================================
    // �}�l�B��
    for (int i = 0; i < setup; ++i){
        cout << "-------------------[" << i << "]" << "" << endl;
        cout << "�W�@�B: ";hanoi_logpri(ht);
        /* 1.�յP */
        if (hanoi_handdif(ht)==1){
            if (hanoi_defrag(ht) == 0){
                cout << "  def" << endl;
                continue;
            }
        }
        /* 2.�o�P */
        if (hanoi_checksent(ht)==1){
            if (hanoi_sent(ht) == 0){
                cout << "  sen" << endl;
                continue;
            }
        }
        /* 3.��or�� */
        // �t (��)
        if (hanoi_handdif(ht) % 2 == 0){
            // �S�����ƤW�@�B���� => �p���^
            if (hanoi_receive(ht, 0) == 0){
                cout << "  sre" << endl;
                continue;
            }
            // ���ƤW�@�B���� => �j��
            else{
                hanoi_receive(ht, 1);
                cout << "  bre" << endl;
                continue;
            }
        }
        // �t (��)
        else{
            // �S�����ƤW�@�B���� => �p��
            if (hanoi_change(ht)==0){
                cout << "  chg" << endl;
                continue;
            }
            // ���ƤW�@�B���� => �j��
            else{
                hanoi_receive(ht, 1);
                cout << "  bre" << endl;
                continue;
            }
        }
        cout << "Nothing" << endl;
    }
    cout << "-------------------[" << setup << "]" << "" << endl;
    cout << "�W�@�B: ";hanoi_logpri(ht);
    //=====================================================
    /* �L�X�`�I */
    cout << "==============================================" <<endl;
    hanoi_pri(ht);
    //=====================================================
    /* ����O���� */
    for (int i = 2; i >= 0; --i){
        node_deleteall(ht[i]);
        delete [] ht[i];
    } delete [] ht;
    //=====================================================
    return 0;
}
