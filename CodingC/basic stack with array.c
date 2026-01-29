#include<stdio.h>
#include<stdlib.h>
#define MAX 4
void print();

int stack[MAX];
int top=-1;

void push(int data) {
    if(top==MAX-1) {
        printf("Stack is overflow");
        return;
    }
    top=top+1;
    stack[top]=data;
}

int pop() {
    int value;
    if(top==-1) {
        printf("stact is under flow");
        return -1;
    }
    value=stack[top];
    top=top-1;
    return value;
}

int main() {
    int data;
    push(10);
    push(20);
    push(30);
    push(40);
    data=pop();
    data=pop();
    print();
    return 0;
}

void print() {
    int i;
    if(top==-1) {
        printf("stack is under flow");
        return;
    }
    for(i=top; i>=0; i--) {
        printf("%d",stack[i]);
        printf("\n");
    }
}