#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define max 100
char stack[max];
int top=-1;
void push(char item)
{
    if(top>=max-1)
        printf("\n overflow");
    else
    {
        top++;
        stack[top]=item;
    }
}
char pop()
{
    char item;
    if(top<0)
    {
        printf("\n underflow");
        getchar();
        exit(1);
    }
    else
    {
        item=stack[top];
        top--;
    }
    return item;
}
int is_operator(char symbol)
{
    if(symbol=='^'||symbol=='*'||symbol=='/'||symbol=='+'||symbol=='-')
        return 1;
    else
        return 0;
}

int intopost(char *exp)
{
    int i=0;
    char symbol=exp[i];
   int a,b,res;
    while(symbol!='\0')
    {
        if(symbol>='0'&&symbol<='9')
        {
        int num=symbol-'0';
            push(num);
        }
        else if(is_operator(symbol) ==1)
        {
            b=pop();
            a=pop();
            switch(symbol)
            {
            case '+':res=a+b;break;
            case '-':res=a-b ;break;
            case '*':res=a*b; break;
            case '/':res=a/b;break;
            case '^':res=a^b;break;
            default:printf("enter valid symbol ");
            }
            push(res);
            }
            i++;
            symbol=exp[i];
            }
            
            res=pop();
            return res;
            }
        
int main()
{
    char postfix[max];
    clrscr();
    printf("enter postfix expression");
    scanf("%s",postfix);
   int result= intopost(postfix) ;
    printf("result=%d",result);
    getch();
    return 0;
}