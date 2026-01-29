#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* delete_end(struct node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return head; 
    }

    struct node* ptr = head;
    struct node* prev = NULL;

    while (ptr->next != NULL) {
        prev = ptr;
        ptr = ptr->next;
    }

    if (prev == NULL) { 
        free(head);
        return NULL;
    } else {
        prev->next = NULL;
        free(ptr);
        return head;
    }
}

int main() {
    struct node* head = (struct node*)malloc(sizeof(struct node));
    head->data = 45;
    head->next = NULL;

    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    ptr->data = 98;
    ptr->next = NULL;

    head->next = ptr;

    head = delete_end(head);

    ptr = head;
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }

    return 0;
}
