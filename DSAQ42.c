#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

// Queue implementation using array
typedef struct {
    int arr[MAX];
    int front, rear;
} Queue;

// Stack implementation using array
typedef struct {
    int arr[MAX];
    int top;
} Stack;

// Queue functions
void initQueue(Queue* q) {
    q->front = 0;
    q->rear = -1;
}

int isQueueEmpty(Queue* q) {
    return q->front > q->rear;
}

void enqueue(Queue* q, int val) {
    q->arr[++q->rear] = val;
}

int dequeue(Queue* q) {
    if (isQueueEmpty(q)) return -1;
    return q->arr[q->front++];
}

// Stack functions
void initStack(Stack* s) {
    s->top = -1;
}

int isStackEmpty(Stack* s) {
    return s->top == -1;
}

void push(Stack* s, int val) {
    s->arr[++s->top] = val;
}

int pop(Stack* s) {
    if (isStackEmpty(s)) return -1;
    return s->arr[s->top--];
}

// Reverse queue using stack
void reverseQueue(Queue* q) {
    Stack s;
    initStack(&s);

    // Step 1: Dequeue all elements into stack
    while (!isQueueEmpty(q)) {
        push(&s, dequeue(q));
    }

    // Step 2: Pop from stack and enqueue back
    while (!isStackEmpty(&s)) {
        enqueue(q, pop(&s));
    }
}

// Main function
int main() {
    int N;
    scanf("%d", &N);

    Queue q;
    initQueue(&q);

    // Input queue elements
    for (int i = 0; i < N; i++) {
        int x;
        scanf("%d", &x);
        enqueue(&q, x);
    }

    // Reverse queue
    reverseQueue(&q);

    // Print reversed queue
    while (!isQueueEmpty(&q)) {
        printf("%d ", dequeue(&q));
    }

    return 0;
}
