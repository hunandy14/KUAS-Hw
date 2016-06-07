#include <stdio.h>
#include <stdlib.h>

struct node_struct {
    struct node_struct *link;
    int data;
    struct node_struct *rlink;
};

int main(int argc, char const *argv[]){
    struct node_struct* head;
    head = (struct node_struct*)malloc(sizeof(struct node_struct));
    head -> link = NULL;    //指向null
    head -> data = 1;
    head -> rlink = NULL;

    struct node_struct* head2;
    head2 = (struct node_struct*)malloc(sizeof(struct node_struct));
    head2 -> link = NULL;    //指向null
    head2 -> data = 2;
    head2 -> rlink = NULL;


    printf("%d\n", head -> data);
    printf("%d\n", head2 -> data);
    return 0;
}
//=========================================================

//=========================================================