#include <iostream>
using namespace std;

// Node structure for polynomial
class Node {
public:
    int coeff;
    int exp;
    Node* next;

    Node(int c, int e) {
        coeff = c;
        exp = e;
        next = NULL;
    }
};

int main() {
    int n;
    cin >> n;

    Node* head = NULL;
    Node* temp = NULL;

    // Create polynomial linked list
    for(int i = 0; i < n; i++) {
        int c, e;
        cin >> c >> e;

        Node* newNode = new Node(c, e);

        if(head == NULL) {
            head = newNode;
            temp = head;
        } else {
            temp->next = newNode;
            temp = temp->next;
        }
    }

    // Print polynomial
    temp = head;
    while(temp != NULL) {
        cout << temp->coeff;

        if(temp->exp > 1)
            cout << "x^" << temp->exp;
        else if(temp->exp == 1)
            cout << "x";

        if(temp->next != NULL)
            cout << " + ";

        temp = temp->next;
    }

    return 0;
}