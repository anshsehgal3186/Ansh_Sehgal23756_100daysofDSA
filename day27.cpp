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

// Function to get length
int getLength(Node* head) {
    int len = 0;
    while(head != NULL) {
        len++;
        head = head->next;
    }
    return len;
}

// Function to find intersection
Node* findIntersection(Node* head1, Node* head2) {
    int len1 = getLength(head1);
    int len2 = getLength(head2);

    Node* p1 = head1;
    Node* p2 = head2;

    // Align both lists
    if(len1 > len2) {
        for(int i = 0; i < len1 - len2; i++) p1 = p1->next;
    } else {
        for(int i = 0; i < len2 - len1; i++) p2 = p2->next;
    }

    // Traverse together
    while(p1 != NULL && p2 != NULL) {
        if(p1 == p2) return p1;
        p1 = p1->next;
        p2 = p2->next;
    }

    return NULL;
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

    // Second list (initially separate)
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

    // ⚠️ Manually create intersection (for demo)
    Node* intersect = head1->next->next; // node with value 30
    temp2->next = intersect;

    // Find intersection
    Node* ans = findIntersection(head1, head2);

    if(ans != NULL)
        cout << ans->data;
    else
        cout << "No Intersection";

    return 0;
}