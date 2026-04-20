#include <stdio.h>
#include <stdlib.h>

// ---------- Tree Node ----------
struct TreeNode {
    int val;
    struct TreeNode *left, *right;
};

struct TreeNode* createNode(int val) {
    struct TreeNode* n = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    n->val = val;
    n->left = n->right = NULL;
    return n;
}

// ---------- Build Tree (Level Order, -1 = NULL) ----------
struct TreeNode* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct TreeNode* root = createNode(arr[0]);
    struct TreeNode* q[n];
    int f = 0, r = 0;

    q[r++] = root;
    int i = 1;

    while (i < n && f < r) {
        struct TreeNode* cur = q[f++];

        if (i < n && arr[i] != -1) {
            cur->left = createNode(arr[i]);
            q[r++] = cur->left;
        }
        i++;

        if (i < n && arr[i] != -1) {
            cur->right = createNode(arr[i]);
            q[r++] = cur->right;
        }
        i++;
    }
    return root;
}

// ---------- Queue item (node + horizontal distance) ----------
struct QItem {
    struct TreeNode* node;
    int hd;
};

// ---------- Vertical Order Traversal ----------
void verticalOrder(struct TreeNode* root) {
    if (!root) return;

    // Simple arrays to group by horizontal distance
    // Range assumed small: [-1000, 1000]
    int minHD = 0, maxHD = 0;

    struct TreeNode* store[2001][2001];
    int count[2001] = {0};

    // BFS queue
    struct QItem q[2001];
    int f = 0, r = 0;

    q[r++] = (struct QItem){root, 0};

    while (f < r) {
        struct QItem cur = q[f++];
        struct TreeNode* node = cur.node;
        int hd = cur.hd;

        int idx = hd + 1000;

        store[idx][count[idx]++] = node;

        if (hd < minHD) minHD = hd;
        if (hd > maxHD) maxHD = hd;

        if (node->left)
            q[r++] = (struct QItem){node->left, hd - 1};

        if (node->right)
            q[r++] = (struct QItem){node->right, hd + 1};
    }

    // Print result from leftmost to rightmost
    for (int i = minHD + 1000; i <= maxHD + 1000; i++) {
        for (int j = 0; j < count[i]; j++) {
            printf("%d ", store[i][j]->val);
        }
        printf("\n");
    }
}

// ---------- Main ----------
int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct TreeNode* root = buildTree(arr, n);

    verticalOrder(root);

    return 0;
}
