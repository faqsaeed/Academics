#include <iostream>
#include <vector>
using namespace std;

template<typename T>
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

	singly() :head(nullptr), tail(nullptr)
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
	
	void deleteNode(T val)
	{
		if (head == nullptr)
			return;
	
		Node* curr = head;
		while (curr)
		{
			if (curr->data == val)
            {
				deleteParticular(curr);
                return;
            }
			curr = curr->next;
		}
		cout << "\nValue doesn't exist in the node\n";
	}

	void deleteParticular(Node* nptr)
	{
		if (nptr->next == nullptr)
			delete nptr;

		Node* temp = nptr->next;
		nptr->data = nptr->next->data;
		nptr->next = nptr->next->next;
		delete temp;
		
	}

	void removeNthFromEnd(int n) 
    {
        Node* prev = nullptr;
        Node* curr = head;
    
        while (curr) 
        {
            if(n == count(curr))
            {
                if(curr == head)
                {
                    
                    Node* temp = curr;
                    head = head->next; 
                    delete temp;
                    return;
                }
                if(curr == tail)
                {
                    tail = prev;
                    delete tail->next;
                    tail->next = nullptr;
                    return;
                }
                prev->next = curr->next;
                delete curr;
                return;
            }
            prev = curr;
            curr = curr->next;
        }
    }

	int nextLargestValue(Node* home)
    {
        int toCheck = home->data;
        int max = 0;
        Node* curr = home;
        while(curr)
        {
            if(curr->data > max && curr->data > toCheck)
	    { 
                max = curr->data;
                return max;
            }
            curr = curr->next;
        }
        return max;
    }

    vector<int> nextLargerNodes() 
    {
        Node* current = this->head;
        vector<int> num1;
        while(current)
        {
            num1.push_back(nextLargestValue(current));
            current = current->next;
        }
        return num1;
    }
};



int main()
{
	singly<int> s1;
	s1.insertAtTail(80);
	s1.insertAtTail(180);
	s1.insertAtHead(45);
	s1.insertAtHead(25);
	s1.insertAtHead(35);
	s1.insertAtHead(75);
	s1.insertAtTail(200);
	s1.insertAtTail(490);
	s1.insertInorder(70);
	s1.insertInorder(10);
	cout << "\nBefore Removing\t";
	s1.print();

	s1.deleteNode(25);
	cout << "\nAfter Removing\t";

	s1.print();

	cout << endl;

	singly<int> s1;

    vector<int> num = s1.nextLargerNodes();
    cout << "\nVector List is as follow\t";
    for (const int& i : num) 
    {
        cout << i << "  ";
    }
    cout << endl;


}
