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

int maxdepth(Node* root) {
    if (root == nullptr) return 0;
    
    int lh = maxdepth(root->leftptr);
    if (lh == -1) return -1;  // Left subtree is not balanced
    
    int rh = maxdepth(root->rightptr);
    if (rh == -1) return -1;  // Right subtree is not balanced
    
    if (abs(lh - rh) > 1) return -1;  // Current node is not balanced
    
    return 1 + max(lh, rh);
}

int main(int argc, char const *argv[]) {
    Node* newNode = new Node(10);
    newNode->leftptr = new Node(11);
    newNode->rightptr = new Node(12);
    newNode->rightptr->leftptr = new Node(13);
    newNode->rightptr->rightptr = new Node(14);
    newNode->rightptr->rightptr->leftptr = new Node(15);
    newNode->rightptr->rightptr->rightptr = new Node(16);

    int maxheight = maxdepth(newNode);

    if (maxheight == -1) {
        cout << "The tree is not balanced.";
    } else {
        cout << "The maximum height is: " << maxheight;
    }

    return 0;
}
