#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* leftptr;
    Node* rightptr;
    Node(int value){
        data=value;
        rightptr=leftptr=nullptr;
    }
};

// void inorder(Node* root){
//     if(root!=nullptr){
//         inorder(root->leftptr);
//         cout<<root->data <<" ";
//         inorder(root->rightptr);
//     }

// }

void inorder(Node* root){
    if(root==nullptr) return;
        inorder(root->leftptr);
        cout<<root->data <<" ";
        inorder(root->rightptr);
    

}

void postorder(Node* root){
    if(root==nullptr) return;
        inorder(root->leftptr);
        inorder(root->rightptr);
        cout<<root->data <<" ";

    

}
void preorder(Node* root){
    if(root==nullptr) return;
        cout<<root->data <<" ";
        inorder(root->leftptr);
        inorder(root->rightptr);
    

}
 
  
//   level order traversal
int height(Node* node) {
    if (node == NULL)
        return 0;
    else {
        int lheight = height(node->leftptr);
        int rheight = height(node->rightptr);
        if (lheight > rheight) {
            return(lheight + 1);
        }
        else {
          return(rheight + 1);
        }
    }
}

void CurrentLevel(Node* root, int level) {
    if (root == NULL)
        return; 
    if (level == 1)
        cout << root->data << " ";
    else if (level > 1) {
       CurrentLevel(root->leftptr, level-1);
       CurrentLevel(root->rightptr, level-1);
    }
}

void LevelOrder(Node* root) {
    int h = height(root);
    int i;
    for (i = 1; i <= h; i++)
     CurrentLevel(root, i);
}

// End of Level Order Traversal


int main(int argc, char const *argv[])
{
    Node* newNode=new Node(10);
    newNode->leftptr=new Node(11);
    newNode->rightptr=new Node(12);
    newNode->rightptr->leftptr=new Node(14);
    cout << "using inorder :";
    inorder(newNode);
    cout<<"\n";
    cout << "using postorder :";
    postorder(newNode);
    cout<<"\n";
    cout << "using preorder :";
    preorder(newNode);
    cout<<"\n";
    cout << "using Levelorder :";
    LevelOrder(newNode);
    cout<<"\n";
    
    return 0;
}