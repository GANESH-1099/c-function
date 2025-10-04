#include <stdio.h>
#include <stdlib.h>

#define MAX 32  // Maximum number of bits for a 32-bit integer

// Stack structure
typedef struct {
    int items[MAX];
    int top;
} Stack;

// Function to initialize stack
void initialize(Stack* s) {
    s->top = -1;
}

// Check if stack is full
int isFull(Stack* s) {
    return s->top == MAX - 1;
}

// Check if stack is empty
int isEmpty(Stack* s) {
    return s->top == -1;
}

// Push operation
void push(Stack* s, int value) {
    if (isFull(s)) {
        printf("Stack overflow!\n");
        exit(1);
    }
    s->items[++(s->top)] = value;
}

// Pop operation
int pop(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack underflow!\n");
        exit(1);
    }
    return s->items[(s->top)--];
}

// Function to convert integer to binary using stack
void convertToBinary(int num) {
    Stack s;
    initialize(&s);

    if (num == 0) {
        printf("Binary: 0\n");
        return;
    }

    // Push remainders to stack
    while (num > 0) {
        int remainder = num % 2;
        push(&s, remainder);
        num /= 2;
    }

    // Pop and print the binary number
    printf("Binary: ");
    while (!isEmpty(&s)) {
        printf("%d", pop(&s));
    }
    printf("\n");
}

// Main function
int main() {
    int number;

    printf("Enter an integer: ");
    scanf("%d", &number);

    convertToBinary(number);

    return 0;
}
