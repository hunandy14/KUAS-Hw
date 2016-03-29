#include <stdio.h>
#include <stdlib.h>

// 宣告節點結構
typedef struct nodestruct{
    int data;
    struct nodestruct* next;
} node;

// 宣告相關函式
node* create_node(int);
void insert_node(node*, node*);
void remove_node(node*);
void print_lists(node*);
void free_lists(node*);
int node_value( node*, int);
node* node_link( node*, int);
void insertion_sort(node*, int, int);
void node_change( node*, int);
/*========================================================================*/
#define ArrayLen 10				//陣列長度
int main(){
	int array[ArrayLen+1] = { 8,5,4,6,7,1,3,2,10,9 };
	node* n[ArrayLen+1];		//宣告節點數量
	int i=0;
	n[0] = create_node( -1 );
	for(i=0;i<ArrayLen;i++){	//陣列導入指標結構單向鏈結(設初始值)
		n[i+1] = create_node( array[i] );
	    insert_node(n[i],n[i+1]);
	} 
	
	printf("Sequence Before \n");
	print_lists(n[0]);			//印出整串節點
	insertion_sort( n[0], 1, ArrayLen );
	printf("Sequence After \n");
    print_lists(n[0]);			//印出整串節點
    free_lists(n[0]);			//歸還記憶體
}

void insertion_sort(node* lists, int first, int last){
	int i=first+1, j=first, temp;
	for ( i=first+1 ; i<=last; i++)
		for(j=i-1; j>=first && node_value(lists,j)>node_value(lists,j+1); j--)
			node_change(lists,j);	//如果比前面大就一直往前換，直到比前面小
}
/*========================================================================*/
void node_change( node* lists, int i){	// 傳入第一點的地址，將他與後者交換
	int j;
	if( (node_link(lists,i)->next != NULL) && i>0 ){
		node* temp=node_link(lists,i);
		node_link(lists,i-1)->next=node_link(lists,i+1);
		temp->next = node_link(lists,i+1);
		node_link(lists,i)->next = temp;
	}
}

node* create_node(int data){		    // 動態配置記憶體
    node* n = (node*)malloc(sizeof(node));
    n->data = data;
    n->next = NULL;
    return n;
}

void insert_node(node* n1, node* n2){	// 將N2插在N1後(N2連接將設成原本N1連結)
    n2->next = n1->next;
    n1->next = n2;
}

void remove_node(node* n1){				// 移除節點連結(沒有刪除節點)
    n1->next = n1->next->next;
}

int node_value( node* lists, int i){	// 傳入第一點的地址，回傳指定節點的值
	int j;
	for(j=0;j<i;j++){
		lists=lists->next;
	}
	return lists->data;
}

node* node_link( node* lists, int i){	// 傳入第一點的地址，回傳指定節點地址
	int j;
	for(j=0;j<i;j++)
		lists=lists->next;
	return lists;
}

void print_lists(node* lists){			// 依序印出節點內容
    node* n = lists->next;
    printf("  Node Lists = ");
    while (n != NULL){
        printf("%d ", n->data);
        n = n->next;
    }
    printf("\n");
}

void free_lists(node* lists){			// 遞迴刪除串列所有節點
    if (lists->next != NULL)
        free_lists(lists->next);
    free(lists);
}
/*========================================================================*/