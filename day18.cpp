#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[n];

    // Input array
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int k;
    cin >> k;

    k = k % n;  // handle k > n

    // Temporary array for rotated result
    int result[n];

    // Copy last k elements to front
    for(int i = 0; i < k; i++) {
        result[i] = arr[n - k + i];
    }

    // Copy remaining elements
    for(int i = k; i < n; i++) {
        result[i] = arr[i - k];
    }

    // Output
    for(int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }

    return 0;
}