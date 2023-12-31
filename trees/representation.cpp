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

int main(int argc, char const *argv[])
{
    Node* newNode=new Node(10);
    newNode->leftptr=new Node(11);
    newNode->rightptr=new Node(12);
    newNode->rightptr->leftptr=new Node(14);
    cout<<newNode->data;
    return 0;
}
  