#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>
#define stacksize 100
struct stack{
    int top;
    float items[stacksize];
    };
bool empty(struct stack *ps)
{
    if(ps->top==-1)
    return true;
    else
    return false;
}
float pop(struct stack *ps)
{
    if(empty(ps))
    {
        printf("POP CANNOT BE EXECUTED!! STACK UNDERFLOW!!!!\n");
        exit(1);
    }
    else
    return ps->items[ps->top--];
}
void push(struct stack *s, float x)
{
    if(s->top==stacksize-1)
    {printf("STACK OVERFLOW!!!");}
    else
    s->items[++s->top]=x;
}
float eval(float op1, float op2, char op)
{
    switch(op)
    {
    case '+':return op1+op2;
    case '-':return op1-op2;
    case '*':return op1*op2;
    case '/':return op1/op2;
    case '$':return (pow(op1,op2));
    

    }
}

float postfix(char a[])
{float op1,op2,value;

struct stack *opndstk;
opndstk=malloc(sizeof(struct stack));
opndstk->top=-1;
int i=0;
while(a[i]!='\0')
{
    if(a[i]>=48 && a[i]<=57)
    {   
    

        push(opndstk,(float)(a[i]-'0'));
    }
    if(a[i]=='+'||a[i]=='-'||a[i]=='*'||a[i]=='/'||a[i]=='$')
    {
    op2=pop(opndstk);
    op1=pop(opndstk);
    
    
   
    value=eval(op1,op2,a[i]);
   
    push(opndstk,value);
    }
    
    i++;
}

return (pop(opndstk));
}
int main()
{
    char str[stacksize];
    gets(str);
    printf("%f",postfix(str));
   
   
    return 0;
}
/*This program can evaluate a postfix expression but however it cannot check the validity of the expression.
Also this program fails if the user is unaware the it only takes single digit as input.
This program also doesn't work with negative integers.*/