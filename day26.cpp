#include <iostream>
using namespace std;

// Doubly Linked List Node
class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int val) {
        data = val;
        prev = NULL;
        next = NULL;
    }
};

int main() {
    int n, x;
    cin >> n;

    Node* head = NULL;
    Node* temp = NULL;

    // Create doubly linked list
    for(int i = 0; i < n; i++) {
        cin >> x;

        Node* newNode = new Node(x);

        if(head == NULL) {
            head = newNode;
            temp = head;
        } else {
            temp->next = newNode;
            newNode->prev = temp;
            temp = newNode;
        }
    }

    // Traverse forward
    temp = head;
    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    return 0;
}