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
    int n, x;
    cin >> n;

    if(n == 0) return 0;

    Node* head = NULL;
    Node* temp = NULL;

    // Create circular linked list
    for(int i = 0; i < n; i++) {
        cin >> x;

        Node* newNode = new Node(x);

        if(head == NULL) {
            head = newNode;
            temp = head;
        } else {
            temp->next = newNode;
            temp = temp->next;
        }
    }

    // Make it circular
    temp->next = head;

    // Traverse circular list (print once)
    Node* curr = head;
    do {
        cout << curr->data << " ";
        curr = curr->next;
    } while(curr != head);

    return 0;
}