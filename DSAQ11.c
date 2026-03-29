#include <stdio.h>

int main() {
    int a, b;

    // Input rows and columns
    scanf("%d %d", &a, &b);

    int A[a][b], B[a][b], sum[a][b];

    // Input first matrix
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    // Input second matrix
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    // Add matrices
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            sum[i][j] = A[i][j] + B[i][j];
        }
    }

    // Print result
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            printf("%d ", sum[i][j]);
        }
        printf("\n");
    }

    return 0;
}
