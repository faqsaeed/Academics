#include <iostream>
#include <vector>
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
    int size;

    Node* insert(Node* node, T value) 
    {
        if (!node) 
            return new Node(value);

        if (value < node->value) 
            node->left = insert(node->left, value);

        else if (value > node->value) 
            node->right = insert(node->right, value);

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
        while (node && node->left) 
            node = node->left;

        return node;
    }

    void inorder(Node* node, vector<T>& elements) 
    {
        if (!node) 
            return;

        inorder(node->left, elements);
        elements.push_back(node->value);
        inorder(node->right, elements);
    }

    T findKthElement(Node* node, int k, int &count) {
        if (!node) 
            return T(); 

        T left = findKthElement(node->left, k, count);

        if (count == k) 
            return left;

        if (++count == k) 
            return node->value;

        return findKthElement(node->right, k, count);
    }

public:
    BST() : root(nullptr), size(0) {}

    void insert(T value) 
    {
        root = insert(root, value);
        size++;
    }

    void deleteNode(T value) 
    {
        root = deleteNode(root, value);
        size--;
    }

   
    float find_median() 
    {
        if (size == 0) 
        {
            cout << "BST is empty." << endl;
            return 0; 
        }
        
        int count = 0;
        if (size % 2 == 1) 
        
            return findKthElement(root, size / 2 + 1, count);

        else 
        {
            int leftMid = findKthElement(root, size / 2, count);
            count = 0; 
            int rightMid = findKthElement(root, size / 2 + 1, count);
            return (leftMid + rightMid) / 2.0;
        }
    }

 vector<T> merge(const BST& other) 
{
    vector<T> thisInorder, otherInorder, mergedResult;

    inorder(root, thisInorder);
    inorder(other.root, otherInorder);

    int i = 0, j = 0;
    while (i < thisInorder.size() && j < otherInorder.size()) 
    {
        if (thisInorder[i] < otherInorder[j]) 
            mergedResult.push_back(thisInorder[i++]);
        else 
            mergedResult.push_back(otherInorder[j++]);
    }

    while (i < thisInorder.size()) 
        mergedResult.push_back(thisInorder[i++]);

    while (j < otherInorder.size()) 
        mergedResult.push_back(otherInorder[j++]);

    return mergedResult;
}


};

int main() 
{
    BST<int> bst1;
    BST<int> bst2;

    bst1.insert(10);
    bst1.insert(20);
    bst1.insert(5);
    bst1.insert(15);
    bst1.insert(25);
    bst1.insert(1);

    bst2.insert(7);
    bst2.insert(3);
    bst2.insert(9);
    bst2.insert(2);
    bst2.insert(6);


    cout << "Median of bst1: " << bst1.find_median() << endl;

    cout << "Deleting 10 from bst1." << endl;
    bst1.deleteNode(10);
    cout << "Median of bst1 after deleting 10: " << bst1.find_median() << endl;

    cout << "Median of bst2: " << bst2.find_median() << endl;

    cout << "Merging bst1 and bst2..." << endl;
    vector<int> mergedResult = bst1.merge(bst2);

    cout << "Inorder traversal of merged BSTs: ";
    for (int val : mergedResult) 
    {
        cout << val << " ";
    }
    cout << endl;

    
    BST<int> emptyBST;
    cout << "Median of empty BST: " << emptyBST.find_median() << endl;
    
    BST<int> singleNodeBST;
    singleNodeBST.insert(42);
    cout << "Median of single-node BST: " << singleNodeBST.find_median() << endl;

    return 0;
}
