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
node* stlog[3]={NULL}; // �W�l�a�}�Ȧs (�˴��O�_���ƤW�@�B)
//=========================================================
// �ˬd�e���𲾰�n1���ʨ�n2 (�W�l�챵�}�Y,�W�l�챵�}�Y)
int hanoi_checkmove(node* nh1, node* nh2);
// �e���𲾰�n1���ʨ�n2 (�W�l�챵�}�Y,�W�l�챵�}�Y)
void hanoi_move(node* nh1, node* nh2);
// �d���`�� (�e����a�})
int hanoi_lenth(node** ht);
// �o�P (�e����a�})
int hanoi_sent(node** ht);
// ���P (�e����a�},�Ҧ�)
// �Ҧ�=0(�p��),�Ҧ�=1(�j��)
int hanoi_receive(node** ht, int mode);
// ��P�t�p�� (�e����a�},�Ҧ�)
// �Ҧ�=-1 �^�� ht[1]-ht[2] �t��
int hanoi_handdif(node** ht, int mode);
// ��P�t[����] (�e����a�})
int hanoi_handdif(node** ht);
// �յP (�e����a�})
int hanoi_defrag(node** ht);
// ���P (�e����a�})
int hanoi_change(node** ht);
// �ˬd�i�_�o�P
int hanoi_checksent(node** ht);
// �����B�J
void hanoi_logwri(node* nh1, node* nh2);
// �ˬd�B�J (�O�_���ƤW�@�B)
int hanoi_logchk(node* nh1, node* nh2);
// �L�X�B�J
void hanoi_logpri(node** ht);
// �L�X�e����
void hanoi_pri(node** ht);
//=========================================================
#include "hanoi.cpp"

#endif