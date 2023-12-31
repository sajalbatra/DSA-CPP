#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* leftptr;
    Node* rightptr;
    Node(int value) {
        data = value;
        rightptr = leftptr = nullptr;
    }
};
Node* insert(Node* root, int value){
    if (root == nullptr) {
        return new Node(value);
    }
    if (value < root->data) {
        root->leftptr = insert(root->leftptr, value);
    } else if (value > root->data) {
        root->rightptr = insert(root->rightptr, value);
    }
    return root;
}
int deleteNode(Node* root, int data) {
    if (root == nullptr) return -1;
    if (root->data == data) {
        delete root;

        return -1;
    }
    deleteNode(root->leftptr, data);
    deleteNode(root->rightptr, data);

    return 0;
}

void inorder(Node* root){
    if (root == nullptr) return;
    inorder(root->leftptr);
    cout << root->data << " ";
    inorder(root->rightptr);
}
int main(int argc, char const *argv[]) {
    Node* root = nullptr;
    root = insert(root, 10);
    insert(root, 11);
    insert(root, 12);
    insert(root, 14);
    deleteNode(root,14);
    cout << "BST Inorder Traversal: ";
    inorder(root);
    cout << "\n";
    return 0;
}
