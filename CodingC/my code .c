#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node * next;
};

struct node * add_nodes(struct node * head,int data);
struct node * create_node(int data);
void print(struct node * head);
struct node * add_beg(struct node *head);
struct node * add_end(struct node *head);
int data();

void main() {
    struct node * head = NULL;
    int i,n,data;
    printf("How many node r u going to enter: ");
    scanf("%d",&n);

    for (i=1; i<=n; i++) {
        printf("Enter node %d : ",i);
        scanf("%d",&data);
        head=add_nodes(head,data);
    }
    head=add_beg(head);
    head=add_end(head);

    printf("List is ");
    print(head);

}

struct node * create_node(int data) {
    struct node * nn=(struct node *)malloc(sizeof(struct node));
    nn->data = data;
    nn->next = NULL;
    return nn;
}
int data() {
    int data;
    printf("Enter data: ");
    scanf("%d",&data);
    return data;
}


struct node * add_nodes(struct node * head, int data) {
    struct node * nn = create_node(data);
    if(head == NULL)
        head =nn;
    else {
        struct node * ptr=head;
        while(ptr->next!= NULL) {
            ptr=ptr->next;
        }
        ptr->next=nn;
    }
    return head;
}

void print( struct node * head) {
    struct node * ptr=head;
    while (ptr!=NULL) {
        printf("%d->",ptr->data);
        ptr=ptr->next;
    }
    printf("NULL");
}

struct node * add_beg(struct node * head) {
    struct node * nn=create_node(data);
    nn->data=data();
    nn->next = head;
    head = nn;
    return nn;
}

struct node * add_end(struct node *head) {
    struct node * nn =create_node(data);
    
    struct node * ptr =head;
    while(ptr->next!= NULL) {
        ptr=ptr->next;
    }
    nn->data=data();
    ptr->next=nn;
    nn->next=NULL;
    return head;
}

