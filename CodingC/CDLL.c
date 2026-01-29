#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prv;
    struct node *next;
};

struct node *create_node();
void print(struct node *tail);
struct node *add_nodes(struct node *tail);
/*
struct node *del_beg(struct node *tail);
struct node *del_end(struct node *tail);
struct node *del_pos(struct node *tail, int n);
*/
struct node * add_beg(struct node * tail);
struct node * add_end(struct node * tail);
struct node * add_pos(struct node * tail, int n);

int main() {
    struct node *tail = NULL;
    int i, n, a;

    printf("How many nodes are you going to enter: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        tail = add_nodes(tail);
    }
    /*
    printf("Where do you want to delete....beg(1), end(2), pos(3): ");
    scanf("%d", &a);

    if (a == 1)
        tail = del_beg(tail);
    else if (a == 2)
        tail = del_end(tail);
    else if (a == 3)
        tail = del_pos(tail, n);
    else
        printf("Invalid option");
    */    
    
    printf("Where do you want to enter....beg(1), end(2), pos(3): ");
    scanf("%d", &a);
    
    if (a == 1)
        tail = add_beg(tail);
    else if (a == 2)
        tail = add_end(tail);
    else if (a == 3)
        tail = add_pos(tail, n);
    else
        printf("Enter a valid option.\n");

    printf("List is: ");
    print(tail);

    return 0;
}

struct node *create_node() {
    struct node *nn = (struct node *)malloc(sizeof(struct node));
    int data;

    printf("Enter data: ");
    scanf("%d", &data);

    nn->data = data;
    nn->next = nn;
    nn->prv = nn;

    return nn;
}

struct node *add_nodes(struct node *tail) {
    struct node *nn = create_node();

    if (tail == NULL) {
        tail = nn;
    } else {
        nn->prv = tail;
        nn->next = tail->next;    // New node points to the first node
        tail->next->prv = nn;     // First node points back to the new node
        tail->next = nn;          // Tail points to the new node
        tail = nn;                // Update the tail to the new node
    }

    return tail;
}

void print(struct node *tail) {
    if (tail == NULL) {
        printf("List is empty\n");
        return;
    }

    struct node *ptr = tail->next; // Start from the first node
    do {
        printf("%d->", ptr->data);
        ptr = ptr->next;
    } while (ptr != tail->next);   // Stop when back to the first node
    printf("(circular)\n");
}

/*
struct node *del_beg(struct node *tail) {
    if (tail == NULL) {
        printf("List is empty\n");
        return NULL;
    }

    struct node *head = tail->next;

    if (head == tail) {  // Only one node in the list
        free(head);
        return NULL;
    }

    tail->next = head->next;       // Tail points to the second node
    head->next->prv = tail;        // Second node points back to the tail
    free(head);

    return tail;
}

struct node *del_end(struct node *tail) {
    if (tail == NULL) {
        printf("List is empty\n");
        return NULL;
    }

    struct node *head = tail->next;

    if (head == tail) {  // Only one node in the list
        free(tail);
        return NULL;
    }

    tail->prv->next = head;   // Second last node points to the first node
    head->prv = tail->prv;    // First node points back to the second last node
    free(tail);
    tail = tail->prv;         // Update tail to the second last node
    return tail;
}

struct node *del_pos(struct node *tail, int n) {
    if (tail == NULL) {
        printf("List is empty\n");
        return NULL;
    }

    int pos, i = 1;
    struct node *ptr = tail->next;

    printf("Enter position (1 to %d): ", n);
    scanf("%d", &pos);

    if (pos == 1) {
        return del_beg(tail);
    }

    while (i < pos && ptr != tail) {
        ptr = ptr->next;
        i++;
    }

    if (i != pos) {
        printf("Invalid position\n");
        return tail;
    }

    ptr->prv->next = ptr->next;  // Bypass the node to be deleted
    ptr->next->prv = ptr->prv;   // Adjust previous node's next and next node's prev
    if (ptr == tail) {
        tail = ptr->prv;  // Update tail if the last node is being deleted
    }

    free(ptr);

    return tail;
}
*/
struct node * add_beg(struct node * tail) {
    struct node *nn = create_node();

    if (tail == NULL) {
        tail = nn;
    } else {
        nn->next = tail->next;     // nn points to the first node
        nn->prv = tail;            // nn points back to tail
        tail->next->prv = nn;      // The first node's previous points to nn
        tail->next = nn;           // Tail's next points to nn
    }

    return tail;
}

struct node * add_end(struct node * tail) {
    return add_nodes(tail); // Add at end is the same as general add_nodes in a circular list
}

struct node * add_pos(struct node * tail, int n) {
    if (tail == NULL) {
        printf("List is empty.\n");
        return NULL;
    }

    struct node *nn = create_node();
    struct node *ptr = tail->next;
    int pos, i = 1;
    
    printf("Enter position (1 to %d): ", n);
    scanf("%d", &pos);

    if (pos == 1) {
        return add_beg(tail);  // If position is 1, it's the same as adding at the beginning
    }

    while (i < pos - 1 && ptr != tail) {
        ptr = ptr->next;
        i++;
    }

    if (i != pos - 1) {
        printf("Invalid position.\n");
        return tail;
    }

    nn->next = ptr->next;      // nn points to the next node
    nn->prv = ptr;             // nn points back to the current node
    ptr->next->prv = nn;       // The next node's previous points to nn
    ptr->next = nn;            // Current node points to nn

    if (ptr == tail) {
        tail = nn; // Update tail if we insert at the end
    }

    return tail;
}