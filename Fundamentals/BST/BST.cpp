#include <iostream>

using namespace std;

// Node structure
struct Node
{
    int value;
    Node *leftChild;
    Node *rightChild;

    // constructor
    Node(int number)
    {
        value = number;
        leftChild = nullptr;
        rightChild = nullptr;
    }
};

// Binary search tree class
class BST
{
private:
    Node *root;

    Node *searchNode(int); // search prototype
    Node *findParent(int); // findparent prototype
    Node *findMin(Node *); // findmin prototype

public:
    BST();                 // constructor
    void insert(int);      // insert method prototype
    bool search(int);      // search prototype;
    void deletevalue(int); // deletevalue prototype
    void update(int, int); // update prototype
};

// constructor implementation
BST::BST()
{
    root = nullptr;
}

// search implementation
Node *BST::searchNode(int value)
{
    Node *current = root;
    while (current != nullptr)
    {
        if (value == current->value)
        {
            return current;
        }
        else if (value < current->value)
        {
            current = current->leftChild;
        }
        else
        {
            current = current->rightChild;
        }
    }
    return nullptr;
}

// findparent implementation
Node *BST::findParent(int value)
{
    Node *parent = nullptr;
    Node *current = root;
    while (current != nullptr && current->value != value)
    {
        parent = current;
        if (value < current->value)
        {
            current = current->leftChild;
        }
        else
        {
            current = current->rightChild;
        }
    }
    return parent;
}

// findmin implementation
Node *BST::findMin(Node *node)
{
    while (node && node->leftChild != nullptr)
    {
        node = node->leftChild;
    }
    return node;
}

// insrt implementation
void BST::insert(int value)
{
    Node *newNode = new Node(value);

    // if the tree is empty
    if (root == nullptr)
    {
        root = newNode;
        cout << "Inserted " << value << " as root." << endl;
        return;
    }

    Node *current = root;
    Node *parent = nullptr;

    // find the best spot to insert
    while (current != nullptr)
    {
        parent = current;
        if (value < current->value)
        {
            current = current->leftChild;
        }
        else if (value > current->value)
        {
            current = current->rightChild;
        }
        else
        {
            // Duplicated value is not allowed
            cout << "Duplicate value " << value << " not inserted." << endl;
            delete newNode;
            return;
        }
    }

    if (value < parent->value)
    {
        parent->leftChild = newNode;
    }
    else
    {
        parent->rightChild = newNode;
    }
    cout << "Inserted " << value << " into BST." << endl;
}

// search implementation
bool BST::search(int value)
{
    Node *current = root;
    while (current != nullptr)
    {
        if (value == current->value)
        {
            cout << "value " << value << " found." << endl;
            return true;
        }
        else if (value < current->value)
        {
            current = current->leftChild;
        }
        else
        {
            current = current->rightChild;
        }
    }
    cout << "value " << value << " was not found!!!!!." << endl;
    return false;
}

// deletevalue implementation
void BST::deletevalue(int value)
{
    if (root == nullptr)
    {
        cout << "Tree is empty. Cannot delete." << endl;
        return;
    }

    Node *parent = nullptr;
    Node *current = root;

    while (current != nullptr && current->value != value)
    {
        parent = current;
        if (value < current->value)
        {
            current = current->leftChild;
        }
        else
        {
            current = current->rightChild;
        }
    }

    if (current == nullptr)
    {
        cout << "value " << value << " not found. Cannot delete." << endl;
        return;
    }

    bool isLeftChild = (parent != nullptr && current == parent->leftChild);

    if (current->leftChild == nullptr && current->rightChild == nullptr)
    {
        if (parent == nullptr)
        {
            root = nullptr;
        }
        else if (isLeftChild)
        {
            parent->leftChild = nullptr;
        }
        else
        {
            parent->rightChild = nullptr;
        }
        delete current;
        cout << "Deleted " << value << " (leaf)." << endl;
    }
    else if (current->leftChild == nullptr)
    {
        if (parent == nullptr)
        {
            root = current->rightChild;
        }
        else if (isLeftChild)
        {
            parent->leftChild = current->rightChild;
        }
        else
        {
            parent->rightChild = current->rightChild;
        }
        delete current;
        cout << "Deleted " << value << " (has right child)." << endl;
    }
    else if (current->rightChild == nullptr)
    {
        if (parent == nullptr)
        {
            root = current->leftChild;
        }
        else if (isLeftChild)
        {
            parent->leftChild = current->leftChild;
        }
        else
        {
            parent->rightChild = current->leftChild;
        }
        delete current;
        cout << "Deleted " << value << " (has left child)." << endl;
    }
    else
    {
        Node *successorParent = current;
        Node *successor = current->rightChild;
        while (successor->leftChild != nullptr)
        {
            successorParent = successor;
            successor = successor->leftChild;
        }

        current->value = successor->value;

        if (successorParent->leftChild == successor)
        {
            successorParent->leftChild = successor->rightChild;
        }
        else
        {
            successorParent->rightChild = successor->rightChild;
        }
        delete successor;
        cout << "Deleted " << value << " (has two children, replaced with successor)." << endl;
    }
}

// update implementation
void BST::update(int oldValue, int newValue)
{
    if (oldValue == newValue)
    {
        cout << "Old and new values are the same. No update." << endl;
        return;
    }

    if (!search(oldValue))
    {
        cout << "Cannot update: " << oldValue << " not found." << endl;
        return;
    }

    deletevalue(oldValue);
    insert(newValue);
    cout << "Updated " << oldValue << " to " << newValue << "." << endl;
}

// main function for test
int main()
{
    BST tree;

    // insert test
    cout << endl;
    cout << "=========================" << endl;
    cout << "Testing insert method: " << endl;
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);
    tree.insert(40); // duplicate test
    cout << "=========================" << endl;
    cout << endl;

    // search test
    cout << "Testing search method: " << endl;
    tree.search(40);
    tree.search(100);
    cout << "=========================" << endl;
    cout << endl;

    //delete test
    cout << "Testing delete method: " << endl;
    tree.deletevalue(20); // leaf
    tree.deletevalue(30); // one child
    tree.deletevalue(50); // two children
    cout << "=========================" << endl;
    cout << endl;

    // update test
    cout << "Testing update method: " << endl;
    tree.update(60, 65);
    cout << "=========================" << endl;
    cout << endl;

    return 0;
}