#include <iostream>
using namespace std;

#define MAX 100

int pq[MAX];
int size = 0;

// Insert element
void insert(int x) {
    pq[size++] = x;
}

// Delete (remove min element)
void deleteMin() {
    if(size == 0) {
        cout << -1 << endl;
        return;
    }

    int minIndex = 0;
    for(int i = 1; i < size; i++) {
        if(pq[i] < pq[minIndex]) {
            minIndex = i;
        }
    }

    cout << pq[minIndex] << endl;

    // Shift elements
    for(int i = minIndex; i < size - 1; i++) {
        pq[i] = pq[i + 1];
    }

    size--;
}

// Peek (get min element)
void peek() {
    if(size == 0) {
        cout << -1 << endl;
        return;
    }

    int minVal = pq[0];
    for(int i = 1; i < size; i++) {
        if(pq[i] < minVal) {
            minVal = pq[i];
        }
    }

    cout << minVal << endl;
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
        else if(op == "delete") {
            deleteMin();
        }
        else if(op == "peek") {
            peek();
        }
    }

    return 0;
}