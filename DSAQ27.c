#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Create list
struct Node* createList(int n) {
    struct Node *head = NULL, *temp = NULL, *newNode;

    for(int i = 0; i < n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        scanf("%d", &newNode->data);
        newNode->next = NULL;

        if(head == NULL) {
            head = temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }
    return head;
}

// Get length
int getLength(struct Node* head) {
    int len = 0;
    while(head) {
        len++;
        head = head->next;
    }
    return len;
}

// Find intersection
int findIntersection(struct Node* head1, struct Node* head2) {
    int len1 = getLength(head1);
    int len2 = getLength(head2);

    struct Node *p1 = head1, *p2 = head2;

    // Move pointer of longer list
    if(len1 > len2) {
        for(int i = 0; i < len1 - len2; i++)
            p1 = p1->next;
    } else {
        for(int i = 0; i < len2 - len1; i++)
            p2 = p2->next;
    }

    // Traverse together
    while(p1 && p2) {
        if(p1->data == p2->data)   // comparing values (as per input style)
            return p1->data;

        p1 = p1->next;
        p2 = p2->next;
    }

    return -1; // no intersection
}

int main() {
    int n, m;

    scanf("%d", &n);
    struct Node* list1 = createList(n);

    scanf("%d", &m);
    struct Node* list2 = createList(m);

    int result = findIntersection(list1, list2);

    if(result == -1)
        printf("No Intersection");
    else
        printf("%d", result);

    return 0;
}
