#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct node {
    struct node * prv ;
    int data;
    struct node * nxt;
}*ptr;
struct node * add_at_empty(struct node * tail);

main() {
    struct node * tail = (struct node *)malloc(sizeof(struct node));
    tail=add_at_empty(tail);
    tail=add_at_beg(tail);
    print(tail);
    getch();
}

struct node * add_at_empty(struct node * tail) {
    struct node * nn = (struct node *)malloc(sizeof(struct node));
    nn->nxt=nn;
    nn->prv=nn;
    nn->data=86;
    tail=nn;
    return (nn);
}

struct node * add_at_beg(struct node * tail) {
    struct node * nn = (struct node *)malloc(sizeof(struct node));
    nn->data=106;
    tail->nxt=nn;
    nn->prv=tail;
    tail->prv=nn;
    nn->nxt=tail;
    return (tail);
}

void print(struct node * tail) {
    if(tail==NULL)
        printf("List is empty");
    else {
        ptr=tail;
        while(ptr->nxt!=tail->) {
            printf("%d",ptr->data);
            ptr=ptr->nxt;
        }
    }

}