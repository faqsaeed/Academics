#include <iostream>
#include <vector>
#include <queue>

using namespace std;

template <typename K, typename V>

class SpecialBST {
private:
    struct Node {
        K key;
        V data;
        Node* left;
        Node* right;
        Node(K k, V v) : key(k), data(v), left(nullptr), right(nullptr) {}
    };
    
    Node* root;

    void rotateToRoot(Node* node) 
    {
        if (node == root) 
            return;

        Node* parent = nullptr;
        Node* grandparent = nullptr;
        Node** linkToNode = &root;  

        while (*linkToNode != node) 
        {
            grandparent = parent;
            parent = *linkToNode;

            if (node->key < parent->key) 
                linkToNode = &parent->left;
            else 
                linkToNode = &parent->right;
        } // linktonode pointer is now pointing at the node that is to be made new root this is to assign values to parent and grandparent node

        if (parent->left == node) 
        {
            parent->left = node->right;
            node->right = parent;
        } 
        else 
        {
            parent->right = node->left;
            node->left = parent;
        } 
        //above two j move the parent of the new root to either its left or its right based upon the value

        if (grandparent) 
        {
            if (grandparent->left == parent) 
                grandparent->left = node;
            else 
                grandparent->right = node;
        } 
        else 
        {
            root = node;
        }
    }

    bool insertHelper(Node*& node, K key, V data)
    {
        if (!node) 
        {
            node = new Node(key, data);
            rotateToRoot(node);
            return true;
        }
        if (key == node->key) 
            return false;  // Duplicate key

        bool inserted;

        if (key < node->key) 
            inserted = insertHelper(node->left, key, data);
        else 
            inserted = insertHelper(node->right, key, data);

        if (inserted) 
            rotateToRoot(node);

        return inserted;
    }

    Node* searchHelper(Node* node, K key) 
    {
        Node* lastVisited = nullptr;
        while (node) 
        {
            lastVisited = node;
            if (key == node->key) 
            {
                rotateToRoot(node);
                return node;
            } 
            else if (key < node->key) 
                node = node->left;
            else 
                node = node->right;
        }

        if (lastVisited) 
            rotateToRoot(lastVisited);
        return nullptr;
    }

    // Helper function to delete recursively
    bool deleteHelper(Node*& node, K key) 
    {
        if (!node)
            return false;

        if (key < node->key) 
            return deleteHelper(node->left, key);

        else if (key > node->key) 
            return deleteHelper(node->right, key);
        
        if (!node->left || !node->right) 
        {
            Node* temp = node;
            node = node->left ? node->left : node->right;
            rotateToRoot(temp);
            delete temp;
            return true;
        } 
        else 
        {
            Node* successor = node->right;
            while (successor->left) successor = successor->left;
            node->key = successor->key;
            node->data = successor->data;
            return deleteHelper(node->right, successor->key);
        }
    }

    void levelOrder(Node* node, vector<V>& datas) 
    {
        if (!node) 
            return;
                
        queue<Node*> q;
        q.push(node);
        while (!q.empty()) 
        {
            Node* current = q.front();
            q.pop();
            datas.push_back(current->data);

            if (current->left) 
                q.push(current->left);

            if (current->right) 
                q.push(current->right);
        }
    }

    // Helper function for inorder traversal
    void inorder(Node* node, vector<V>& datas) const
    {
        if (!node) 
            return;

        inorder(node->left, datas);
        datas.push_back(node->data);
        inorder(node->right, datas);
    }

    // Helper function to free memory
    void destroyTree(Node* node) 
    {
        if (!node) 
            return;
        
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }

public:
    SpecialBST() : root(nullptr) {}

    bool insert(K key, V data) 
    {
        return insertHelper(root, key, data);
    }

    V* search(K key) 
    {
        Node* foundNode = searchHelper(root, key);
        return foundNode ? &foundNode->data : nullptr;
    }

    bool deleteKey(K key) 
    {
        return deleteHelper(root, key);
    }

    vector<V> getdatasLevelWise() 
    {
        vector<V> datas;
        levelOrder(root, datas);
        return datas;
    }

    vector<V> getValuesInOrder() const
    {
        vector<V> datas;
        inorder(root, datas);
        return datas;
    }

    ~SpecialBST() 
    {
        destroyTree(root);
    }
};


