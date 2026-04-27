#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    int n, i;
    scanf("%d", &n);

    if (n == 0) {
        printf("YES");
        return 0;
    }

    int arr[n];
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Simple fixed tree creation for level order input
    struct TreeNode* nodes[n];

    for (i = 0; i < n; i++) {
        if (arr[i] == -1)
            nodes[i] = NULL;
        else
            nodes[i] = createNode(arr[i]);
    }

    for (i = 0; i < n; i++) {
        if (nodes[i] != NULL) {
            int leftIndex = 2 * i + 1;
            int rightIndex = 2 * i + 2;

            if (leftIndex < n)
                nodes[i]->left = nodes[leftIndex];

            if (rightIndex < n)
                nodes[i]->right = nodes[rightIndex];
        }
    }

    struct TreeNode* root = nodes[0];

    if (isSymmetric(root))
        printf("YES");
    else
        printf("NO");

    return 0;
}

// Definition for binary tree node
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Create new node
struct TreeNode* createNode(int val) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Check mirror
bool isMirror(struct TreeNode* left, struct TreeNode* right) {
    if (left == NULL && right == NULL)
        return true;

    if (left == NULL || right == NULL)
        return false;

    if (left->val != right->val)
        return false;

    return isMirror(left->left, right->right) &&
           isMirror(left->right, right->left);
}

// Check symmetric
bool isSymmetric(struct TreeNode* root) {
    if (root == NULL)
        return true;

    return isMirror(root->left, root->right);
}

