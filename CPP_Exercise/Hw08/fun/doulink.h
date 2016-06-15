/**********************************************************
Name : doulink
Date : 2016/06/15
By   : CharlotteHonG
Final: 2016/06/15
**********************************************************/
#ifndef DOULINK_H
#define DOULINK_H

using namespace std;
/* typedef ���A�ŧi�A�i�H�Q������r���N�\��
��p�� [typedef A B] �i�H�� [A(�ܪ�)]����[B(���)]
�H�U�N�O�@�ӽd�ҡA��������@�굲�c�ŧi����node*/
typedef struct doulnk_struct node;
struct doulnk_struct{
    node *link;
    int data;
    node *rlink;
};
//=========================================================
/* API �������*/

// �إ߷s�`�I�æ^�Ǹ`�I�a�} (�`�I����)
node* node_creat(int data);
// �쵲������ (�쵲���}�Y)
int node_lenth(node* nh);
// �M��̫�@�Ӹ`�I���a�} (���N�`�I)
node* nodep_final(node* n);
// �L�X�`�I���� (���N�`�I)
void nodep_printpt(node* n);
// �L�Ҧ��`�I���� (�쵲�}�Y)
void node_printall(node* nh);
// �L�Ҧ��`�I����� (�쵲�}�Y)
void node_printalldata(node* nh);
// �L�Ҧ��`�I���a�} (�쵲�}�Y)
void node_printalladd(node* nh);
// �b�쵲���̫��s�W�`�I (���N�`�I,�s�W�`�I���ƭ�)
void nodep_append(node* n, int data);
// �妸�b���ݷs�W�`�I (���N�`�I,�}�C,�ƶq)
void nodep_input(node* n, int *ptr, int len);
// �`�I�a�}�d��,����ϦV�d�� (�쵲�}�Y,��m)
node* node_address(node* nh, int p);
// ���J�`�I,���J�I�|�Q����� (�쵲�}�Y,���J��m,�ƭ�)
void node_insert(node* nh, int p, int data);
// �R���`�I (�쵲�}�Y,�R����m)
void node_delete(node* nh, int p);
// �R���쵲,���|�R���쵲�}�Y (�쵲�}�Y)
void node_deleteall(node* nh);

// �T�{�O�_���}�Y (���N�`�I)
int nodep_checkhead(node* n);
// ���X�`�I,�^�Ǩ��X���a�},�`�N�I�S������ (���N�`�I)
node* nodep_unlink(node* n1);
// ���J�`�I,n2����n1�e�� (���N�`�I,���N�`�I)
void nodep_insert(node* n1, node* n2);
// n1�쵲���ݥ[�Jn2�쵲 (���N�`�I,�`�I�}�Y)
void nodep_link(node* n1, node* n2);
// �d�߶��ǬO�_���T (���N�`�I,���N�`�I)
int nodep_checkseq(node* n1, node* n2);
// �`�I�洫 (���N�`�I,���N�`�I)
void nodep_change(node* n1, node* n2);
// �M��`�I�}�Y���a�} (���N�`�I)
node* nodep_head(node* n);
// ���쵲��� (�쵲�}�Y,��Ʀ�m)
int node_value(node* nh, int p);
// �Ƨ��쵲��� (�쵲�}�Y,�Ƨ��Y,�Ƨǧ�)
void node_short(node* nh, int h, int f);
// �Ƨ��쵲������� (�쵲�}�Y)
void node_short(node* nh);
// �Ƨ��쵲�e�X����� (�쵲�}�Y,�ƧǦ�m)
void node_short(node* nh,int p);
//=========================================================
#include "doulink.cpp"

#endif