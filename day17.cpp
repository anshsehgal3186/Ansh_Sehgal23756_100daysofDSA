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

    // Initialize max and min
    int maxVal = arr[0];
    int minVal = arr[0];

    // Find max and min
    for(int i = 1; i < n; i++) {
        if(arr[i] > maxVal) {
            maxVal = arr[i];
        }
        if(arr[i] < minVal) {
            minVal = arr[i];
        }
    }

    // Output
    cout << "Maximum: " << maxVal << endl;
    cout << "Minimum: " << minVal << endl;

    return 0;
}
