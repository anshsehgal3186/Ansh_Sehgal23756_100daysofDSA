#include <iostream>
using namespace std;

#define MAX 100

int dq[MAX];
int front = -1, rear = -1;

// Check empty
bool empty() {
    return (front == -1);
}

// Size
int size() {
    if(front == -1) return 0;
    if(rear >= front) return rear - front + 1;
    return MAX - front + rear + 1;
}

// Push front
void push_front(int x) {
    if((front == 0 && rear == MAX - 1) || (front == rear + 1)) {
        cout << "Overflow\n";
        return;
    }

    if(front == -1) {
        front = rear = 0;
    }
    else if(front == 0) {
        front = MAX - 1;
    }
    else {
        front--;
    }

    dq[front] = x;
}

// Push back
void push_back(int x) {
    if((front == 0 && rear == MAX - 1) || (front == rear + 1)) {
        cout << "Overflow\n";
        return;
    }

    if(front == -1) {
        front = rear = 0;
    }
    else if(rear == MAX - 1) {
        rear = 0;
    }
    else {
        rear++;
    }

    dq[rear] = x;
}

// Pop front
void pop_front() {
    if(empty()) {
        cout << "Underflow\n";
        return;
    }

    if(front == rear) {
        front = rear = -1;
    }
    else if(front == MAX - 1) {
        front = 0;
    }
    else {
        front++;
    }
}

// Pop back
void pop_back() {
    if(empty()) {
        cout << "Underflow\n";
        return;
    }

    if(front == rear) {
        front = rear = -1;
    }
    else if(rear == 0) {
        rear = MAX - 1;
    }
    else {
        rear--;
    }
}

// Get front
void getFront() {
    if(empty()) cout << -1 << endl;
    else cout << dq[front] << endl;
}

// Get back
void getBack() {
    if(empty()) cout << -1 << endl;
    else cout << dq[rear] << endl;
}

int main() {
    // Example usage
    push_back(10);
    push_back(20);
    push_front(5);

    getFront(); // 5
    getBack();  // 20

    pop_front();
    pop_back();

    getFront(); // 10

    cout << size(); // 1

    return 0;
}