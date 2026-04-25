#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

// Function to rotate list
Node* rotateRight(Node* head, int k) {
    if(head == NULL || head->next == NULL || k == 0)
        return head;

    // Step 1: Find length and last node
    Node* temp = head;
    int len = 1;

    while(temp->next != NULL) {
        temp = temp->next;
        len++;
    }

    // Step 2: Make it circular
    temp->next = head;

    // Step 3: Normalize k
    k = k % len;

    // Step 4: Find new tail (n-k-th node)
    int steps = len - k;
    Node* newTail = head;

    for(int i = 1; i < steps; i++) {
        newTail = newTail->next;
    }

    // Step 5: Set new head
    Node* newHead = newTail->next;

    // Step 6: Break the circle
    newTail->next = NULL;

    return newHead;
}

int main() {
    int n, x, k;
    cin >> n;

    Node* head = NULL;
    Node* temp = NULL;

    // Create list
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

    cin >> k;

    head = rotateRight(head, k);

    // Print result
    temp = head;
    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    return 0;
}