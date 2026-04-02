#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[1000];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int visited[1000] = {0};

    for (int i = 0; i < n; i++) {
        if (visited[i]) continue;  // already counted

        int count = 1;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] == arr[i]) {
                count++;
                visited[j] = 1;  // mark as counted
            }
        }
        printf("%d:%d\n", arr[i], count);
    }

    return 0;
}
