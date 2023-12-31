// check whether the 2 tree are equal or not 
// use inorder traversal then mathc every element 
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

bool checkInOrder(Node* root1, Node* root2) {
    if (root1 == nullptr && root2 == nullptr) {
        return true;  // Both trees are empty, consider them equal
    }
    
    if (root1 != nullptr && root2 != nullptr && root1->data == root2->data) {
        // Check left and right subtrees
        bool leftEqual = checkInOrder(root1->leftptr, root2->leftptr);
        bool rightEqual = checkInOrder(root1->rightptr, root2->rightptr);

        // Return true only if both left and right subtrees are equal
        return leftEqual && rightEqual;
    }

    // Nodes are not equal
    return false;
}

int main(int argc, char const* argv[]) {
    Node* root1 = new Node(10);
    root1->leftptr = new Node(5);
    root1->rightptr = new Node(15);

    Node* root2 = new Node(10);
    root2->leftptr = new Node(5);
    root2->rightptr = new Node(15);

    if (checkInOrder(root1, root2)) {
        cout << "Trees are equal.";
    } else {
        cout << "Trees are not equal.";
    }

    return 0;
}
