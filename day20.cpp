#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    unordered_map<int, int> freq;
    int sum = 0;
    int count = 0;

    // Important: sum = 0 already seen once
    freq[0] = 1;

    for(int i = 0; i < n; i++) {
        sum += arr[i];

        // If this sum seen before, add its frequency
        if(freq.find(sum) != freq.end()) {
            count += freq[sum];
        }

        freq[sum]++;
    }

    cout << count;

    return 0;
}