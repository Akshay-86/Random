#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void push1(int);
void push2(int);
int pop1();
int pop2();
void display();
#define max 20
int stack1[max],stack2[max];
int top1==-1,top2==-1;
void sort();
void main() {
    push1(2);
    push1(1);
    push1(6);
    push1(5);
    push1(7);
    display();
}
void sort() {
    int temp;
    while(top1!=-1) {
        temp=pop1();
        while (top2!=-1&&stack2[top]>temp) {
            push1(pop1());
            push(temp);
        }
    }
}
void display(){
printf("\n");
for(int i = top1;i>=0;i--)
  printf("%d",stack1[i]);
}
void push1(int data){
 if(top1==max-1){
 printf("overflow");
 break;
 }
 else
  stack1[++top]=data;
}
void push2(int data){
if(top2==)
}