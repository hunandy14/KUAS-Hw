#include <stdio.h>
#include <stdlib.h>

typedef struct node_struct {
    struct node_struct *link;
    int data;
    struct node_struct *rlink;
} node;

int main(int argc, char const *argv[]){

    node* head = (node*)malloc(sizeof(node));
    head -> link = NULL;    //指向null
    head -> data = 1;
    head -> rlink = NULL;

    node* head2 = (node*)malloc(sizeof(node));
    head2 -> link = NULL;    //指向null
    head2 -> data = 2;
    head2 -> rlink = NULL;


    printf("%d\n", head -> data);
    printf("%d\n", head2 -> data);
    return 0;
}
//=========================================================

//=========================================================