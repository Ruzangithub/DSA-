//Implement a stack using an array and write functions to perform push and pop operations
#include<stdio.h>
#include<stdlib.h>

#define Max_S 100

typedef struct
{
    int st[Max_S];
    int tp; 
} stk;

void ini_S(stk *s)
{
    s->tp =-1;
}

void push(stk *s,int x)
{
    if(s->tp == Max_S)
    {
        printf("Stack Overflow\n");
    }
    else
    {
    s->tp++;
    s->st[s->tp] = x;
    printf("Pushed element %d onto the stack.\n",x);
    }
}

int pop(stk *s)
{
    if(s->tp == -1)
    {
        printf("Stack Underflow\n");
        return -1;
    }
    else
    {
         int x= s->st[s->tp];
         s->tp--;
         printf("poped element from the stack \n");
         return x;
    }
}

int main()
{
    stk s;
    ini_S(&s);
    push(&s,10);
    push(&s,20);
    push(&s,30);

    int Poped_E = pop(&s);
    if(Poped_E != -1)
    {
        printf("Popped element: %d\n",Poped_E);
    }

    return 0;
}
