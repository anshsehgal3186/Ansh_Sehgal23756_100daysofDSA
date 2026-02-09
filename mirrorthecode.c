#include <stdio.h>
#include <string.h>

void reverseString(char str[], int start, int end) {
    if (start >= end)
        return;

    // swap characters
    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;

    // recursive call
    reverseString(str, start + 1, end - 1);
}

int main() {
    char str[100];
    printf("Enter code name: ");
    scanf("%s", str);

    reverseString(str, 0, strlen(str) - 1);

    printf("Mirror format: %s\n", str);
    return 0;
}
