#include <iostream>
using namespace std;

#define MAX 100

int stackArr[MAX];
int top = -1;

// Push function
void push(int x) {
    stackArr[++top] = x;
}

// Pop function
void pop() {
    if(top != -1)
        top--;
}

int main() {
    int n;
    cin >> n;

    int x;
    // Push n elements
    for(int i = 0; i < n; i++) {
        cin >> x;
        push(x);
    }

    int m;
    cin >> m;

    // Pop m elements
    for(int i = 0; i < m; i++) {
        if(top == -1) break;
        pop();
    }

    // Display remaining elements
    for(int i = top; i >= 0; i--) {
        cout << stackArr[i] << " ";
    }

    return 0;
}