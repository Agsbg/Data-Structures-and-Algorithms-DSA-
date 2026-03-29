#include <stdio.h>

void mergeLogs(int log1[], int p, int log2[], int q) {
    int i = 0, j = 0;
    int first = 1;
    
    while (i < p && j < q) {
        if (!first) printf(" ");
        
        if (log1[i] <= log2[j]) {
            printf("%d", log1[i]);
            i++;
        } else {
            printf("%d", log2[j]);
            j++;
        }
        first = 0;
    }
    
    while (i < p) {
        if (!first) printf(" ");
        printf("%d", log1[i]);
        i++;
        first = 0;
    }
    
    while (j < q) {
        if (!first) printf(" ");
        printf("%d", log2[j]);
        j++;
        first = 0;
    }
    
    printf("\n");
}

int main() {
    int p;
    scanf("%d", &p);
    
    int log1[p];
    for (int i = 0; i < p; i++) {
        scanf("%d", &log1[i]);
    }
    
    int q;
    scanf("%d", &q);
    
    int log2[q];
    for (int i = 0; i < q; i++) {
        scanf("%d", &log2[i]);
    }
    
    mergeLogs(log1, p, log2, q);
    
    return 0;
}
