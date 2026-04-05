#include <stdio.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

// Push
void push(char c) {
    stack[++top] = c;
}

// Pop
char pop() {
    if (top == -1) return -1;
    return stack[top--];
}

// Peek
char peek() {
    if (top == -1) return -1;
    return stack[top];
}

// Precedence
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

// Infix to Postfix
void infixToPostfix(char* exp) {
    for (int i = 0; exp[i] != '\0'; i++) {
        char ch = exp[i];

        // Operand → print directly
        if (isalnum(ch)) {
            printf("%c", ch);
        }
        // Opening bracket
        else if (ch == '(') {
            push(ch);
        }
        // Closing bracket
        else if (ch == ')') {
            while (top != -1 && peek() != '(') {
                printf("%c", pop());
            }
            pop(); // remove '('
        }
        // Operator
        else {
            while (top != -1 && precedence(peek()) >= precedence(ch)) {
                printf("%c", pop());
            }
            push(ch);
        }
    }

    // Pop remaining operators
    while (top != -1) {
        printf("%c", pop());
    }
}

// Main function
int main() {
    char exp[MAX];

    scanf("%s", exp);

    infixToPostfix(exp);

    return 0;
}
