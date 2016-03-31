/**********************************************************
Name:KUAS-Hw/Hw05
DATE:2016/03/29
Final:2016/03/31
By CharlotteHong
**********************************************************/
//=========================================================
#include <iostream>
using namespace std;
//=========================================================
/* typedef 型態宣告，可以想像成文字取代功能
比如說 [typedef A B] 可以把 [A(很長)]換成[B(單詞)]
以下就是一個範例，把長長的一串結構宣告換成node*/
typedef struct doulnk_struct {
    doulnk_struct *link;
    int data;
    doulnk_struct *rlink;
} node;
//=========================================================
/* API 說明文件*/

// 建立新節點並回傳節點地址 (節點的值)
node* node_creat(int data);
// 鏈結的長度 (鏈結的開頭)
int node_lenth(node* nh);
// 尋找最後一個節點的地址 (任意節點)
node* node_final(node* n);
// 印出節點的值 (任意節點)
void node_print(node* n);
// 印所有節點的值 (鏈結開頭)
void node_printall(node* nh);
// 印所有節點的資料 (鏈結開頭)
void node_printalldata(node* nh);
// 在鏈結的最後方新增節點 (任意節點,新增節點的數值)
void node_appen(node* n, int data);
// 批次在尾端新增節點 (任意節點,陣列,數量)
void node_input(node* n, int *ptr, int len);
// 節點地址查找,支持反向查找 (節點開頭,位置)
node* node_find(node* nh, int p);
// 插入節點,插入點會被往後推 (鏈結開頭,插入位置,數值)
void node_insert(node* nh, int p, int data){
    
}

//=========================================================
int main(int argc, char const *argv[]){
    node *nh=node_creat(-1); // 開頭節點

    int a[]={1,2,3,4,5,6,7,8};
    node_input(nh,a,8);
    
    node_printalldata(nh);
    node_printall(nh);
    cout << "position=" << node_find(nh,-1);

    cout << endl;
    return 0;
}
//=========================================================
node* node_creat(int data){
    node *n;
    n = new doulnk_struct;
    n -> link = NULL;
    n -> data = data;
    n -> rlink = NULL;
    return n;
}

node* node_final(node* n){
    int lenth=0;
    node* tmp=n;
    while( tmp->rlink != NULL || lenth>=999){
        tmp=tmp->rlink;
        lenth++;
    }
    return tmp;
}

int node_lenth(node* nh){
    int lenth=0;
    node* tmp=nh;
    while( tmp->rlink != NULL || lenth>=999){
        tmp=tmp->rlink;
        lenth++;
    }
    return lenth;
}

void node_print(node* n){
    cout << "" << n << " || ";
    cout << "[" << n->link << "] ";
    cout << "[" << n->data << "] ";
    cout << "[" << n->rlink << "] " << endl;
}

void node_printall(node* nh){
    node* tmp=nh;
    for (int i = 0; i < node_lenth(nh)+1 ; ++i){
        cout << "" << tmp << " || ";
        cout << "[" << tmp->link << "] ";
        cout << "[" << tmp->data << "] ";
        cout << "[" << tmp->rlink << "] " << endl;
        tmp=tmp->rlink;
    }
}

void node_printalldata(node* nh){
    node* tmp=nh;
    for (int i = 0; i < node_lenth(nh)+1 ; ++i){
        cout << "[" << tmp->data << "] ";
        tmp=tmp->rlink;
    }
    cout << endl;
}

void node_appen(node* n, int data){
    node* temp = node_final(n);
    node* nf = node_creat(data);
    temp -> rlink = nf;
    nf -> link = temp;
}

void node_input(node* n, int *ptr, int len){
    for (int i = 0; i < len; ++i){
        node_appen(n,ptr[i]);
    }
}

node* node_find(node* nh, int p){
    node *temp=nh;
    int p1=p;
    if ( p<0 ){
        p1=p1+node_lenth(nh)+1;
    }
    cout << p1;
    for (int i = 0; i < p1; ++i){
        temp=temp->rlink;
    }
    return temp;
}
//=========================================================