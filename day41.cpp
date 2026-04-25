#include <iostream>
using namespace std;

// Node structure
class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

// Queue class
class Queue {
public:
    Node* front;
    Node* rear;

    Queue() {
        front = rear = NULL;
    }

    // Enqueue
    void enqueue(int x) {
        Node* temp = new Node(x);

        if(rear == NULL) {
            front = rear = temp;
        } else {
            rear->next = temp;
            rear = temp;
        }
    }

    // Dequeue
    void dequeue() {
        if(front == NULL) {
            cout << -1 << endl;
            return;
        }

        Node* temp = front;
        cout << front->data << endl;

        front = front->next;

        if(front == NULL) {
            rear = NULL;
        }

        delete temp;
    }
};

int main() {
    int n;
    cin >> n;

    Queue q;
    string op;

    while(n--) {
        cin >> op;

        if(op == "enqueue") {
            int x;
            cin >> x;
            q.enqueue(x);
        }
        else if(op == "dequeue") {
            q.dequeue();
        }
    }

    return 0;
}