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
typedef struct doulnk_struct node;
struct doulnk_struct {
    node *link;
    int data;
    node *rlink;
};
//=========================================================
/* API 說明文件*/

// 建立新節點並回傳節點地址 (節點的值)
node* node_creat(int data);
// 鏈結的長度 (鏈結的開頭)
int node_lenth(node* nh);
// 尋找最後一個節點的地址 (任意節點)
node* nodep_final(node* n);
// 印出節點的值 (任意節點)
void nodep_printpt(node* n);
// 印所有節點的值 (鏈結開頭)
void node_printall(node* nh);
// 印所有節點的資料 (鏈結開頭)
void node_printalldata(node* nh);
// 印所有節點的地址 (鏈結開頭)
void node_printalladd(node* nh);
// 在鏈結的最後方新增節點 (任意節點,新增節點的數值)
void nodep_append(node* n, int data);
// 批次在尾端新增節點 (任意節點,陣列,數量)
void nodep_input(node* n, int *ptr, int len);
// 節點地址查找,支持反向查找 (鏈結開頭,位置)
node* node_find(node* nh, int p);
// 插入節點,插入點會被往後推 (鏈結開頭,插入位置,數值)
void node_insert(node* nh, int p, int data);
// 刪除節點 (鏈結開頭,刪除位置)
void node_delete(node* nh, int p);
// 刪除鏈結,不會刪除鏈結開頭 (鏈結開頭)
void node_deleteall(node* nh);


// 確認是否為開頭 (任意節點)
int nodep_checkhead(node* n);
// 取出節點,回傳取出的地址,注意點沒有移除 (任意節點)
node* nodep_unlink(node* n1);
// 插入節點,n2插到n1前面 (任意節點,任意節點)
void nodep_insert(node* n1, node* n2);
// n1鏈結尾端加入n2鏈結 (任意節點,節點開頭)
void nodep_link(node* n1, node* n2);
// 查詢順序是否正確 (任意節點,任意節點)
int nodep_checkseq(node* n1, node* n2);
// 節點交換 (任意節點,任意節點)
void nodep_change(node* n1, node* n2);
// 尋找最後一個節點的地址 (任意節點)
node* nodep_head(node* n);
//=========================================================
int main(int argc, char const *argv[]){
    // 開頭節點
    node *nh=node_creat(-1);
    // 批次匯入節點
    int a[]={1,2,3,4,5,6,7,8};
    nodep_input(nh,a,8);

    
    node_printall(nh);
    nodep_change(node_find(nh,8),node_find(nh,7));
    // 印出節點
    cout << "=====================================" <<endl;
    node_printall(nh);  


    // 釋放記憶體
    node_deleteall(nh);
    delete [] nh;
    return 0;
}
//=========================================================
node* nodep_unlink(node* n2){
    if (nodep_checkhead(n2) == 0){
        node *n1=n2->link;
        node *n3=n2->rlink;
        if (n3==NULL){
            n1 -> rlink = NULL;
            n2 -> link = NULL;
            n2 -> rlink = NULL;
        }
        else{
            n1 -> rlink = n3;
            n3 -> link = n1;
            n2 -> link = NULL;
            n2 -> rlink = NULL;
        }
    }
    return n2;
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

node* nodep_final(node* n){
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

void nodep_printpt(node* n){
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
        if (i==0)
            cout << "      ";
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

void node_printalladd(node* nh){
    node* tmp=nh;
    for (int i = 0; i < node_lenth(nh)+1 ; ++i){
        cout << "[" << tmp->data << "]";
        cout << "[" << tmp << "] ";
        tmp=tmp->rlink;
    }
    cout << endl;
}

void nodep_append(node* n, int data){
    node* temp = nodep_final(n);
    node* nf = node_creat(data);
    temp -> rlink = nf;
    nf -> link = temp;
}

void nodep_input(node* n, int *ptr, int len){
    for (int i = 0; i < len; ++i){
        nodep_append(n,ptr[i]);
    }
}

node* node_find(node* nh, int p){
    node *temp=nh;
    int p1=p;

    //如果輸入負值
    if ( p<0 ){
        if (p<=-node_lenth(nh))
            p1=-node_lenth(nh);
        p1=p1+node_lenth(nh)+1;
    }else{
        if (p>=node_lenth(nh))
            p1=node_lenth(nh);
    }
    //開始查找
    for (int i = 0; i < p1; ++i){
        temp=temp->rlink;
    }
    return temp;
}

void node_insert(node* nh, int p, int data){
    node *target,*temp;
    target = node_find(nh,p);
    temp = node_creat(data);
    cout << nh << "||" <<target << "||" << temp << endl;
    if ( nodep_checkhead(node_find(target,0)) == 0){
        // 先將創建的點地址指好
        temp -> link = target -> link;
        temp -> rlink = target;
        // 在將目標的地址指好
        target -> link = temp;
        // 最後將創建的那一串接上
        temp -> link -> rlink = temp;
    }
}

void node_delete(node* nh, int p){
    node *target=node_find(nh,p);
    if ( nodep_checkhead(node_find(target,0)) == 0){
        target -> link -> rlink = target -> rlink;
        delete [] target;
    }
}

void node_deleteall(node* nh){
    for (int i = node_lenth(nh); i > 0; --i){
        node_delete(nh,i);
    }
}

int nodep_checkhead(node* n){
    if ( n->link == NULL ){
        cout << "  **Error! Head don't use.**" << endl;
        return 1;
    }
    else
        return 0;
}

void nodep_insert(node* n1, node* n2){
    if (nodep_checkhead(n1) == 0){
        n2 -> link = n1 -> link;
        n2 -> rlink = n1;
        n1 -> link = n2;
        n2->link -> rlink = n2;
    }
}

void nodep_link(node* n1, node* n2){
    node* temp = nodep_final(n1);
    temp -> rlink = n2;
    n2 -> link = temp;

}

int nodep_checkseq(node* n1, node* n2){
    node *temp=n1->rlink;
    for (int i = 0; i < node_lenth(n1); ++i){
        if (temp == n2)
            return 1;
        temp = temp->rlink;
    }
    return 0;
}

void nodep_change(node* n1, node* n2){
    if (n1==n2) return;
    
    // 如果n2在前調整順序
    node *nh, *nf, *n1r, *n2r;
    if (nodep_checkseq(n1,n2)==1){
        nh=n1;
        nf=n2;
        n1r = n1->rlink;
        n2r = n2->rlink;
    }else{
        nh=n2;
        nf=n1;
        n1r = n2->rlink;
        n2r = n1->rlink;
    }

    // 如果他們相鄰
    if (nf == n1r){
        nodep_unlink(nh);
        //如果n2在末端
        if (n2r==NULL){
            nodep_link(nf,nh);
        }else {
            nodep_insert(n2r,nh);
        }
    }
    // 如果他們不相鄰
    else{
        nodep_unlink(nf);
        nodep_insert(n1r,nf);
        nodep_unlink(nh);
        // 如果n2在末端
        if (n2r==NULL){
            nodep_link(nf,nh);
        }else {
            nodep_insert(n2r,nh);
        }
    }
}

node* nodep_head(node* n){
    int lenth=0;
    node* tmp=n;
    while( tmp->link != NULL || lenth>=999){
        tmp=tmp->link;
        lenth++;
    }
    return tmp;
}
//=========================================================