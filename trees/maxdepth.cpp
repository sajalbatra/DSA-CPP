//heoght of tree or maximum depth of tree
#include<iostream>
using namespace std;

struct Node{
    int data;
    Node*rightptr;
    Node*leftptr;
    Node(int value){
        data=value;
        rightptr=leftptr=nullptr;
    }
};
int maxdepth(Node* root){
    if(root==nullptr) return 0;
    int lh=maxdepth(root->leftptr);
    int rh=maxdepth(root->rightptr);
    return 1+max(lh,rh);
}
int main(int argc, char const *argv[])
{
    Node* newNode=new Node(10);
    newNode->leftptr=new Node(11);
    newNode->rightptr=new Node(12);
    newNode->rightptr->leftptr=new Node(14);
    int maxheight=maxdepth(newNode);
    cout<<"maximum height is: "<<maxheight;
    return 0;
}
