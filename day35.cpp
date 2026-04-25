#include <iostream>
using namespace std;

#define MAX 100

int queueArr[MAX];
int front = 0, rear = -1;

// Enqueue
void enqueue(int x) {
    if(rear == MAX - 1) {
        cout << "Queue Overflow";
        return;
    }
    queueArr[++rear] = x;
}

// Display
void display() {
    for(int i = front; i <= rear; i++) {
        cout << queueArr[i] << " ";
    }
}

int main() {
    int n;
    cin >> n;

    int x;
    for(int i = 0; i < n; i++) {
        cin >> x;
        enqueue(x);
    }

    display();

    return 0;
}