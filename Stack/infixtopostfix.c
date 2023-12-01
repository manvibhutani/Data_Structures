#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#define stacksize 100
struct stack{
    int top;
    char items[stacksize];
};
bool empty(struct stack *ps)
{
    if(ps->top==-1)
    return true;
    else
    return false;
}
void push(struct stack *ps, char x)
{
    if(ps->top==stacksize-1)
    {
        printf("STACKOVERFLOW!!PUSH OPERATION CANNOT BE EXECUTED");
        exit(1);
    }
    else
    ps->items[++ps->top]=x;
}
char pop(struct stack *ps)
{
    if(ps->top==-1)
    {
        printf("STACK UNDERFLOW!! CANNOT EXECUTE POP!!");
        exit(1);
    }
    else
    {
        return ps->items[ps->top--];
    }
}
char stacktop(struct stack *ps)
{
    if(empty(ps))
    {
       
    }
    else
    return ps->items[ps->top];
}
int prcd(char op1, char op2)
{int k=0;
if(op1=='$')
k=1;
if(op1=='*'|| op1=='/')
{
    if(op2=='$')
    k=0;
    else
    k=1;
}
if(op1=='+'||op1=='-')
{
    if(op2!='+'||op2!='-')
    {
        k=0;
    }
    if(op2=='+'||op2=='-')
    k=1;
}
return k;
}
void infixtopostfix(char a[])
{int i=0,j=0;
char symb;
char str[strlen(a)];
struct stack *s;
s=malloc(sizeof(struct stack));
s->top=-1;

    while(a[i]!='\0')
    {
        if(a[i]>=48 && a[i]<=57)
        {
            str[j]=a[i];
            j++;
        }
        else
        {
            while(prcd(stacktop(s),a[i]) && !empty(s))
            {
                str[j]=pop(s);
                j++;
            }
            push(s,a[i]);
        }
        
        i++;
    }
    while(!empty(s))
        {
            str[j]=pop(s);
            j++;
        }
        
        for(int k=0; k<strlen(a);k++)
        {
            printf("%c",str[k]);
        }
}
int main()
{
    char string[stacksize];
    gets(string);
    infixtopostfix(string);
    return 0;
}