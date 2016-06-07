//=========================================================
#include <iostream>
using namespace std;
//=========================================================
/*  */
struct node_struct {
    node_struct *link;
    int data;
    node_struct *rlink;
};
int main(int argc, char const *argv[]){

    node_struct *head;
    head = new node_struct;   //實體化首節點
    head -> link = NULL;    //指向null
    head -> data = 1;
    head -> rlink = NULL;

    node_struct *head2;
    head2 = new node_struct;   //實體化首節點
    head2 -> link = NULL;    //指向null
    head2 -> data = 2;
    head2 -> rlink = NULL;

    cout << head -> data <<endl;
    cout << head2 -> data <<endl;
    cout << endl;
    return 0;
}
//=========================================================