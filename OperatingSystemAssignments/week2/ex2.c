#include <stdio.h>
#include <string.h>

int main() {
    char string[100];
    scanf("%s", string);
    for (int i = 0; i < strlen(string)/2; i++) {
        char temp = string[i];
        string[i] = string[strlen(string)-i-1];
        string[strlen(string)-i-1] = temp;
    }
    printf("Reverse string: %s", string);
    return 0;
}
