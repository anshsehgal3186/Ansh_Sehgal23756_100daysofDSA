#include <iostream>
using namespace std;

#define MAX 100

int heap[MAX];
int size = 0;

// Swap helper
void swap(int &a, int &b) {
    int t = a;
    a = b;
    b = t;
}

// Heapify up
void heapifyUp(int i) {
    while(i > 0 && heap[(i - 1) / 2] > heap[i]) {
        swap(heap[i], heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Heapify down
void heapifyDown(int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if(left < size && heap[left] < heap[smallest])
        smallest = left;

    if(right < size && heap[right] < heap[smallest])
        smallest = right;

    if(smallest != i) {
        swap(heap[i], heap[smallest]);
        heapifyDown(smallest);
    }
}

// Insert
void insert(int x) {
    if(size == MAX) return;
    heap[size] = x;
    heapifyUp(size);
    size++;
}

// Peek
void peek() {
    if(size == 0) {
        cout << -1 << endl;
        return;
    }
    cout << heap[0] << endl;
}

// Extract Min
void extractMin() {
    if(size == 0) {
        cout << -1 << endl;
        return;
    }

    cout << heap[0] << endl;

    heap[0] = heap[size - 1];
    size--;

    heapifyDown(0);
}

int main() {
    int n;
    cin >> n;

    string op;

    while(n--) {
        cin >> op;

        if(op == "insert") {
            int x;
            cin >> x;
            insert(x);
        }
        else if(op == "peek") {
            peek();
        }
        else if(op == "extractMin") {
            extractMin();
        }
    }

    return 0;
}