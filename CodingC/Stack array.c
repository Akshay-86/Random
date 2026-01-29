#include<stdio.h>
#include<stdlib.h>
#define max 4
int stack[max];
int top=-1;
void push(int data) {
    if(top==max-1) {
        printf("overflow");
return;
    }
    top=top+1;
    stack[top]=data;
}
int pop() {
    int value;
    if(top==-1) {
        printf("under flow");
        return -1; 
    }
    value=stack[top];
    top=top-1;
    
return value;
}
void display () {
    int i;
    if (top==-1)
        printf("under flow");
    printf("Stack is : ");
    for(i=top;i>=0;i--)
        printf("%d ",stack[i]);
    printf("\n");
}

int main() {
    int data;

    push(10);
    push(20);
    push(30);
    push(40);

    display();

    data=pop();
    printf("poped element is: %d\n",data);

    data=pop();
    printf("poped element is: %d\n",data);
    display();
    return 0;
}
