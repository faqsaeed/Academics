#include <iostream>
#include <queue>
using namespace std;


struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BST {
private:
    Node* root;

    bool insert(Node*& node, int v) 
    {
        if (!node) 
        {
            node = new Node(v);
            return true;
        }

        if (v == node->data) 
            return false; 
        else if (v < node->data) 
            return insert(node->left, v);
        else 
            return insert(node->right, v);
        
    }

    Node* copyTree(Node* otherRoot) 
    {
        if (!otherRoot) 
            return nullptr;

        Node* newNode = new Node(otherRoot->data);
        newNode->left = copyTree(otherRoot->left);
        newNode->right = copyTree(otherRoot->right);
        return newNode;
    }

    void inorderPrint(Node* node) const 
    {
        if (!node) 
            return;

        inorderPrint(node->left);
        cout << node->data << " ";
        inorderPrint(node->right);
    }

    void levelorderPrint(Node* node) const 
    {
        if (!node) 
            return;

        queue<Node*> q;
        q.push(node);

        while (!q.empty()) 
        {
            Node* current = q.front();
            cout << current->data << " ";
            q.pop();
            if (current->left) 
                q.push(current->left);
            if (current->right) 
                q.push(current->right);
        }

        cout << endl;
    }

    Node* search(Node* node, int key) const 
    {
        if (!node || node->data == key) 
            return node;
        if (key < node->data) 
            return search(node->left, key);

        return search(node->right, key);
    }

    int countNodes(Node* node) const 
    {
        if (!node) 
            return 0;
        return 1 + countNodes(node->left) + countNodes(node->right);
    }

    int leafCount(Node* node) const 
    {
        if (!node) 
            return 0;
        if (!node->left && !node->right) 
            return 1; 

        return leafCount(node->left) + leafCount(node->right);
    }

    void destroyTree(Node* node) 
    {
        if (!node) 
            return;

        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }

public:

    BST() : root(nullptr) {}

    bool insert(int v) 
    {
        return insert(root, v);
    }

    BST(const BST& other) 
    {
        root = copyTree(other.root);
    }

    void inorderPrint() const {

        inorderPrint(root);
        cout << endl;
    }

    void levelorderPrint() const 
    {
        levelorderPrint(root);
    }

    Node* search(int key) const 
    {
        return search(root, key);
    }

    int countNodes() const 
    {
        return countNodes(root);
    }

    int leafCount() const 
    {
        return leafCount(root);
    }

    ~BST() 
    {
        destroyTree(root);
    }
};

int main() {
    BST tree;
    
    // Inserting elements
    tree.insert(10);
    tree.insert(5);
    tree.insert(20);
    tree.insert(3);
    tree.insert(7);
    tree.insert(15);
    tree.insert(30);

    cout << "In-order traversal: ";
    tree.inorderPrint();

    cout << "Level-order traversal: ";
    tree.levelorderPrint();

    Node* result = tree.search(7);
    if (result) 
        cout << "Node with value 7 found." << endl;
    else 
        cout << "Node with value 7 not found." << endl;
    

    cout << "Total nodes: " << tree.countNodes() << endl;

    cout << "Leaf nodes: " << tree.leafCount() << endl;

    return 0;
}
