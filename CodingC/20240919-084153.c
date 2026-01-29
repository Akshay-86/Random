#include"stdio.h"
#include"conio.h"
#include"stdlib.h"
#include"ctype.h"
#include"string.h"
#define max 100
int top=-1;
char stack[max];
void push(char item)
{
if(top>=max-1)
{
printf("overflow");}
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
printf("underflow");
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
if(symbol=='^'||symbol=='+'||symbol=='-'||symbol=='*'||symbol=='/')
{
return 1;
}
else
return 0;
}
int precedence(char symbol)
{
if(symbol=='^')
return 3;
else if(symbol=='*'||symbol=='/')
return 2;
else if(symbol=='-'||symbol=='+')
return 1;
else 
return 0;
}
void infixtopostfix(char infix[],char postfix[])
{
int i,j;
char exp;
char val;
push('(');
strcat(infix,")");
i=0;
j=0;
exp=infix[i];
while(exp!='\0')
{
if(exp=='(')
push(exp);
else if(isdigit(exp)||isalpha(exp))
{
postfix[j]=exp;
j++;
}
else if(is_operator(exp)==1)
{
val=pop();
while(is_operator(val)==1&&precedence(val)>=precedence(exp))
{
postfix[j]=val;
j++;
val=pop();
}
push(val);
push(exp);
}
else if (exp==')')
{
val=pop();
while(val!='(')
{
postfix[j]=val;
j++;
val=pop();
}

}
else
{
printf("invalid expression");
getchar();
exit(1);
}
i++;
exp=infix[i];
}
postfix[j]='\0';
}

int main()
{
char infix[max],postfix[max];
printf("enter infix expression");
scanf("%s",infix);
infixtopostfix(infix,postfix);
printf("%s",postfix);
getch();
return 0;
}
