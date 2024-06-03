#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

// Define a structure for the stack
struct Stack {
    char items[MAX_SIZE];
    int top;
};

// Function to initialize the stack
void initialize(struct Stack *stack) {
    stack->top = -1;
}

// Function to check if the stack is empty
int isEmpty(struct Stack *stack) {
    return stack->top == -1;
}

// Function to check if the stack is full
int isFull(struct Stack *stack) {
    return stack->top == MAX_SIZE - 1;
}

// Function to push an element onto the stack
void push(struct Stack *stack, char value) {
    if (isFull(stack)) {
        printf("Stack Overflow\n");
        exit(1);
    }
    stack->items[++stack->top] = value;
}

// Function to pop an element from the stack
char pop(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return stack->items[stack->top--];
}

// Function to peek the top element of the stack
char peek(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        exit(1);
    }
    return stack->items[stack->top];
}

// Function to check if the given character is an operator
int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

// Function to get the precedence of an operator
int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

// Function to convert infix expression to postfix notation
void infixToPostfix(char infix[], char postfix[]) {
    struct Stack stack;
    initialize(&stack);

    int i = 0, j = 0;
    char ch, x;

    while ((ch = infix[i++]) != '\0') {
        if (isalnum(ch)) {
            postfix[j++] = ch;
        } else if (ch == '(') {
            push(&stack, ch);
        } else if (ch == ')') {
            while ((x = pop(&stack)) != '(') {
                postfix[j++] = x;
            }
        } else { // Operator
            while (!isEmpty(&stack) && precedence(ch) <= precedence(peek(&stack))) {
                x = pop(&stack);
                postfix[j++] = x;
            }
            push(&stack, ch);
        }
    }

    while (!isEmpty(&stack)) {
        x = pop(&stack);
        postfix[j++] = x;
    }

    postfix[j] = '\0';
}

// Function to convert infix expression to prefix notation
void infixToPrefix(char infix[], char prefix[]) {
    int length = strlen(infix);
    char temp[length + 1];
    int j = 0;

    // Reverse the infix expression
    for (int i = length - 1; i >= 0; i--) {
        if (infix[i] == '(')
            temp[j++] = ')';
        else if (infix[i] == ')')
            temp[j++] = '(';
        else
            temp[j++] = infix[i];
    }
    temp[j] = '\0';

    // Convert reversed infix expression to postfix
    char postfix[MAX_SIZE];
    infixToPostfix(temp, postfix);

    // Reverse the postfix expression to get prefix notation
    length = strlen(postfix);
    j = 0;
    for (int i = length - 1; i >= 0; i--) {
        prefix[j++] = postfix[i];
    }
    prefix[j] = '\0';
}

int main() {
    char infix[MAX_SIZE], postfix[MAX_SIZE], prefix[MAX_SIZE];

    printf("Enter an infix expression: ");
    fgets(infix, MAX_SIZE, stdin);

    // Remove the trailing newline character
    infix[strcspn(infix, "\n")] = '\0';

    infixToPostfix(infix, postfix);
    printf("Postfix notation: %s\n", postfix);

    infixToPrefix(infix, prefix);
    printf("Prefix notation: %s\n", prefix);

    return 0;
}

