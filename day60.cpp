#include <iostream>
#include <queue>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Build tree from level order
Node* buildTree(int arr[], int n) {
    if (n == 0)
        return NULL;

    Node* root = new Node(arr[0]);
    queue<Node*> q;
    q.push(root);

    int i = 1;

    while (!q.empty() && i < n) {
        Node* curr = q.front();
        q.pop();

        if (i < n) {
            curr->left = new Node(arr[i]);
            q.push(curr->left);
            i++;
        }

        if (i < n) {
            curr->right = new Node(arr[i]);
            q.push(curr->right);
            i++;
        }
    }

    return root;
}

// Check CBT
bool isComplete(Node* root) {
    queue<Node*> q;
    q.push(root);

    bool foundNull = false;

    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();

        if (curr == NULL) {
            foundNull = true;
        } else {
            if (foundNull)
                return false;

            q.push(curr->left);
            q.push(curr->right);
        }
    }

    return true;
}

// Check heap property
bool isMinHeap(Node* root) {
    if (root == NULL)
        return true;

    // Leaf node
    if (root->left == NULL && root->right == NULL)
        return true;

    // Only left child
    if (root->right == NULL)
        return (root->data <= root->left->data) && isMinHeap(root->left);

    // Both children
    return (root->data <= root->left->data &&
            root->data <= root->right->data &&
            isMinHeap(root->left) &&
            isMinHeap(root->right));
}

int main() {
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    Node* root = buildTree(arr, n);

    if (isComplete(root) && isMinHeap(root))
        cout << "YES";
    else
        cout << "NO";

    return 0;
}