/**********************************************************
Name:KUAS-Hw/Hw05
DATE:2016/03/29
By CharlotteHong
**********************************************************/

//=========================================================
#include <iostream>
using namespace std;
//=========================================================

//=========================================================
/* typedef 型態宣告，可以想像成文字取代功能
比如說 [typedef A B] 可以把 [A(很長)]換成[B(單詞)]
以下就是一個範例，把長長的一串結構宣告換成node*/
typedef struct node_struct {
    node_struct *link;
    int data;
    node_struct *rlink;
} node;
//=========================================================
int main(int argc, char const *argv[]){

    node *head;
    head = new node_struct;   //實體化首節點
    head -> link = NULL;    //指向null
    head -> data = -1;
    head -> rlink = NULL;




    cout << head -> data;
    cout << endl;
    return 0;
}
//=========================================================

//=========================================================