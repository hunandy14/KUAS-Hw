/**********************************************************
Name : hanoi
Date : 2016/06/15
By   : CharlotteHonG
Final: 2016/06/15
**********************************************************/
#ifndef HANOI_H
#define HANOI_H

#include <iostream>
#include <stdio.h>
#include "doulink.h"
using namespace std;
node* stlog[3]={NULL}; // 柱子地址暫存 (檢測是否重複上一步)
//=========================================================
// 檢查河內塔移動n1移動到n2 (柱子鏈接開頭,柱子鏈接開頭)
int hanoi_checkmove(node* nh1, node* nh2);
// 河內塔移動n1移動到n2 (柱子鏈接開頭,柱子鏈接開頭)
void hanoi_move(node* nh1, node* nh2);
// 查詢總數 (河內塔地址)
int hanoi_lenth(node** ht);
// 發牌 (河內塔地址)
int hanoi_sent(node** ht);
// 收牌 (河內塔地址,模式)
// 模式=0(小收),模式=1(大收)
int hanoi_receive(node** ht, int mode);
// 手牌差計算 (河內塔地址,模式)
// 模式=-1 回傳 ht[1]-ht[2] 負值
int hanoi_handdif(node** ht, int mode);
// 手牌差[正數] (河內塔地址)
int hanoi_handdif(node** ht);
// 組牌 (河內塔地址)
int hanoi_defrag(node** ht);
// 換牌 (河內塔地址)
int hanoi_change(node** ht);
// 檢查可否發牌
int hanoi_checksent(node** ht);
// 紀錄步驟
void hanoi_logwri(node* nh1, node* nh2);
// 檢查步驟 (是否重複上一步)
int hanoi_logchk(node* nh1, node* nh2);
// 印出步驟
void hanoi_logpri(node** ht);
// 印出河內塔
void hanoi_pri(node** ht);
//=========================================================
#include "hanoi.cpp"

#endif