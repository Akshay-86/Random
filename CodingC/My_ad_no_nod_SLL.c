#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};
struct node * create_new_node (int data );
struct node *add_nodes(struct node * head,int data ) ;
void print(struct node * head) ;

void main () {
    struct node * head = NULL;
    int i,n,data;
    printf("Enter the no of nodes u want to enter: " );
    scanf("%d",&n);

    for(i=0; i<n; i++) {
        printf("Enter the node %d : ",i+1);
        scanf("%d",&data);
        head = add_nodes(head,data);
    }

    printf("List is ");
    print(head);
}

struct node * create_new_node (int data ) {
    struct node * nn=(struct node *) malloc(sizeof(struct node));
    nn->data =data ;
    nn->next=NULL;
    return(nn);
}

struct node *add_nodes(struct node * head,int data ) {
    struct node * nn=create_new_node(data );
    if (head==NULL)
        head=nn;
    else {
        struct node *ptr=head;
        while (ptr->next!=NULL) {
            ptr=ptr->next;
        }
        ptr->next=nn;
    }
    return (head);
}

void print(struct node * head) {
    struct node * ptr=head;
    while(ptr!=NULL) {
        printf("%d->",ptr->data);
        ptr=ptr->next;
    }
    printf("NULL\n");
}