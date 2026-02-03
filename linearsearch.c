#include <stdio.h>

int main() {
    int n, k;
    int comparisons = 0;
    int found = -1;

    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter array elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter key to search: ");
    scanf("%d", &k);

    for (int i = 0; i < n; i++) {
        comparisons++;          // one comparison
        if (arr[i] == k) {
            found = i;
            break;
        }
    }

    if (found != -1)
        printf("Key found at index %d\n", found);
    else
        printf("Key not found\n");

    printf("Number of comparisons: %d\n", comparisons);

    return 0;
}
