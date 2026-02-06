#include <stdio.h>

int main() {
    int arr[] = {1, 1, 2, 2, 3, 4, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    if (n == 0)
        return 0;

    int i = 0;
    for (int j = 1; j < n; j++) {
        if (arr[j] != arr[i]) {
            i++;
            arr[i] = arr[j];
        }
    }

    // Print unique elements
    for (int k = 0; k <= i; k++) {
        printf("%d ", arr[k]);
    }

    return 0;
}
