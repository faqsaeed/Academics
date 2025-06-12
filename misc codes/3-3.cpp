#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class bst {
    struct treeNode {
        T data;
        treeNode* left;
        treeNode* right;

        treeNode(const T& obj) {
            data = obj;
            left = right = nullptr;
        }
    };

    treeNode* root;

    // Search Parent Node
    bool getParentNode(const T& key, treeNode*& par) {
        par = nullptr;
        treeNode* curr = root;
        while (curr != nullptr) {
            if (key == curr->data)
                return true;
            else if (key < curr->data) {
                par = curr;
                curr = curr->left;
            } else {
                par = curr;
                curr = curr->right;
            }
        }
        return false;
    }

    void inOrderTraversal(treeNode* node, vector<T>& result) 
    {
        if (node == nullptr)
            return;
        
        inOrderTraversal(node->left, result);
        result.push_back(node->data);
        inOrderTraversal(node->right, result);
    }

public:
    bst() : root(nullptr) {}

    void insert(const T& data) 
    {
        treeNode* par = nullptr;

        if (!getParentNode(data, par)) 
        {
            treeNode* temp = new treeNode(data);
            if (par == nullptr)  // Tree is empty
                root = temp;
            else 
            {
                if (par->data < data) 
                    par->right = temp;
                else 
                    par->left = temp;
            }
        }
    }

    vector<T> inOrderTraversal() 
    {
        vector<T> result;
        inOrderTraversal(root, result);
        return result;
    }

    treeNode* getRoot() const {
        return root;
    }

    vector<T> mergeBSTs(treeNode* root1, treeNode* root2) 
    {
        vector<T> inOrder1, inOrder2;

        inOrderTraversal(root1, inOrder1);
        inOrderTraversal(root2, inOrder2);

        return mergeSortedVectors(inOrder1, inOrder2);
    }

   vector<T> mergeSortedVectors(const vector<T>& v1, const vector<T>& v2)
    {
        vector<T> merged;
        int i = 0, j = 0;

        while (i < v1.size() && j < v2.size())
        {
            if (v1[i] < v2[j])
            {
                merged.push_back(v1[i]);
                i++;
            }
            else if (v1[i] > v2[j])
            {
                merged.push_back(v2[j]);
                j++;
            }
            else
            {
                merged.push_back(v1[i]);
                i++;
                j++;
            }
        }

        while (i < v1.size())
        {
            merged.push_back(v1[i]);
            i++;
        }

        while (j < v2.size())
        {
            merged.push_back(v2[j]);
            j++;
        }

        return merged;
    }

};

int main() {
    bst<int> bst1, bst2;

    bst1.insert(3);
    bst1.insert(1);
    bst1.insert(5);

    bst2.insert(4);
    bst2.insert(2);
    bst2.insert(6);

    vector<int> merged = bst1.mergeBSTs(bst1.getRoot(), bst2.getRoot());

    for (int val : merged) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
