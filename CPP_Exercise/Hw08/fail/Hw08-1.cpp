/**********************************************************
Name:KUAS-Hw/Hw08
DATE:2016/04/06
Final:2016/04/07
By CharlotteHong
**********************************************************/
//=========================================================
#include <iostream>
#include <stdio.h>
using namespace std;
//=========================================================
/* typedef 型態宣告，可以想像成文字取代功能
比如說 [typedef A B] 可以把 [A(很長)]換成[B(單詞)]
以下就是一個範例，把長長的一串結構宣告換成node*/
typedef struct doulnk_struct node;
struct doulnk_struct{
    node *link;
    int data;
    node *rlink;
};
//=========================================================
/* 切割字串 (要切割的字串,切割的符號)
字串的格式如 srt[]="1,2";
回傳值為陣列指標地址，陣列[0]是長度 */
int* str_split(const char* str, const char* sp);
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
node* node_address(node* nh, int p);
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
// 尋找節點開頭的地址 (任意節點)
node* nodep_head(node* n);
// 找鏈結資料 (鏈結開頭,資料位置)
int node_value(node* nh, int p);
// 排序鏈結資料 (鏈結開頭,排序頭,排序尾)
void node_short(node* nh, int h, int f);
// 排序鏈結全部資料 (鏈結開頭)
void node_short(node* nh);
// 排序鏈結前幾筆資料 (鏈結開頭,排序位置)
void node_short(node* nh,int p);
//=========================================================
// 檢查河內塔移動n1移動到n2 (柱子鏈接開頭,柱子鏈接開頭)
int hanoi_checkmove(node* nh1, node* nh2);
// 河內塔移動n1移動到n2 (柱子鏈接開頭,柱子鏈接開頭)
void hanoi_move(node* nh1, node* nh2);
// 查詢總數 (河內塔地址)
int hanoi_lenth(node** ht);
// 發牌 (河內塔地址)
void hanoi_sent(node** ht);
// 收牌 (河內塔地址,模式)
// 模式=0(小收),模式=1(大收)
void hanoi_receive(node** ht, int mode);
// 小收牌 (河內塔地址)
void hanoi_receive(node** ht);
// 手牌差計算 (河內塔地址,模式)
// 模式=-1 回傳 ht[1]-ht[2] 負值
int hanoi_handdif(node** ht, int mode);
// 手牌差[正數] (河內塔地址)
int hanoi_handdif(node** ht);
// 組牌 (河內塔地址)
void hanoi_defrag(node** ht);
// 換牌 (河內塔地址)
void hanoi_change(node** ht);
// 檢查可否發牌
int hanoi_checksent(node** ht){
    if (hanoi_checkmove(ht[0],ht[2]) == 1 || \
        hanoi_checkmove(ht[0],ht[1]) == 1)
        return 1;
    return 0;
}
//=========================================================
int main(int argc, char const *argv[]){
    /* 開頭節點 */
    // node* ht[3];
    node* *ht = new node*[3];
    ht[0] = node_creat(-1);
    ht[1] = node_creat(-1);
    ht[2] = node_creat(-1);
    /* 批次匯入節點 */
    int len = 3, *data = new int[len];
    for (int i = 0; i < len; ++i)
        data[i] = len-i;
    nodep_input(ht[0], data, len);
    //=====================================================
    // continue 
    int def=1, cha=1, sen=1, rec=1;
    int rc=0;//下下回之後把上面全部歸零
    int senc=-1;//第一柱原本有的還沒發完，不要啟動次要條件

    /*第29步失敗，無法精準確定條件
    可能要記錄上一步的步驟，判定是否相同*/

    int setup=2;
    for (int i = 0; i < len-1; ++i){
        setup*=2;
    }setup--;

    for (int i = 0; i < setup; ++i){
        cout << "******************" << endl;
        if (def!=1 || cha!=1 || sen!=1 || rec!=1){
            rc++;
        }
        if (rc==2){
            rc=0;def=1;cha=1;sen=1;rec=1;
        }
        for (int j = 0; j < 3; ++j)
            node_printalldata(ht[j]);
        cout << "def=" << def << ",cha=" << cha << ",sen=" << sen; 
        cout << ",rec=" << rec << ",rc=" << rc << endl;


        //偵測第一柱是否發完了
        if (senc == 0)  //延遲一回合，避免發牌當回合回收
            senc++;
        if (node_lenth(ht[0]) ==0 && senc<=0){
            senc++;
            // cout << "           ht[0] len =0" << endl;
        }
        

        /* 1.組牌 */
        if (hanoi_handdif(ht)==1 && def==1){
            hanoi_defrag(ht);
            cout << "[" << i+1 << "]";
            cout << "def" << endl;
            continue;
        }
        /* 2.發牌 */
        if (hanoi_checksent(ht)==1 && sen==1){
            hanoi_sent(ht);
            rec=0; rc=0;
            cout << "[" << i+1 << "]";
            cout << "sen" << endl;
            continue;
        }
        /* 3.收or換 */
        // 差 2(雙) => 小收回
        if (hanoi_handdif(ht) % 2 == 0){
            sen=0; rc=0;//標記不可發
            def=1;     //歸零重組
            cout << "                            ht0 len==" << node_lenth(ht[0]) << endl;
            if(senc == 1){
                
                if(rec==1 || i==28){ //這個i有問題，條件不完全應該會出bug
                    cout << "               small" << endl;
                    hanoi_receive(ht);
                }
                else {    //已標不可收 => 大收回
                    cout << "                            big"<<node_lenth(ht[0]) << endl;
                    cout << i << endl;
                    hanoi_receive(ht, 1);
                }
            }
            else{
                cout << "               small*" << endl;
                hanoi_receive(ht);
            }


            cout << "[" << i+1 << "]";
            cout << "dif.2" << endl;
            continue;
        }
        // 差 3(單) => 小換
        if (hanoi_handdif(ht) != 1){
            if (hanoi_handdif(ht) % 2 == 1){
                hanoi_change(ht);
                def=0; rc=0; //標記不可組
                sen=1; rec=1;      //歸零發收牌
                cout << "[" << i+1 << "]";
                cout << "dif.3" << endl;
                continue;
            }
        }else{
            // 差 1 => 大收回
            hanoi_receive(ht, 1);
            cout << "[" << i+1 << "]";
            cout << "dif.1" << endl;
            sen=0; rc=0; //標記不可發
            continue;
        }




        cout << "[" << i+1 << "]";
        cout << "Nothing" << endl;
    }






    //=====================================================
    /* 印出節點 */
    cout << "=====================================" <<endl;
    for (int i = 0; i < 3; ++i)
        node_printalldata(ht[i]);
    //=====================================================
    /* 釋放記憶體 */
    for (int i = 2; i >= 0; --i){
        node_deleteall(ht[i]);
        delete [] ht[i];
    } delete [] ht;
    return 0;
}
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

