#include <iostream>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;

    int matrix[m][n];

    // Input matrix
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    // Calculate diagonal sum
    int sum = 0;
    for(int i = 0; i < m && i < n; i++) {
        sum += matrix[i][i];
    }

    // Output
    cout << sum;

    return 0;
}