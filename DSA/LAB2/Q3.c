#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_SIZE 100

int Empty(int top) {
    return top == -1;
}

void push(char stack[], int* top, char item) {
    stack[++(*top)] = item;
}

char pop(char stack[], int* top) {
    if (Empty(*top)) {
        printf("Stack Underflow\n");
        return '\0';
    }
    return stack[(*top)--];
}

void infToPof(char infix[], char postfix[]) {
    char stack[MAX_SIZE];
    int top = -1;
    int i, j = 0;

    for (i = 0; infix[i] != '\0'; i++) {
        char ch = infix[i];

        if (isalpha(ch) || isdigit(ch))
            postfix[j++] = ch;
        else if (ch == '(')
            push(stack, &top, ch);
        else if (ch == ')') {
            while (!Empty(top) && stack[top] != '(')
                postfix[j++] = pop(stack, &top);
            if (!Empty(top) && stack[top] != '(') {
                printf("Invalid expression\n");
                return;
            } else {
                pop(stack, &top);
            }
        } else {
            while (!Empty(top) && stack[top] != '(' && (ch == '+' || ch == '-' || ch == '*' || ch == '/')) {
                postfix[j++] = pop(stack, &top);
            }
            push(stack, &top, ch);
        }
    }

    while (!Empty(top)) {
        if (stack[top] == '(') {
            printf("Invalid expression\n");
            return;
        }
        postfix[j++] = pop(stack, &top);
    }

    postfix[j] = '\0';
}

int main() {
    char infix[MAX_SIZE];
    char postfix[MAX_SIZE];

    printf("Enter an infix expression: ");
    fgets(infix, sizeof(infix), stdin);

    infToPof(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
