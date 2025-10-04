#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

// Stack implementation
char stack[MAX];
int top = -1;

void push(char c) {
    if (top == MAX - 1)
        printf("Stack Overflow\n");
    else
        stack[++top] = c;
}

char pop() {
    if (top == -1)
        return -1;
    else
        return stack[top--];
}

char peek() {
    if (top == -1)
        return -1;
    return stack[top];
}

// Function to check precedence
int precedence(char op) {
    switch (op) {
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2;
        case '^': return 3;
        default:  return 0;
    }
}

// Function to check if character is operator
int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// Reverse a string
void reverse(char *exp) {
    int len = strlen(exp);
    for (int i = 0; i < len / 2; i++) {
        char temp = exp[i];
        exp[i] = exp[len - i - 1];
        exp[len - i - 1] = temp;
    }
}

// Infix to Postfix Conversion
void infixToPostfix(char infix[], char postfix[]) {
    int i = 0, j = 0;
    char c;

    while ((c = infix[i++]) != '\0') {
        if (isalnum(c)) {
            postfix[j++] = c;
        } else if (c == '(') {
            push(c);
        } else if (c == ')') {
            while (top != -1 && peek() != '(')
                postfix[j++] = pop();
            pop(); // remove '('
        } else if (isOperator(c)) {
            while (top != -1 && precedence(peek()) >= precedence(c))
                postfix[j++] = pop();
            push(c);
        }
    }

    while (top != -1)
        postfix[j++] = pop();

    postfix[j] = '\0';
}

// Main function: Infix to Prefix
void infixToPrefix(char infix[], char prefix[]) {
    char revInfix[MAX], revPostfix[MAX];

    strcpy(revInfix, infix);
    reverse(revInfix);

    // Swap '(' and ')'
    for (int i = 0; revInfix[i]; i++) {
        if (revInfix[i] == '(')
            revInfix[i] = ')';
        else if (revInfix[i] == ')')
            revInfix[i] = '(';
    }

    infixToPostfix(revInfix, revPostfix);
    reverse(revPostfix);
    strcpy(prefix, revPostfix);
}

// Driver Code
int main() {
    char infix[MAX], prefix[MAX];

    printf("Enter Infix Expression: ");
    scanf("%s", infix);

    infixToPrefix(infix, prefix);

    printf("Prefix Expression: %s\n", prefix);

    return 0;
}
