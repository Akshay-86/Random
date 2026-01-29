#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node * next;
};

struct node * add_nodes(struct node * tail);
struct node * create_node();
void print(struct node * tail);
/*
struct node * add_beg(struct node * tail);
struct node * add_end(struct node * tail);
struct node * add_pos(struct node * tail, int n);
*/

struct node * del_beg(struct node * tail);
struct node * del_end(struct node * tail);
struct node * del_pos(struct node * tail, int n);

int main() {
    struct node * tail = NULL;
    int i, n, a;
    printf("How many nodes are you going to enter: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        tail = add_nodes(tail);
    }
    /*
    printf("\nWhere do you want to enter.....beg(1), end(2), pos(3): ");
    scanf("%d", &a);
    if (a == 1)
        tail = add_beg(tail);
    else if (a == 2)
        tail = add_end(tail);
    else if (a == 3)
        tail = add_pos(tail, n);
    else
        printf("Enter valid option");
    */
    
    printf("\nWhere do you want to delete.....beg(1), end(2), pos(3): ");
    scanf("%d", &a);
    
    if (a == 1)
        tail = del_beg(tail);
    else if (a == 2)
        tail = del_end(tail);
    else if (a == 3)
        tail = del_pos(tail, n);
    else
        printf("Invalid option");
    
    printf("List is: ");
    print(tail);
    return 0;
}

struct node * add_nodes(struct node * tail) {
    struct node * nn = create_node();
    if (tail == NULL) {
        tail = nn;
        nn->next = nn; // First node points to itself to form a circular link
    } else {
        nn->next = tail->next; // New node points to the first node
        tail->next = nn;       // Old tail points to the new node
        tail = nn;             // Update the tail to the new node
    }
    return tail;
}

void print(struct node * tail) {
    if (tail == NULL) {
        printf("List is empty\n");
        return;
    }

    struct node * ptr = tail->next; // Start from the first node
    do {
        printf("%d->", ptr->data);
        ptr = ptr->next;
    } while (ptr != tail->next); // Loop until we reach the first node again

    printf("(circular)\n");
}
/*
struct node * add_beg(struct node * tail) {
    struct node * nn = create_node();
    if (tail == NULL) {
        tail = nn;
        nn->next = nn; // First node points to itself
    } else {
        nn->next = tail->next; // New node points to the first node
        tail->next = nn;       // Tail points to the new node
    }
    return tail;
}

struct node * add_end(struct node * tail) {
    struct node * nn = create_node();
    if (tail == NULL) {
        tail = nn;
        nn->next = nn; // First node points to itself
    } else {
        nn->next = tail->next; // New node points to the first node
        tail->next = nn;       // Old tail points to the new node
        tail = nn;             // Update the tail to the new node
    }
    return tail;
}

struct node * add_pos(struct node * tail, int n) {
    struct node * nn = create_node();
    struct node * ptr = tail->next;
    int pos, i = 1;
    printf("Enter position (1 to %d):  ", n + 1);
    scanf("%d", &pos);

    if (pos == 1) { // If adding at the first position
        return add_beg(tail);
    }

    while (i < pos - 1 && ptr != tail) {
        ptr = ptr->next;
        i++;
    }
    nn->next = ptr->next;
    ptr->next = nn;

    if (ptr == tail) { // If added at the end, update the tail
        tail = nn;
    }
    return tail;
}
*/
struct node * create_node() {
    struct node * nn = (struct node *)malloc(sizeof(struct node));
    int data;
    printf("Enter data: ");
    scanf("%d", &data);
    nn->data = data;
    nn->next = NULL;
    return nn;
}

struct node * del_beg(struct node * tail) {
    if (tail == NULL) {
        printf("List is empty\n");
        return NULL;
    }

    struct node * head = tail->next;
    
    if (head == tail) {  // Only one node in the list
        free(head);
        return NULL;
    }

    tail->next = head->next;  // Tail points to the new first node
    free(head);

    return tail;
}

struct node * del_end(struct node * tail) {
    if (tail == NULL) {
        printf("List is empty\n");
        return NULL;
    }

    struct node * ptr = tail->next;
    
    if (ptr == tail) {  // Only one node in the list
        free(ptr);
        return NULL;
    }

    struct node * preptr = NULL;
    
    // Traverse to the second last node
    while (ptr->next != tail->next) {
        preptr = ptr;
        ptr = ptr->next;
    }
    
    preptr->next = tail->next;  // Second last node points to the first node
    free(tail);
    
    tail = preptr;  // Update tail to the second last node
    
    return tail;
}

struct node * del_pos(struct node * tail, int n) {
    if (tail == NULL) {
        printf("List is empty\n");
        return NULL;
    }

    int pos, i = 1;
    struct node * ptr = tail->next;
    struct node * preptr = NULL;
    
    printf("Enter position (1 to %d): ", n);
    scanf("%d", &pos);

    if (pos == 1) {
        return del_beg(tail);
    }

    while (i < pos && ptr != tail) {
        preptr = ptr;
        ptr = ptr->next;
        i++;
    }

    if (ptr == tail->next || i < pos) {
        printf("Invalid position\n");
        return tail;
    }

    preptr->next = ptr->next;  // Bypass the node to be deleted
    free(ptr);

    if (ptr == tail) {  // If the deleted node is the last one
        tail = preptr;
    }

    return tail;
}