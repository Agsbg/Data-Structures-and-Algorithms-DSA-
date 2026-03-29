// Problem: Write a C program to insert an element x at a given 1-based position pos in an array of n integers. Shift existing elements to the right to make space.
#include <stdio.h>

int main() {
    int n, pos, x;

    if (scanf("%d", &n) != 1) return 0;

    int arr[n + 1];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    if (scanf("%d %d", &pos, &x) != 2) return 0;

    for (int i = n; i >= pos; i--) {
        arr[i] = arr[i - 1];
    }

    arr[pos - 1] = x;

    for (int i = 0; i <= n; i++) {
        printf("%d%s", arr[i], (i == n) ? "" : " ");
    }
    printf("\n");

    return 0;
}
