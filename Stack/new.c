#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
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
int main()
{

    printf("%d\n",prcd('$','$'));
    printf("%d\n",prcd('$','*'));
    printf("%d\n",prcd('$','/'));
    printf("%d\n",prcd('$','+'));
    printf("%d\n",prcd('$','-'));
    printf("%d\n",prcd('*','$'));
    printf("%d\n",prcd('*','*'));
    printf("%d\n",prcd('*','/'));
    printf("%d\n",prcd('*','+'));
    printf("%d\n",prcd('*','-'));
    printf("%d\n",prcd('/','$'));
    printf("%d\n",prcd('/','*'));
    printf("%d\n",prcd('/','/'));
    printf("%d\n",prcd('/','+'));
    printf("%d\n",prcd('/','-'));
    printf("%d\n",prcd('+','$'));
    printf("%d\n",prcd('+','*'));
    printf("%d\n",prcd('+','/'));
    printf("%d\n",prcd('+','+'));
    printf("%d\n",prcd('+','-'));
    printf("%d\n",prcd('-','$'));
    printf("%d\n",prcd('-','*'));
    printf("%d\n",prcd('-','/'));
    printf("%d\n",prcd('-','+'));
    printf("%d\n",prcd('-','-'));
}