#include <iostream>
using namespace std;

template <typename T>
struct treeNode {
    T data;
    treeNode* left;
    treeNode* right;

    treeNode(const T& obj) {
        data = obj;
        left = right = nullptr;
    }
};

template <typename T>
class bst {
    treeNode<T>* root;

    // Search Parent Node
    bool getParentNode(const T& key, treeNode<T>*& par) {
        par = nullptr;
        treeNode<T>* curr = root;
        while (curr != nullptr) {
            if (key == curr->data)
                return true;
            else if (key < curr->data) {
                par = curr;
                curr = curr->left;
            }
            else {
                par = curr;
                curr = curr->right;
            }
        }
        return false;
    }




    int secondLargestValue(treeNode<T>* root)
    {

        while (root) 
        {
            if (root->right == nullptr && root->left) 
            {
                root = root->left;

                while (root->right) 
                    root = root->right;

                return root->data;
            }

            if (root->right && root->right->right == nullptr && root->right->left == nullptr) 
                return root->data;

            root = root->right;
        }

        return -1; 
    }


   

    treeNode<T>* findLCA(treeNode<T>* node, const T& node1, const T& node2) 
    {
        while (node != nullptr) 
        {
            if (node1 < node->data && node2 < node->data)
                node = node->left;

            else if (node1 > node->data && node2 > node->data)
                node = node->right;

            else
                return node;
        }
        return nullptr;
    }
public:
    bst() : root(nullptr) {}

    void insert(const T& data) {
        treeNode<T>* par = nullptr;
        if (!getParentNode(data, par)) {
            treeNode<T>* temp = new treeNode<T>(data);
            if (par == nullptr) { // Tree is empty
                root = temp;
            }
            else {
                if (par->data < data) {
                    par->right = temp;
                }
                else {
                    par->left = temp;
                }
            }
        }
    }

    treeNode<T>* findLCA(const T& node1, const T& node2) 
    {
        return findLCA(root, node1, node2);
    }

    treeNode<T>* getRoot() const 
    {
        return root;
    }

    int secondLargestValue()
    {
        return secondLargestValue(root);
    }
};

int main() {
    bst<int> t1;
    t1.insert(5);
    t1.insert(10);
    t1.insert(20);
    t1.insert(15);
    t1.insert(30);

    treeNode<int>* lca = t1.findLCA(10, 30);

    if (lca) {
        cout << "LCA of 10 and 30 is: " << lca->data << endl;
    }
    else {
        cout << "LCA not found." << endl;
    }


    cout << "Second largest value of the BST: " << t1.secondLargestValue() << endl;

    bst<int> t2;

    cout << "Second largest value of an empty BST: " << t2.secondLargestValue() << endl;;
    
    t2.insert(5);
    cout << "Second largest value of a BST with only one element: " << t2.secondLargestValue() << endl;;

    t2.insert(6);
    //t2.insert(4);
    cout << "Second largest value of a BST with two element: " << t2.secondLargestValue() << endl;;


    return 0;
}
