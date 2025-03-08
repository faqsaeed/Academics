#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template <typename T>
class BST {
private:
    struct Node {
        T value;
        Node* left;
        Node* right;

        Node(T val) : value(val), left(nullptr), right(nullptr) {}
    };

    Node* root;

    Node* insert(Node* node, T value) 
    {
        if (!node)
            return new Node(value);

        if (value < node->value)
            node->left = insert(node->left, value);
        
        else if (value > node->value)
            node->right = insert(node->right, value);

        int bf = balanceFactor(node);

        if (bf > 1 && value < node->left->value)
            return rotateRight(node);

        if (bf < -1 && value > node->right->value)
            return rotateLeft(node);

        if (bf > 1 && value > node->left->value) 
        {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }

        if (bf < -1 && value < node->right->value) 
        {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }

        return node;
    }

    Node* deleteNode(Node* node, T value) 
    {
        if (!node)
            return nullptr;

        if (value < node->value)
            node->left = deleteNode(node->left, value);
        
        else if (value > node->value)
            node->right = deleteNode(node->right, value);
        
        else 
        {
            if (!node->left) 
            {
                Node* temp = node->right;
                delete node;
                return temp;
            } 
            else if (!node->right) 
            {
                Node* temp = node->left;
                delete node;
                return temp;
            }

            Node* temp = findMin(node->right);
            node->value = temp->value;
            node->right = deleteNode(node->right, temp->value);
        }
        return node;
    }

    Node* findMin(Node* node) 
    {
        while (node->left)
            node = node->left;

        return node;
    }

    int findHeight(Node* node) 
    {
        if (!node)
            return 0;
        
        return 1 + max(findHeight(node->left), findHeight(node->right));
    }

    int balanceFactor(Node* node) 
    {
        return findHeight(node->left) - findHeight(node->right);
    }

    Node* rotateRight(Node* y) 
    {
        Node* x = y->left;
        Node* T2 = x->right;
        x->right = y;
        y->left = T2;
        return x;
    }

    Node* rotateLeft(Node* x) 
    {
        Node* y = x->right;
        Node* T2 = y->left;
        y->left = x;
        x->right = T2;
        return y;
    }

    bool search(Node* node, T value) 
    {
        if (!node)
            return false;
        
        if (node->value == value)
            return true;
        
        if (value < node->value)
            return search(node->left, value);
        
        return search(node->right, value);
    }

    bool isAVL(Node* node) 
    {
        if (!node)
            return true;

        int bf = balanceFactor(node);
        return (bf >= -1 && bf <= 1) && isAVL(node->left) && isAVL(node->right);
    }

    void inorder(Node* node) 
    {
        if (node) 
        {
            inorder(node->left);
            cout << node->value << " ";
            inorder(node->right);
        }
    }

    void preorder(Node* node) 
    {
        if (node) 
        {
            cout << node->value << " ";
            preorder(node->left);
            preorder(node->right);
        }
    }

    void postorder(Node* node) 
    {
        if (node) 
        {
            postorder(node->left);
            postorder(node->right);
            cout << node->value << " ";
        }
    }

public:
    BST() : root(nullptr) {}

    void insert(T value) 
    {
        root = insert(root, value);
    }

    void deleteNode(T value) 
    {
        root = deleteNode(root, value);
    }

    bool search(T value) 
    {
        return search(root, value);
    }

    bool isAVL() 
    {
        return isAVL(root);
    }

    void inorder() 
    {
        inorder(root);
        cout << endl;
    }

    void preorder() 
    {
        preorder(root);
        cout << endl;
    }

    void postorder() 
    {
        postorder(root);
        cout << endl;
    }
};

int main() 
{
    BST<int> bst;

    bst.insert(20);
    bst.insert(10);
    bst.insert(30);
    bst.insert(5);
    bst.insert(15);

    cout << "Inorder traversal: ";
    bst.inorder();

    cout << "Preorder traversal: ";
    bst.preorder();

    cout << "Postorder traversal: ";
    bst.postorder();

    cout << "Searching for 15: " << (bst.search(15) ? "Found" : "Not Found") << endl;
    cout << "Searching for 25: " << (bst.search(25) ? "Found" : "Not Found") << endl;

    cout << "Is AVL: " << (bst.isAVL() ? "Yes" : "No") << endl;

    bst.deleteNode(10);

    cout << "Inorder traversal after deletin 10: ";
    bst.inorder();

    cout << "Is AVL after deletion: " << (bst.isAVL() ? "Yes" : "No") << endl;

    return 0;
}
