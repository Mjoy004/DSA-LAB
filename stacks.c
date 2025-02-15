#include <stdio.h>
#define MAX 5  // Maximum size of stack

int stack[MAX], top = -1;

// Function to check if the stack is full
int isFull() {
    return (top == MAX - 1);
}

// Function to check if the stack is empty
int isEmpty() {
    return (top == -1);
}

// Function to push an element onto the stack
void push(int value) {
    if (isFull()) {
        printf("Stack Overflow! Cannot push %d\n", value);
        return;
    }
    stack[++top] = value;
    printf("%d pushed into stack\n", value);
}

// Function to pop an element from the stack
int pop() {
    if (isEmpty()) {
        printf("Stack Underflow! Cannot pop\n");
        return -1;
    }
    return stack[top--];
}

// Function to peek the top element of the stack
int peek() {
    if (isEmpty()) {
        printf("Stack is empty\n");
        return -1;
    }
    return stack[top];
}

// Function to display the stack
void display() {
    if (isEmpty()) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = top; i >= 0; i--)
        printf("%d ", stack[i]);
    printf("\n");
}

int main() {
    push(10);
    push(20);
    push(30);
    display();
    
    printf("Popped element: %d\n", pop());
    display();

    printf("Top element: %d\n", peek());

    return 0;
}
