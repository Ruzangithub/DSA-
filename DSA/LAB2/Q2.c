#include <stdio.h>

#define MAX_SIZE 100

typedef struct {
    int arr[MAX_SIZE];
    int top;
} Stack;

void initStack(Stack *s) {
    s->top = -1;
}

int isEmpty(Stack *s) {
    return (s->top == -1);
}

int isFull(Stack *s) {
    return (s->top == MAX_SIZE - 1);
}

void push(Stack *s, int v) {
    if (isFull(s)) {
        printf("Stack Overflow: Cannot push element %d, stack is full.\n", v);
        return;
    }

    s->top++;
    s->arr[s->top] = v;
    printf("Pushed element %d onto the stack.\n", v);
}

int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow: Cannot pop element, stack is empty.\n");
        return -1; 
    }

    int value = s->arr[s->top];
    s->top--;
    printf("Popped element.\n");
    return value;
}

int main() {
    Stack s;
    initStack(&s);

    int choice, value;
    while (1) {
        printf("\nStack Operations:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to push: ");
                scanf("%d", &value);
                push(&s, value);
                break;
            case 2:
                pop(&s);
                break;
            case 3:
                printf("Quitting the program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
