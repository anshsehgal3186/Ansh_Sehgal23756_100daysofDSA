#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int main() {
    int n;
    cin >> n;

    queue<int> q;
    stack<int> st;

    // Input queue
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        q.push(x);
    }

    // Step 1: Queue → Stack
    while(!q.empty()) {
        st.push(q.front());
        q.pop();
    }

    // Step 2: Stack → Queue
    while(!st.empty()) {
        q.push(st.top());
        st.pop();
    }

    // Print reversed queue
    while(!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}