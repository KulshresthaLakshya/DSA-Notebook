#include<stdio.h>
#define MAX 8

int stack[MAX];
int top = -1;

void push(int val) {
    if (top == MAX - 1) {
        printf("stack is overflow \n");
        return;
    }
    stack[++top] = val;
    printf("pushed %d into stack\n", val);
}

void pop() {
    if (top == -1) {
        printf("stack is underflow\n");
        return;
    }
    printf("popped element: %d\n", stack[top]);
    top--;
}

void peek() {
    if (top == -1) {
        printf("stack is empty\n");
        return;
    }
    printf("top element: %d\n", stack[top]);
}

void display() {
    if (top == -1) {
        printf("stack is empty\n");
        return;
    }
    printf("stack elements: \n");
    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    int choice, val;
    while (1) {
        printf("\nSTACK USING ARRAY\n");
        printf("1. PUSH\n2. POP\n3. peek\n4. DISPLAY\n5. EXIT\n");
        printf("enter choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("enter value: ");
                scanf("%d", &val);
                push(val);
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                return 0;
            default:
                printf("invalid choice\n");
        }
    }
}