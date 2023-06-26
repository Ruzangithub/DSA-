#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

int isEmpty(int top) 
{
    return top == -1;
}

void push(char stack[], int* top, char item) 
{
    stack[++(*top)] = item;
}

char pop(char stack[], int* top) 
{
    if (isEmpty(*top)) 
    {
        printf("Stack Underflow\n");
        return '\0';
    }
    return stack[(*top)--];
}


int isOperand(char ch) 
{
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'); //check if the char is a operand or not
}

int getPrecedence(char op) 
{
    switch (op) 
    {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
    }
    return -1;
}

void infixToPrefix(char infix[], char prefix[]) 
{
    char stack[MAX_SIZE];
    int top = -1;
    int i, j = 0;
    int len = strlen(infix);

    for (i = len - 1; i >= 0; i--) 
    {
        char ch = infix[i];

        if (isOperand(ch))

            prefix[j++] = ch;

        else if (ch == '(') 
        {
            while (!isEmpty(top) && stack[top] != ')')
                prefix[j++] = pop(stack, &top);
            if (!isEmpty(top) && stack[top] != ')') {
                printf("Invalid expression\n");
                return;
            } 
            else 
            {
                pop(stack, &top);  // this removes ')' from the stack
            }
        } 
        else 
        {
            while (!isEmpty(top) && getPrecedence(ch) < getPrecedence(stack[top]))
                prefix[j++] = pop(stack, &top);
            push(stack, &top, ch);
        }
    }

    while (!isEmpty(top))

        prefix[j++] = pop(stack, &top);

    prefix[j] = '\0';

     //this here is used for reversing the prefix expression >_<
    strrev(prefix);
}

int main() 
{
    char infix[MAX_SIZE];
    char prefix[MAX_SIZE];

    printf("Enter an infix expression: ");
    fgets(infix, sizeof(infix), stdin);

    infixToPrefix(infix, prefix);

    printf("Prefix expression: %s\n", prefix);

    return 0;
}
