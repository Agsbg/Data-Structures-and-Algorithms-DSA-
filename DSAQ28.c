#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n;
    scanf("%d", &n);

    struct Node *head = NULL, *temp = NULL, *newNode;

    // Create circular linked list
    for(int i = 0; i < n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        scanf("%d", &newNode->data);

        if(head == NULL) {
            head = temp = newNode;
            newNode->next = head;  // circular link
        } else {
            temp->next = newNode;
            newNode->next = head;  // point to head
            temp = newNode;
        }
    }

    // Traverse circular list
    if(head != NULL) {
        temp = head;
        do {
            printf("%d ", temp->data);
            temp = temp->next;
        } while(temp != head);
    }

    return 0;
}
