#include <iostream>
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

// Insert into BST
Node* insert(Node* root, int key) {
    if (root == NULL)
        return new Node(key);

    if (key < root->data)
        root->left = insert(root->left, key);
    else if (key > root->data)
        root->right = insert(root->right, key);

    return root;
}

// Find LCA
Node* findLCA(Node* root, int n1, int n2) {
    if (root == NULL)
        return NULL;

    // Both values smaller → go left
    if (n1 < root->data && n2 < root->data)
        return findLCA(root->left, n1, n2);

    // Both values greater → go right
    if (n1 > root->data && n2 > root->data)
        return findLCA(root->right, n1, n2);

    // Split point → this is LCA
    return root;
}

int main() {
    int n;
    cin >> n;

    Node* root = NULL;

    // Input BST values
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        root = insert(root, x);
    }

    int a, b;
    cin >> a >> b;

    Node* lca = findLCA(root, a, b);

    if (lca != NULL)
        cout << lca->data;

    return 0;
}