#include <stdio.h>

void mergeLogs(int logA[], int sizeA, int logB[], int sizeB, int merged[]) {
    int i = 0, j = 0, k = 0;

    // Merge while both logs have elements
    while (i < sizeA && j < sizeB) {
        if (logA[i] <= logB[j]) {
            merged[k++] = logA[i++];
        } else {
            merged[k++] = logB[j++];
        }
    }

    // Copy remaining elements from logA
    while (i < sizeA) {
        merged[k++] = logA[i++];
    }

    // Copy remaining elements from logB
    while (j < sizeB) {
        merged[k++] = logB[j++];
    }
}

int main() {
    int logA[] = {1, 5, 20};
    int logB[] = {2, 6, 15};

    int sizeA = sizeof(logA) / sizeof(logA[0]);
    int sizeB = sizeof(logB) / sizeof(logB[0]);

    int merged[sizeA + sizeB];

    mergeLogs(logA, sizeA, logB, sizeB, merged);

    printf("Merged Log: ");
    for (int i = 0; i < sizeA + sizeB; i++) {
        printf("%d ", merged[i]);
    }

    return 0;
}
