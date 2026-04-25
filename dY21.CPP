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

    // Traverse and print
    temp = head;
    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    return 0;
}