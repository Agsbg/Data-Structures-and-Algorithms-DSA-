#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int prefixSum = 0, count = 0;

    // Using array as hash map (range assumed safe for typical inputs)
    int hash[20001] = {0};   // supports sums from -10000 to +10000
    int offset = 10000;

    hash[offset] = 1; // prefix sum = 0 occurs once

    for(int i = 0; i < n; i++) {
        prefixSum += arr[i];

        // If same prefix sum seen before → zero-sum subarray exists
        count += hash[prefixSum + offset];

        // Store this prefix sum
        hash[prefixSum + offset]++;
    }

    printf("%d", count);
    return 0;
}
