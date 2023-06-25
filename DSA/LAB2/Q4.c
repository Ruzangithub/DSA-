//Write a program to convert an infix expression to prefix using a stack.
#include<stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_SIZE 100

int Empty(int top) 
{
    return top == -1;
}

void push(char stack[], int* top, char item) 
{
    stack[++(*top)] = item;
}

char pop(char stack[], int* top) 
{
    if (Empty(*top)) 
    {
        printf("Stack Underflow\n");
        return '\0';
    }
    return stack[(*top)--];
}


