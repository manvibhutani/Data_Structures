#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define stacksize 100
struct stack{
    int top;
    int items[stacksize];
};
bool empty(struct stack *s)
{
    if(s->top==-1)
    return true;
    else
    return false;
}
int pop(struct stack *s)
{
    if(empty(s))
    {
        printf("Stack underflow!! Cannot execute pop operation!");
        exit(1);
    }
    else
    {
        
        return s->items[s->top--];
        
    }

}
int stacktop(struct stack *s)
{
    if(empty(s))
    printf("Stack Underflow!!");
    return s->items[s->top];
}
int push(struct stack *s, int x)
{
   return s->items[++(s->top)]=x;

}

int main()
{
    struct stack *ps;
    ps=malloc(sizeof(struct stack));
    ps->top=-1;
    printf("%d\n", empty(ps));
    push(ps,9);
    push(ps,7);
    push(ps,0);
    printf("%d\n", stacktop(ps));
    pop(ps);
    printf("%d\n", stacktop(ps));
    pop(ps);
    printf("%d\n", stacktop(ps));
    pop(ps);
    printf("%d\n", stacktop(ps));
    pop(ps);
    return 0;
}