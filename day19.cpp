#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Sort array
    sort(arr, arr + n);

    int left = 0;
    int right = n - 1;

    int minSum = INT_MAX;
    int a, b;

    // Two pointer approach
    while(left < right) {
        int sum = arr[left] + arr[right];

        if(abs(sum) < abs(minSum)) {
            minSum = sum;
            a = arr[left];
            b = arr[right];
        }

        if(sum < 0)
            left++;
        else
            right--;
    }

    cout << a << " " << b;

    return 0;
}