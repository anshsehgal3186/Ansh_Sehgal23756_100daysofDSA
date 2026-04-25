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

int main() {
    int n;
    cin >> n;

    if(n == 0) {
        cout << 0;
        return 0;
    }

    int x;
    cin >> x;

    // Create head
    Node* head = new Node(x);
    Node* temp = head;

    // Create remaining nodes
    for(int i = 1; i < n; i++) {
        cin >> x;
        temp->next = new Node(x);
        temp = temp->next;
    }

    // Count nodes
    int count = 0;
    temp = head;
    while(temp != NULL) {
        count++;
        temp = temp->next;
    }

    cout << count;

    return 0;
}