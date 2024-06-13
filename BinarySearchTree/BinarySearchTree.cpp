#include <iostream>
#include <string>
using namespace std;

//membuat class node
class Node
{
    //membuat akses modifier serta deklarasi varibel dan object
public:
    string info;
    Node* leftchild;
    Node* rightchild;

    //constructor untuk class node
    Node(string i, Node* l, Node* r)
    {
        info = i;
        leftchild = l;
        rightchild = r;
    }
};

//membuat class BinaryTree
class BinaryTree
{
    //membuat akses modifier dan deklarasi object
public:
    Node* ROOT;

    //constructor untuk class BinaryTree
    BinaryTree()
    {
        ROOT = nullptr; //initializing root to null
    }

    //membuat dan mendefinisikan prosedur insert
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

        if (element < parent->info) //If the value in the data field of the new node is less than that of the parent
        {
            parent->leftchild = newNode; // Make the left child of the parent point to the new node
        }
        else if (element > parent->info) // If the value in the data field of the new data is greater than that of the parent
        {
            parent->rightchild = newNode; //Make the right child of the parent point to the new node
        }
    }

    void search(string element, Node*& parent, Node*& currentNode) {
        currentNode = ROOT;
        parent = nullptr;

        while ((currentNode != nullptr) && (currentNode->info != element))
        {
            parent = currentNode;
            if (element < currentNode->info)
                currentNode = currentNode->leftchild;
            else
                currentNode = currentNode->rightchild;
        }
    };

    void inorder(Node* ptr) {
        if (ROOT == nullptr) {
            cout << "Tree is empty" << endl;
            return;
        }

        if (ptr != nullptr)
        {
            inorder(ptr->leftchild);
            cout << ptr->info << " ";
            inorder(ptr->rightchild);
        }
    };
    
    void preorder(Node* ptr) {
        if (ROOT == nullptr) {
            cout << "Tree is empty" << endl;
            return;
        }

        if (ptr != nullptr)
        {
            cout << ptr->info << " ";
            preorder(ptr->leftchild);
            preorder(ptr->rightchild);
        }
    }

    void postorder(Node* ptr) {
        if (ROOT == nullptr) {
            cout << "Tree is empty" << endl;
            return;
        }

        if (ptr != nullptr)
        {
            postorder(ptr->leftchild);
            postorder(ptr->rightchild);
            cout << ptr->info << " ";
        }
    };

};

int main()
{
    BinaryTree obj;

    while (true)
    {
        cout << "\nMenu" << endl;
        cout << "1. Implement insert operation" << endl;
        cout << "2. Perform inorder traversal" << endl;
        cout << "3. Perform preorder traversal" << endl;
        cout << "4. Perform postorder traversal" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice (1-5) : ";

        char ch;
        cin >> ch;
        cout << endl;

        switch (ch)
        {
        case '1': {
            cout << "Type a  word : ";
            string word;
            cin >> word;
            obj.insert(word);
            break;
        }
        case '2': {
            obj.inorder(obj.ROOT);
            break;
        }
        case '3': {
            obj.preorder(obj.ROOT);
            break;
        }
        case '4': {
            obj.postorder(obj.ROOT);
            break;
        }
        case '5': {
            return 0;
        }
        default:
            cout << "Invalid Option" << endl;
            break;
        }
    }
    
}
