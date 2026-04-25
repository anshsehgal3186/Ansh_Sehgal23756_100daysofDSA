#include <iostream>
#include <queue>
#include <map>
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

// Build tree from level order
Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1)
        return NULL;

    Node* root = new Node(arr[0]);
    queue<Node*> q;
    q.push(root);

    int i = 1;

    while (!q.empty() && i < n) {
        Node* curr = q.front();
        q.pop();

        // Left child
        if (i < n && arr[i] != -1) {
            curr->left = new Node(arr[i]);
            q.push(curr->left);
        }
        i++;

        // Right child
        if (i < n && arr[i] != -1) {
            curr->right = new Node(arr[i]);
            q.push(curr->right);
        }
        i++;
    }

    return root;
}

// Vertical Order Traversal
void verticalOrder(Node* root) {
    if (root == NULL)
        return;

    map<int, vector<int>> mp; // HD -> nodes
    queue<pair<Node*, int>> q;

    q.push({root, 0});

    while (!q.empty()) {
        auto front = q.front();
        q.pop();

        Node* node = front.first;
        int hd = front.second;

        mp[hd].push_back(node->data);

        if (node->left)
            q.push({node->left, hd - 1});

        if (node->right)
            q.push({node->right, hd + 1});
    }

    // Print result
    for (auto it : mp) {
        for (int val : it.second) {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Node* root = buildTree(arr, n);

    verticalOrder(root);

    return 0;
}