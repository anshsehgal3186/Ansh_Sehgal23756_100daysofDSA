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

// Function to delete first occurrence of key
Node* deleteKey(Node* head, int key) {
    // Case 1: empty list
    if(head == NULL) return head;

    // Case 2: key is at head
    if(head->data == key) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    // Case 3: key is in middle/end
    Node* curr = head;
    while(curr->next != NULL && curr->next->data != key) {
        curr = curr->next;
    }

    // If key found
    if(curr->next != NULL) {
        Node* temp = curr->next;
        curr->next = temp->next;
        delete temp;
    }

    return head;
}

int main() {
    int n, x, key;
    cin >> n;

    Node* head = NULL;
    Node* temp = NULL;

    // Create linked list
    for(int i = 0; i < n; i++) {
        cin >> x;
        if(head == NULL) {
            head = new Node(x);
            temp = head;
        } else {
            temp->next = new Node(x);
            temp = temp->next;
        }
    }

    cin >> key;

    // Delete key
    head = deleteKey(head, key);

    // Print updated list
    temp = head;
    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    return 0;
}