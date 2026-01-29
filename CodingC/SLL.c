#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node * next;
};

struct node * add_nodes(struct node * head);
struct node * create_node();
void print(struct node * head);
/*
struct node * del_beg(struct node *head);
struct node * del_end(struct node * head);
struct node * del_pos(struct node * head,int n);
*/

struct node * add_beg(struct node *head);
struct node * add_end(struct node *head);
struct node * add_pos(struct node * head,int n);


int main() {
    struct node * head = NULL;
    int i,n,a;
    printf("How many node r u going to enter: ");
    scanf("%d",&n);

    for (i=1; i<=n; i++) {

        head=add_nodes(head);

    }
    /*
        printf("\n Where do u want to delete.....beg(1),end(2),pos(3): ");
        scanf("%d",&a);
        if(a==1)
            head=del_beg(head);
        if(a==2)
            head=del_end(head);
        if(a==3)
            head=del_pos(head,n);
        else
            printf("Invalid option");
        */

    printf("\nWhere do u want to enter.....beg(1),end(2),pos(3): ");
    scanf("%d",&a);
    if(a==1)
        head=add_beg(head);
    else if(a==2)
        head=add_end(head);
    else if(a==3)
        head=add_pos(head,n);
    else
        printf("Enter valid option");



    printf("List is ");
    print(head);
    return 0;
}

struct node * add_nodes(struct node * head) {
    struct node * nn = create_node();
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
    struct node * nn=create_node();
    nn->next = head;
    head = nn;
    return head;
}

struct node * add_end(struct node *head) {
    struct node * nn =create_node();

    struct node * ptr =head;
    while(ptr->next!= NULL) {
        ptr=ptr->next;
    }
    ptr->next=nn;
    nn->next=NULL;
    return head;
}

struct node * add_pos(struct node * head,int n) {
    struct node * nn=create_node();
    struct node * ptr=head;
    int pos,i=1;
    printf("Enter position <%d:  ",n+1);
    scanf("%d",&pos);
    while (i<pos-1) {
        ptr=ptr->next;
        i++;
    }
    nn->next=ptr->next;
    ptr->next=nn;
    return head;
}

struct node * create_node() {
    struct node * nn=(struct node *)malloc(sizeof(struct node));
    int data ;
    printf("Enter data: ");
    scanf("%d",&data);
    nn->data=data;
    nn->next=NULL;
    return nn;
}
/*

struct node * del_beg(struct node * head) {
    struct node *ptr=head;
    head=ptr->next;
    free (ptr);
    return head;

}

struct node * del_end(struct node * head) {
    struct node * preptr, * ptr=head;
    while (ptr->next!=NULL ) {
        preptr=ptr;
        ptr=ptr->next;
    }
    preptr->next=NULL;
    free(ptr);
    return head;
}

struct node * del_pos(struct node * head,int n) {
    struct node *preptr, *ptr=head;
    int pos,i=1;
    printf("Enter position <%d: ",n+1);
    scanf("%d",&pos);
    while(i<=pos-1) {
        preptr=ptr;
        ptr=ptr->next;
        i++;
    }
    preptr->next=ptr->next;
    free(ptr);
    return head;

}
*/