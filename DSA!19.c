#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    qsort(arr, n, sizeof(int), compare);

    int l = 0, r = n - 1;
    int bestSum = arr[l] + arr[r];
    int a = arr[l], b = arr[r];

    while(l < r) {
        int sum = arr[l] + arr[r];

        if(abs(sum) < abs(bestSum)) {
            bestSum = sum;
            a = arr[l];
            b = arr[r];
        }

        if(sum < 0)
            l++;
        else
            r--;
    }

    printf("%d %d", a, b);
    return 0;
}
