#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

// Stack for operators
char stack[MAX];
int top = -1;

// Function prototypes
void push(char c);
char pop();
char peek();
int precedence(char op);
void infixToPostfix(char* infix, char* postfix);

int main() {
    char infix[MAX], postfix[MAX];
    
    printf("Enter infix expression: ");
    fgets(infix, sizeof(infix), stdin);
    
    // Remove newline character if present
    infix[strcspn(infix, "\n")] = '\0';
    
    infixToPostfix(infix, postfix);
    
    printf("Postfix expression: %s\n", postfix);
    
    return 0;
}

// Push function for stack
void push(char c) {
    if (top < (MAX - 1)) {
        stack[++top] = c;
    } else {
        printf("Stack overflow\n");
        exit(1); // Terminate the program due to stack overflow
    }
}

// Pop function for stack
char pop() {
    if (top >= 0) {
        return stack[top--];
    } else {
        printf("Stack underflow\n");
        exit(1); // Terminate the program due to stack underflow
    }
}

// Peek function for stack
char peek() {
    if (top >= 0) {
        return stack[top];
    } else {
        return '\0'; // Return null character if stack is empty
    }
}

// Function to get the precedence of operators
int precedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

// Function to convert infix expression to postfix
void infixToPostfix(char* infix, char* postfix) {
    int i = 0, k = 0;
    
    while (infix[i] != '\0') {
        if (isdigit(infix[i]) || isalpha(infix[i])) {
            postfix[k++] = infix[i];
        } else if (infix[i] == '(') {
            push(infix[i]);
        } else if (infix[i] == ')') {
            while (top >= 0 && peek() != '(') {
                postfix[k++] = pop();
            }
            pop(); // Remove '(' from stack
        } else {
            while (top >= 0 && precedence(peek()) >= precedence(infix[i])) {
                postfix[k++] = pop();
            }
            push(infix[i]);
        }
        i++;
    }
    
    // Pop all remaining operators from the stack
    while (top >= 0) {
        postfix[k++] = pop();
    }
    postfix[k] = '\0'; // Null-terminate the postfix expression
}

