/**********************************************************
Name : doulink
Date : 2016/06/15
By   : CharlotteHonG
Final: 2016/06/15
**********************************************************/
#include <iostream>
#include <stdio.h>
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
    while( tmp->rlink != NULL && lenth<=999){
        tmp=tmp->rlink;
        lenth++;
    }
    return tmp;
}

int node_lenth(node* nh){
    int lenth=0;
    node* tmp=nh;
    while( tmp->rlink != NULL && lenth<=999){
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
    node* tmp = nh->rlink;
    for (int i = 0; i < node_lenth(nh) ; ++i){
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

node* node_address(node* nh, int p){
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
    target = node_address(nh,p);
    temp = node_creat(data);
    cout << nh << "||" <<target << "||" << temp << endl;
    if ( nodep_checkhead(node_address(target,0)) == 0){
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
    node *target=node_address(nh,p);
    if ( nodep_checkhead(node_address(target,0)) == 0){
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
    while( tmp->link != NULL && lenth<=999){
        tmp=tmp->link;
        lenth++;
    }
    return tmp;
}

int node_value(node* nh, int p){
    return node_address(nh,p)->data;
}

void node_short(node* nh, int h, int f){
    for (int j=h+1; j<=f; j++){
        for(int i=j-1; i>=h && node_value(nh,i)>node_value(nh,i+1); i--){
            //如果比前面大就一直往前換，直到比前面小
            nodep_change(node_address(nh,i),node_address(nh,i+1));
        }
    }
}

void node_short(node* nh){
    return node_short(nh,1,node_lenth(nh));
}

void node_short(node* nh,int p){
    return node_short(nh,1,p);
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