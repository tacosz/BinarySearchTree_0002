#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
    string info;
    Node* leftchild;
    Node* rightchild;

    //constructor for the node class
    Node(string i, Node* l, Node* r)
    {
        info = i;
        leftchild = l;
        rightchild = r;
    }
};

class BinaryTree
{
public:
    Node* ROOT;

    BinaryTree()
    {
        ROOT = nullptr; //initializing root to null
    }

    void insert(string element) //insert a node in the binary search tree
    {
        Node* newNode = new Node(element, nullptr, nullptr); //allocate memory for the new node
        newNode->info = element; //assign value to the data field of the new data
        newNode->leftchild = nullptr; //make the left child of the new node point to NULL
        newNode->rightchild = nullptr; //make the right child of the new node point to NULL

        Node* parent = nullptr;
        Node* currentNode = nullptr;
        search(element, parent, currentNode); //locate the node which be the parent of the node

        if (parent == nullptr) //If the parent is NULL (Tree is empty)
        {
            ROOT = newNode; //Mark the new node as ROOT
            return; //exit
        }

        if (element < parent->info) //If the value in the data field pf the new node is less than that of the parent
        {
            parent->leftchild = newNode; // Make the left child of the parent point to the new node
        }
    }
};

int main()
{
    
}
