#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Create new node
struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

// Insert at end
struct Node* insert(struct Node* head, int val) {
    struct Node* newNode = createNode(val);

    if (head == NULL)
        return newNode;

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

// Rotate right by k
struct Node* rotateRight(struct Node* head, int k) {
    if (!head || !head->next || k == 0)
        return head;

    // Find length and last node
    struct Node* temp = head;
    int n = 1;
    while (temp->next) {
        temp = temp->next;
        n++;
    }

    // Make circular
    temp->next = head;

    // Handle k > n
    k = k % n;

    // Find new tail: (n - k) steps
    int steps = n - k;
    struct Node* newTail = head;

    for (int i = 1; i < steps; i++)
        newTail = newTail->next;

    // New head
    struct Node* newHead = newTail->next;

    // Break circle
    newTail->next = NULL;

    return newHead;
}

// Display list
void display(struct Node* head) {
    while (head) {
        printf("%d", head->data);
        if (head->next) printf(" ");
        head = head->next;
    }
    printf("\n");
}

// Main function
int main() {
    int n, val, k;
    struct Node* head = NULL;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        head = insert(head, val);
    }

    scanf("%d", &k);

    head = rotateRight(head, k);

    display(head);

    return 0;
}
