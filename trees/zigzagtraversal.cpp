// 1
// 23
// 456
// 76910
// output: 
// 1 
// 3 2 
// 4 5 6 
// 10 9 8 7 

#include<bits/stdc++.h>
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

void zigzagTraversal(Node* root) {
    if (root == nullptr) return;

    // Use two stacks to alternate the direction of traversal
    stack<Node*> currentLevel;
    stack<Node*> nextLevel;

    // Push the root node onto the currentLevel stack
    currentLevel.push(root);

    // Flag to indicate the direction of traversal
    bool leftToRight = true;

    while (!currentLevel.empty()) {
        // Pop a node from the currentLevel stack
        Node* currentNode = currentLevel.top();
        currentLevel.pop();

        // Print the data of the popped node
        cout << currentNode->data << " ";

        // Push the next level nodes onto the nextLevel stack based on the traversal direction
        if (leftToRight) {
            if (currentNode->leftptr) nextLevel.push(currentNode->leftptr);
            if (currentNode->rightptr) nextLevel.push(currentNode->rightptr);
        } else {
            if (currentNode->rightptr) nextLevel.push(currentNode->rightptr);
            if (currentNode->leftptr) nextLevel.push(currentNode->leftptr);
        }

        // Switch to the next level if the currentLevel stack is empty
        if (currentLevel.empty()) {
            swap(currentLevel, nextLevel);
            leftToRight = !leftToRight; // Change the direction for the next level
        }
    }
}

int main() {
    Node* root = new Node(1);
    root->leftptr = new Node(2);
    root->rightptr = new Node(3);
    root->leftptr->leftptr = new Node(4);
    root->leftptr->rightptr = new Node(5);
    root->rightptr->leftptr = new Node(6);
    root->rightptr->rightptr = new Node(7);

    cout << "Zigzag Traversal: ";
    zigzagTraversal(root);

    return 0;
}
