#include <iostream>
using namespace std;

template <typename T>
class singly
{
	struct Node
	{
		T data;
		Node* next;
		Node(T val, Node* nptr = nullptr) : data(val), next(nptr)
		{}
	};
	Node* head, * tail;
public:

	singly()  :head(nullptr), tail(nullptr)
	{}

	void insertAtHead(const T val)
	{
		Node* n = new Node(val); //parameterized constr
		if (head == nullptr)
		{
			head = n;
			tail = n;
			return;
		}
		n->next = head;
		head = n;
	}
	void print()
	{
		Node* temp = head;
		while (temp != nullptr)
		{
			cout << temp->data << " ";
			temp = temp->next;
		}
	}
	void insertAtTail(const T val)
	{
		if (head == nullptr)
		{
			insertAtHead(val);
			return;
		}
		Node* n = new Node(val);
		tail->next = n;
		tail = tail->next;
	}
	void deleteAtHead()
	{
		if (head == nullptr)
			return;
		Node* temp = head;
		head = head->next;
		delete temp;
	}

	void insertInorder(T val)
	{
		if (head != nullptr && val < head->data)
		{
			insertAtHead(val);
		}
		else if (val > tail->data)
		{
			insertAtTail(val);
		}
		Node* curr = head->next;
		Node* prev = head;
		while (curr->data < val)
		{
			prev = curr;
			curr = curr->next;
		}
		Node* n = new Node(val, curr);
		prev->next = n;
	}

	void deleteAtTail()
	{
		if (head == nullptr)
			return;
		//only single node case
		Node* curr = head->next;
		Node* prev = head;
		while (curr->next != nullptr)
		{
			prev = curr;
			curr = curr->next;
		}
		delete curr;
		prev->next = nullptr;
		tail = prev;
	}

	void deleteParticular(Node* nptr)
	{
    	if (nptr->next == nullptr)
    	{
        	delete nptr;
        	return;
    	}

    	Node* temp = nptr->next;
    	nptr->data = temp->data;
    	nptr->next = temp->next;
    	delete temp;
	}

	void deleteSubSequence()
	{
    	Node* temp = head;
    	while (temp && temp->next) 
    	{
        	if (temp->data == 0 || temp->next->data == 0)
            	deleteParticular(temp);
        	else
            	temp = temp->next;
    	}
	}
};


int main()
{
	singly<int> s1;
	s1.insertAtHead(1);
	s1.insertAtHead(0);
	s1.insertAtHead(1);
	s1.insertAtHead(0);
	s1.insertAtHead(0);
	s1.insertAtHead(1);
	s1.insertAtHead(1);
	s1.print();
	cout << endl;
	s1.deleteSubSequence();
	cout << "After Deletion \t";
	s1.print();
	cout << endl;

}
