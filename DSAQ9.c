#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    
    // Input
    scanf("%s", str);
    
    int length = strlen(str);
    
    // Reverse the string using for 
    for (int i = length - 1; i >= 0; i--) {
        printf("%c", str[i]);
    }
    
    return 0;
}
