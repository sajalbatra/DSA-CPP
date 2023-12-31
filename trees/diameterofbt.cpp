//longest path between two nodes
//heoght of tree or maximum depth of tree
#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* rightptr;
    Node* leftptr;
    Node(int value) {
        data = value;
        rightptr = leftptr = nullptr;
    }
};

int height(Node* root, int* diameter);  // Function declaration

int diameterofBT(Node* root) {
    int diameter = 0;
    height(root, &diameter);
    return diameter;
}

int height(Node* root, int* diameter) {
    if (root == nullptr) return 0;

    int lh = height(root->leftptr, diameter);
    int rh = height(root->rightptr, diameter);

    // Calculate diameter passing through the current node
    *diameter = max(*diameter, lh + rh);

    return 1 + max(lh, rh);
}

int main(int argc, char const* argv[]) {
    Node* newNode = new Node(10);
    newNode->leftptr = new Node(11);
    newNode->rightptr = new Node(12);
    newNode->rightptr->leftptr = new Node(14);

    int diameter = diameterofBT(newNode);

    cout << "Diameter of the binary tree is: " << diameter;

    return 0;
}
