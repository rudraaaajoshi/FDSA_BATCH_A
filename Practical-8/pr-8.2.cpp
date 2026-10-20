#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

// Create a new node
Node* createNode(int x) {
    Node* newNode = new Node;

    newNode->data = x;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

// Insert a value into BST
Node* insert(Node* root, int x) {

    // If tree is empty
    if (root == NULL) {
        return createNode(x);
    }

    // Smaller value goes left
    if (x < root->data) {
        root->left = insert(root->left, x);
    }

    // Larger value goes right
    else if (x > root->data) {
        root->right = insert(root->right, x);
    }

    return root;
}

// Inorder traversal
void inorder(Node* root) {

    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {

    Node* root = NULL;

    // Book codes arriving
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    cout << "Book codes in sorted order: ";

    inorder(root);

    return 0;
}
