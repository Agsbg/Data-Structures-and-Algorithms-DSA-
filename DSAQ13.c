#include <stdio.h>

int main() {
    int r, c;
    scanf("%d %d", &r, &c);

    int matrix[100][100];
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            scanf("%d", &matrix[i][j]);

    int top = 0, bottom = r - 1, left = 0, right = c - 1;
    int total = r * c, count = 0;

    while (top <= bottom && left <= right) {
        // Traverse right along the top row
        for (int j = left; j <= right; j++) {
            printf("%d", matrix[top][j]);
            if (++count < total) printf(" ");
        }
        top++;

        // Traverse down along the right column
        for (int i = top; i <= bottom; i++) {
            printf("%d", matrix[i][right]);
            if (++count < total) printf(" ");
        }
        right--;

        // Traverse left along the bottom row (if still valid)
        if (top <= bottom) {
            for (int j = right; j >= left; j--) {
                printf("%d", matrix[bottom][j]);
                if (++count < total) printf(" ");
            }
            bottom--;
        }

        // Traverse up along the left column (if still valid)
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                printf("%d", matrix[i][left]);
                if (++count < total) printf(" ");
            }
            left++;
        }
    }

    printf("\n");
    return 0;
}