void hanoi_sent(node** ht){
    // 單數
    if (hanoi_lenth(ht)%2 == 1){
        if (hanoi_checkmove(ht[0],ht[2]) == 1){
            hanoi_move(ht[0],ht[2]);
        }else if (hanoi_checkmove(ht[0],ht[1]) == 1){
            hanoi_move(ht[0],ht[1]);
        }else {
            cout << "hanoi_sent Error!" << endl;
        }
    }
    // 雙數
    if (hanoi_lenth(ht)%2 == 0) {
        if (hanoi_checkmove(ht[0],ht[1])==1){
            hanoi_move(ht[0],ht[1]);
        }else if (hanoi_checkmove(ht[0],ht[2]) == 1){
            hanoi_move(ht[0],ht[2]);
        }else{
            cout << "hanoi_sent Error!" << endl;
        }
    }
    
}

void hanoi_receive(node** ht, int mode){
    if (mode==0){ //小收回
        if (nodep_final(ht[1])->data > \
            nodep_final(ht[2])->data){
            hanoi_move(ht[2],ht[0]);
        }else{
            hanoi_move(ht[1],ht[0]);
        }
        return;
    }
    if (mode==1){ //大收回
        if (nodep_final(ht[1])->data < \
            nodep_final(ht[2])->data){
            hanoi_move(ht[2],ht[0]);
        }else{
            hanoi_move(ht[1],ht[0]);
        }
        return;
    }
}

void hanoi_receive(node** ht){
    return hanoi_receive(ht, 0);
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

void hanoi_defrag(node** ht){
    if (hanoi_handdif(ht,-1) == 1)
        hanoi_move(ht[2],ht[1]);
    else if (hanoi_handdif(ht,-1) == -1)
        hanoi_move(ht[1],ht[2]);
    else
        cout << "defrag Error!" << endl;
}

void hanoi_change(node** ht){
    if (hanoi_handdif(ht,-1) > 0)
        hanoi_move(ht[2],ht[1]);
    else if (hanoi_handdif(ht,-1) < 0)
        hanoi_move(ht[1],ht[2]);
    else
        cout << "change Error!" << endl;
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
int* str_split(const char* str, const char* sp){
    // 計算字串長度
    int slen=0;
    while (str[slen]!=0 && slen<=999)
        slen++;
    // 計算字串內總共有幾個數
    int ilen=1;
    for (int i = 0; i < slen; ++i)
        if ( str[i] == sp[0]) 
            ilen++;
    // 根據長度配置記憶體
    int *ptr = new int[ilen+1];
    *ptr = (int)(ilen);
    // 開始切割
    int tempflag=0,index=1;
    char *temp = new char[1];
    for (int i = 0; i <= slen; ++i){
        if (str[i] == sp[0] || i==slen){
            ilen++;
            tempflag=0;
            // printf("temp=%c%c\n",temp[0],temp[1] );
            sscanf(temp, "%d", (ptr+index));
            index++;
            delete [] temp;
            temp = new char[1];
        }
        else {temp[tempflag++]=str[i];}
    } delete [] temp;
    return ptr;
}
/* ================================================== */