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

// Insert function (to build BST)
Node* insert(Node* root, int key) {
    if (root == NULL)
        return new Node(key);

    if (key < root->data)
        root->left = insert(root->left, key);
    else if (key > root->data)
        root->right = insert(root->right, key);

    return root;
}

// Search function
bool search(Node* root, int key) {
    // Base case
    if (root == NULL)
        return false;

    if (root->data == key)
        return true;

    if (key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}

int main() {
    Node* root = NULL;

    int arr[] = {5, 3, 7, 2, 4, 6, 8};

    // Build BST
    for (int i = 0; i < 7; i++) {
        root = insert(root, arr[i]);
    }

    int key = 4;

    if (search(root, key))
        cout << "Element found";
    else
        cout << "Element not found";

    return 0;
}