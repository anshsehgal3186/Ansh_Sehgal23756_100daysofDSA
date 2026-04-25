#include <iostream>
#include <vector>
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

// Helper to build tree
Node* buildTree(vector<int>& preorder, vector<int>& inorder,
                int preStart, int preEnd,
                int inStart, int inEnd) {

    if (preStart > preEnd || inStart > inEnd)
        return NULL;

    // Root from preorder
    int rootVal = preorder[preStart];
    Node* root = new Node(rootVal);

    // Find root in inorder
    int k = inStart;
    while (inorder[k] != rootVal) k++;

    int leftSize = k - inStart;

    // Build left and right subtree
    root->left = buildTree(preorder, inorder,
                           preStart + 1,
                           preStart + leftSize,
                           inStart,
                           k - 1);

    root->right = buildTree(preorder, inorder,
                            preStart + leftSize + 1,
                            preEnd,
                            k + 1,
                            inEnd);

    return root;
}

// Postorder traversal
void postorder(Node* root) {
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main() {
    int n;
    cin >> n;

    vector<int> preorder(n), inorder(n);

    for (int i = 0; i < n; i++)
        cin >> preorder[i];

    for (int i = 0; i < n; i++)
        cin >> inorder[i];

    Node* root = buildTree(preorder, inorder, 0, n - 1, 0, n - 1);

    postorder(root);

    return 0;
}