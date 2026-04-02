Here's the C solution:

```c
#include <stdio.h>

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    int matrix[100][100];
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &matrix[i][j]);

    int sum = 0;
    int limit = m < n ? m : n;  // handle non-square matrices

    for (int i = 0; i < limit; i++)
        sum += matrix[i][i];

    printf("%d\n", sum);
    return 0;
}
