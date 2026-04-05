#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Queue structure
struct Queue {
    struct Node *front, *rear;
};

// Create queue
struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

// Enqueue (insert)
void enqueue(struct Queue* q, int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = newNode;
        return;
    }

    q->rear->next = newNode;
    q->rear = newNode;
}

// Display queue
void display(struct Queue* q) {
    struct Node* temp = q->front;

    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next) printf(" ");
        temp = temp->next;
    }
    printf("\n");
}

// Main function
int main() {
    int n, val;

    scanf("%d", &n);

    struct Queue* q = createQueue();

    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        enqueue(q, val);
    }

    display(q);

    return 0;
}
