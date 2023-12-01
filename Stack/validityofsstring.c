#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<strings.h>
#define stacksize 100
struct stack
{
    int top;
    char items[stacksize];
};
bool empty(struct stack *s)
{
    if(s->top==-1)
    return true;
    else 
    return false;
}
char pop(struct stack *s)
{
    if(empty(s))
    {
        printf("Empty stack");
    }
    else
    {
        return s->items[s->top--];
    }
}
void push(struct stack *s,char x)
{
    if(s->top==stacksize-1)
    {
        printf("Stack overflow");
    }
    else{
        s->items[++s->top]=x;
    }
}
void val(char a[])
{
    char k;
    struct stack *s;
    s=malloc(sizeof(struct stack));
    s->top=-1;
    bool valid=true;
    int i=0;
    while(a[i]!='\0')
    {
        
        if(a[i]=='(' || a[i]=='{' || a[i]=='[')
        {
            push(s,a[i]);
        }
       
        if(a[i]==')'||a[i]=='}'||a[i]==']')
        {
            if(empty(s))
            {
                valid=false;
            }
            
            
            
            else
          {
              k=pop(s);
            if(a[i]==')')
            {
                if(k!='(')
                {
                    valid=false;
                }
            }
            if(a[i]==']')
            {
                if(k!='[')
                {
                    valid=false;
                }
            }
            if(a[i]=='}')
            {
                if(k!='{')
                {
                    valid=false;
                }
            }
           
          }
        }
        i++;
    }
    if(!empty(s))
    {
        valid=false;
    }
    
    if(valid==false)
    {
        printf("String is invalid");
    }
    if(valid==true)
    {
        printf("String is valid");
    }
}

int main()
{
    struct stack *ps;
    ps=malloc(sizeof(struct stack));
    ps->top=-1;
   char a[stacksize];
   gets(a);
   val(a);
    return 0;
}