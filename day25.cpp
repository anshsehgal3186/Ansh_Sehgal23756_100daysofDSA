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

// Function to count occurrences
int countKey(Node* head, int key) {
    int count = 0;
    Node* temp = head;

    while(temp != NULL) {
        if(temp->data == key) {
            count++;
        }
        temp = temp->next;
    }

    return count;
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

    // Count and print result
    cout << countKey(head, key);

    return 0;
}