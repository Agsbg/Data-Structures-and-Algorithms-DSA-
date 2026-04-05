#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int stack[MAX];
int top = -1;

// Push function
void push(int val) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = val;
}

// Pop function
void pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return;
    }
    top--;
}

// Display stack (top to bottom)
void display() {
    for (int i = top; i >= 0; i--) {
        printf("%d", stack[i]);
        if (i != 0) printf(" ");
    }
    printf("\n");
}

// Main function
int main() {
    int n, m, val;

    // Number of elements to push
    scanf("%d", &n);

    // Push elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        push(val);
    }

    // Number of pops
    scanf("%d", &m);

    // Perform pop operations
    for (int i = 0; i < m; i++) {
        pop();
    }

    // Display remaining stack
    display();

    return 0;
}
