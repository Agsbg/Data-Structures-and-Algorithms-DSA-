#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Node for stack
struct Node {
    int data;
    struct Node* next;
};

// Push
struct Node* push(struct Node* top, int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = top;
    return newNode;
}

// Pop
struct Node* pop(struct Node* top, int* val) {
    if (top == NULL) return NULL;

    struct Node* temp = top;
    *val = temp->data;
    top = top->next;
    free(temp);
    return top;
}

// Evaluate postfix
int evaluatePostfix(char* exp) {
    struct Node* top = NULL;
    char* token = strtok(exp, " ");

    while (token != NULL) {
        // If number (including negative)
        if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) {
            top = push(top, atoi(token));
        }
        else {
            int b, a;
            top = pop(top, &b);
            top = pop(top, &a);

            int result;
            if (strcmp(token, "+") == 0)
                result = a + b;
            else if (strcmp(token, "-") == 0)
                result = a - b;
            else if (strcmp(token, "*") == 0)
                result = a * b;
            else if (strcmp(token, "/") == 0)
                result = a / b;

            top = push(top, result);
        }

        token = strtok(NULL, " ");
    }

    int finalResult;
    top = pop(top, &finalResult);
    return finalResult;
}

// Main function
int main() {
    char exp[1000];

    // Read full line input
    fgets(exp, sizeof(exp), stdin);

    // Remove newline if present
    exp[strcspn(exp, "\n")] = '\0';

    int result = evaluatePostfix(exp);

    printf("%d\n", result);

    return 0;
}
