#include<stdio.h>
// Function to reverse the array in place using while loop
void reverse(int arr[], int size){
    int start = 0;
    int end = size - 1;
    while(start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}
int main() {
    int size;
    printf("Enter size of an array: ");
    scanf("%d", &size);
    int arr[size];
    // Input elements
    int i = 0;
    while(i < size) {
        printf("Enter element %d: ", i+1);
        scanf("%d", &arr[i]);
        i++;
    }
    // Call the reverse function
    reverse(arr, size);
    // Print reversed array
    i = 0;
    printf("Reversed array:\n");
    while(i < size) {
        printf("%d\n", arr[i]);
        i++;
    }
    return 0;
}
