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

// Function to merge two sorted lists
Node* mergeLists(Node* l1, Node* l2) {
    Node* dummy = new Node(0);
    Node* tail = dummy;

    while(l1 != NULL && l2 != NULL) {
        if(l1->data < l2->data) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }

    // Attach remaining elements
    if(l1 != NULL) tail->next = l1;
    if(l2 != NULL) tail->next = l2;

    return dummy->next;
}

int main() {
    int n, m, x;

    // First list
    cin >> n;
    Node* head1 = NULL;
    Node* temp1 = NULL;

    for(int i = 0; i < n; i++) {
        cin >> x;
        if(head1 == NULL) {
            head1 = new Node(x);
            temp1 = head1;
        } else {
            temp1->next = new Node(x);
            temp1 = temp1->next;
        }
    }

    // Second list
    cin >> m;
    Node* head2 = NULL;
    Node* temp2 = NULL;

    for(int i = 0; i < m; i++) {
        cin >> x;
        if(head2 == NULL) {
            head2 = new Node(x);
            temp2 = head2;
        } else {
            temp2->next = new Node(x);
            temp2 = temp2->next;
        }
    }

    // Merge lists
    Node* merged = mergeLists(head1, head2);

    // Print merged list
    while(merged != NULL) {
        cout << merged->data << " ";
        merged = merged->next;
    }

    return 0;
}