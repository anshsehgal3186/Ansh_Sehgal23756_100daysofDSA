#include <iostream>
#include <map>
using namespace std;

int main() {
    int n;
    cin >> n;

    map<int, int> freq;
    int x;

    // Input and count frequency
    for(int i = 0; i < n; i++) {
        cin >> x;
        freq[x]++;
    }

    // Print result
    for(auto it : freq) {
        cout << it.first << ":" << it.second << endl;
    }

    return 0;
}