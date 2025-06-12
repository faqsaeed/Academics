#include <iostream>
#include <stack>
#include <queue>
using namespace std;
template <typename T>
class bst {
	struct treeNode {
		T data;
		treeNode* left, * right;
		treeNode(const T& obj) {
			data = obj;
			left = right = nullptr;
		}
	};
	treeNode* root;

//Search Parent Node
	bool getParentNode(const T& key, treeNode*& par){
		//par = nullptr;
		treeNode* curr = root;
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
	void printPreOrder(treeNode * curr) {
		if (curr)
		{
			cout << curr->data << " ";
			printPreOrder(curr->left);
			printPreOrder(curr->right);
		}
	}
	void printInOrder(treeNode* curr) {
		if (curr != nullptr) {
			//LNR
			printInOrder(curr->left);
			cout << (curr->data) << " ";
			printInOrder(curr->right);
		}
	}
	void printPostOrder(treeNode* curr) {
		if (curr != nullptr) {
			//LRN
			printPostOrder(curr->left);
			printPostOrder(curr->right);
			cout << (curr->data) << " ";
		}
	}
	void cleanup(treeNode* curr) 
    {
		if (curr != nullptr) 
        {
			cleanup(curr->left);
			cleanup(curr->right);
			delete curr;
		}
	}
	void copy(treeNode*& curr, treeNode* objptr) {
		if (objptr != nullptr) {
			curr = new treeNode(objptr->data);
			copy(curr->lchild, objptr->lchild);
			copy(curr->rchild, objptr->rchild);
		}
	}
	int numOfChild(treeNode* curr) {
		if (curr == nullptr)
			return -1;
		else
			return
			int(curr->left != nullptr) +
			int(curr->right != nullptr);
	}
	int height(treeNode* curr)
	{
		if (curr)
		{
			int left_height = height(curr->left);
			int right_height = height(curr->right);

			return 1 + max(left_height, right_height);
		}
		return -1;
	}
	void erase(const T& key, treeNode* &curr)
	{
	//Search for element to be deleted
		if (curr == nullptr)
			return;
		else if (key > curr->data)
			erase(key, curr->right);
		else if (key < curr->data)
			erase(key, curr->left);
		else
		{
		//Case:0 (deleting a node with no child i.e., leaf node)
			if (numOfChild(curr) == 0)
			{
//since pointer is passed by reference. So we don't need to set the parent pointer
				delete curr;
				curr = nullptr;
			}
		//Case:1 (deleting a node with 1 child)
			else if (numOfChild(curr) == 1)
			{
				if (curr->left)
				{
					treeNode* temp = curr;
					curr = curr->left;
					delete temp;
				}
				else
				{
					treeNode* temp = curr;
					curr = curr->right;
					delete temp;
				}
			}
		//Case:2 (deleting a node with 2 child nodes
			else
			{
				//1: Determine the successor Node. 
				treeNode* successor = curr->right;
				while (successor->left)
					successor = successor->left;
				//2: copy the data from successor to the node to be deleted.
				curr->data = successor->data;
				//3: delete the successor.
				erase(successor->data, curr->right);
			}
		}
	}

public:
//1: deletion
	void erase(const T& key)
	{
		erase(key, root); //pass the root by-reference
	}
//2: copy constructor
	bst(const bst<T>& obj) {
		//copy constructor
		copy(root, obj.root);
	}
//3: assignment operator
	const bst<T>& operator = (const bst<T>& obj) {
		cleanup(root);//uses post order
		copy(root, obj.root);//uses preorder
	}
//4: insertion
	void insert(const T& data) {
		treeNode* par = nullptr;
		if (getParentNode(data, par) == false) {
			//add new node as a child of parent
			//par contains the parent pointer
			treeNode* temp = new treeNode(data);
			if (par == nullptr) {//tree is empty
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
//5: inorder printing
	void printInOrder() {
		printInOrder(root);
	}
//6: preorder printing
	void printPreOrder(){
		printPreOrder(root);
	}
//7: post order printing
	void printPostOrder()
	{
		printPostOrder(root);
	}
//8: search function
	bool search(const T & key)
	{
		treeNode* curr = root;
		while (curr != nullptr)
		{
			if (curr->data == key)
				return true;
			else if (curr->data < key)
				curr = curr->right;
			else
				curr = curr->left;
		}
		return false;
	}
//9: Iterative inorder	
	

    void iterInOrder() {
    stack<treeNode*> s1;
    treeNode* curr = root;
    while (curr != nullptr || !s1.empty()) {
        while (curr != nullptr) {
            s1.push(curr);
            curr = curr->left;
        }
        curr = s1.top();
        s1.pop();
        cout << curr->data << " ";
        curr = curr->right;
    }
}
//10: level order traversal (print the tree level by level using queue)
	void leveOrder()
	{
		treeNode* curr;
		queue<treeNode*> q1;
		q1.push(root);
		while (!q1.empty())
		{
			curr = q1.front();
			q1.pop();
			cout << curr->data << endl;

			if (curr->left)
				q1.push(curr->left);
			if (curr->right)
				q1.push(curr->right);
		}
	}
//11: height of BST
	int height()
	{
		return height(root);
	}
//12: whether the given tree is BST or not.
//	bool isBST(treeNode * curr)
//	{
//		if (!curr)
//			return true;
////if the max value in the left subtree is greaer than or equals to the data of current Node
////then it is not a BST.
//		if (curr->left && maxValue(curr->left) >= curr->data)
//		{
//			return false;
//		}
////if the min value in the right subtree is less than or equals to the data of current Node
////then it is not a BST.
//		if (curr->right && minValue(curr->right) <= curr->data)
//		{
//			return false;
//		}
////repeat the above for all nodes in BST.
//		return isBST(curr->left) && isBST(curr->right);
//	}
//13: constructor
	bst() {
		root = nullptr;
	}
//14: destructor using clean-up function
	~bst() {
		cleanup(root);
	}
};
int main() {
    bst<int> tree;

    // Insert elements into the BST
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    // Print tree traversals
    cout << "In-order Traversal: ";
    tree.printInOrder();
    cout << endl;

    cout << "Pre-order Traversal: ";
    tree.printPreOrder();
    cout << endl;

    cout << "Post-order Traversal: ";
    tree.printPostOrder();
    cout << endl;

    // Search for elements
    cout << "Search 40: " << (tree.search(40) ? "Found" : "Not Found") << endl;
    cout << "Search 100: " << (tree.search(100) ? "Found" : "Not Found") << endl;

    // Height of the BST
    cout << "Height of the BST: " << tree.height() << endl;

    // Level-order traversal
    cout << "Level-order Traversal: " << endl;
    tree.leveOrder();
    cout << endl;

    // Iterative In-order traversal
    cout << "Iterative In-order Traversal: ";
    tree.iterInOrder();
    cout << endl;

    // Delete a node
    cout << "Deleting 40..." << endl;
    tree.erase(40);

    cout << "In-order Traversal after deletion: ";
    tree.printInOrder();
    cout << endl;

    return 0;
}
