#include <stdio.h>

int push(int stack[], int top, int maxSize) {
    if (top == maxSize - 1) {
        printf("Stack Overflow\n");
    } else {
        int value;
        printf("Enter value to push: ");
        scanf("%d", &value);
        top++;
        stack[top] = value;
        printf("Value pushed successfully\n");
    }
    return top;
}

int pop(int stack[], int top) {
    if (top == -1) {
        printf("Stack Underflow\n");
    } else {
        printf("Popped value: %d\n", stack[top]);
        top--;
    }
    return top;
}

void peek(int stack[], int top) {
    if (top == -1) {
        printf("Stack is empty\n");
    } else {
        printf("Top value: %d\n", stack[top]);
    }
}

void display(int stack[], int top) {
    if (top == -1) {
        printf("Stack is empty\n");
    } else {
        printf("Stack elements:\n");
        for (int i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}

int main() {
    int stack[100];
    int top = -1;
    int maxSize;
    int choice;

    printf("Enter maximum size of stack: ");
    scanf("%d", &maxSize);

    while (1) {
        printf("\n1. PUSH\n2. POP\n3. PEEK\n4. DISPLAY\n5. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                top = push(stack, top, maxSize);
                break;
            case 2:
                top = pop(stack, top);
                break;
            case 3:
                peek(stack, top);
                break;
            case 4:
                display(stack, top);
                break;
            case 5:
                printf("Program ended.\n");
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}

