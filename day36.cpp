#include <iostream>
using namespace std;

#define MAX 100

int queueArr[MAX];
int front = -1, rear = -1;

// Enqueue
void enqueue(int x) {
    if((rear + 1) % MAX == front) {
        cout << "Queue Overflow";
        return;
    }

    if(front == -1) front = 0;

    rear = (rear + 1) % MAX;
    queueArr[rear] = x;
}

// Dequeue
void dequeue() {
    if(front == -1) return;

    if(front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
}

// Display
void display() {
    if(front == -1) return;

    int i = front;
    while(true) {
        cout << queueArr[i] << " ";
        if(i == rear) break;
        i = (i + 1) % MAX;
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

    int m;
    cin >> m;

    for(int i = 0; i < m; i++) {
        dequeue();
    }

    display();

    return 0;
}