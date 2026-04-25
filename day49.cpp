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

// Function to insert into BST
Node* insert(Node* root, int key) {
    // Base case: insert here
    if (root == NULL) {
        return new Node(key);
    }

    // Recursive case
    if (key < root->data) {
        root->left = insert(root->left, key);
    }
    else if (key > root->data) {
        root->right = insert(root->right, key);
    }

    return root;
}

// Inorder traversal (to check BST)
void inorder(Node* root) {
    if (root == NULL) return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node* root = NULL;

    // Example insertion
    int arr[] = {5, 3, 7, 2, 4, 6, 8};

    for (int i = 0; i < 7; i++) {
        root = insert(root, arr[i]);
    }

    cout << "Inorder Traversal: ";
    inorder(root);

    return 0;
}