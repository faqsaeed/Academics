

#include <iostream>
using namespace std;

struct node {
    int data;
    node* next;

    node(int element)
    {
        data = element;
        next = nullptr;
    }
};
class list
{
public:

    node* tail;
    node* head;

    list()
    {
        head = nullptr;
        tail = nullptr;
    }

    void insertAtHead(int const element)
    {
        if (head == nullptr)
        {
            node* n = new node(element);
            head = n;
            tail = n;
            return;
        }
        node* n = new node(element);
        n->next = head;
        head = n;
    }

    void insertAtTail(const int element)
    {
        if (head == nullptr)
        {
            insertAtHead(element);
            return;
        }
        node* n = new node(element);
        tail->next = n;
        tail = tail->next;
    }

    void deleteAtHead()
    {
        if (head == nullptr)
            return;

        node* temp = head;
        head = head->next;
        delete temp;
    }

    void deleteAtTail()
    {

        node* curr = head->next;
        node* prev = head;
        while (curr->next != nullptr)
        {
            prev = curr;
            curr = curr->next;
        }
        delete curr;
        prev->next = nullptr;
        tail = prev;
    }

    void printForward() const
    {
        node* temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    int size() const
    {
        if (head == nullptr)
            return 0;
        node* temp = head;
        int count = 1;
        while (temp->next != nullptr)
        {
            count++;
            temp = temp->next;
        }
        return count;
    }

    int getMiddle()
    {
        if (head == nullptr)
            return -1;
        int count = this->size();
        count = count / 2;
        node* temp = head;
        for (int i = 1; i < count; i++)
        {
            temp = temp->next;
        }
        return temp->data;
    }

    bool IsEmpty()
    {
        if (head == nullptr && tail == nullptr)
            return true;
        else
            return false;
    }

    void InsertBefore(const int val, const int key)
    {
        if (head == nullptr)
        {
            insertAtHead(val);
            return;
        }
        node* temp = head;
        node* prev = temp;
        while (temp->next != nullptr && temp->data != key)
        {
            prev = temp;
            temp = temp->next;
        }

        if (temp->next == nullptr)
            insertAtTail(val);
        else
        {
            node* n = new node(val);
            prev->next = n;
            n->next = temp;
        }
    }

    void InsertAfter(const int val, const int key)
    {
        if (head == nullptr)
        {
            insertAtHead(val);
            return;
        }
        node* temp = head;
        node* prev = temp;
        while (temp->next != nullptr && temp->data != key)
        {
            prev = temp;
            temp = temp->next;
        }

        if (temp->next == nullptr)
            insertAtTail(val);
        else
        {
            node* n = new node(val);
            n->next = temp->next;
            temp->next = n;
        }
    }


    int getMax() const
    {
        if (head == nullptr)
            return -1;
        node* temp = head;
        int max = head->data;
        while (temp->next != nullptr)
        {
            if (temp->data > max)
                max = temp->data;
            temp = temp->next;
        }
        return max;
    }

    int getMin() const
    {
    if (head == nullptr)
        return -1;
    node* temp = head;
    int min = head->data;
    while (temp->next != nullptr)
    {
        if (temp->data < min)
            min = temp->data;
        temp = temp->next;
    }
    return min;
    }

    int getAvg()
    {
        if (head == nullptr)
            return 0;
        int total = this->size();
        node* temp = head;
        int sum = 0;
        while (temp != nullptr)
        {
            sum += temp->data;
            temp = temp->next;
        }
        return sum / total;
    }

    bool Swap(int LeftIndex, int RightIndex)
    {
        int total = this->size();
        if (head == nullptr || LeftIndex ==RightIndex || LeftIndex < 0 || RightIndex < 0 || LeftIndex > total || RightIndex > total)
            return false;
       
        node* first = head;
        node* prev1 = nullptr, * prev2 = nullptr;

        for (int i = 0; i < LeftIndex; i++)
        {
            prev1 = first;
            first = first->next;
        }
        node* last = head;
        for (int i = 0; i < RightIndex; i++)
        {
            prev2 = last;
            last = last->next;
        }
        if (prev1 != nullptr) 
            prev1->next = last;
        else 
            head = last;

        if (prev2 != nullptr) 
            prev2->next = first;
        else 
            head = first;

        node* temp = last->next;
        last->next = first->next;
        first->next = temp;

        if (first == tail) 
            tail = last;
        else if (last == tail) 
            tail = first;

        return true;
    }

    void Detructor()
    {
        if (head == nullptr)
            return;


        node* temp = head;
        while (head != nullptr)
        {
            head = temp->next;
            delete temp;
        }
    }

};


int main() {
    list ll;

  
    ll.insertAtHead(3);
    ll.insertAtHead(2);
    ll.insertAtTail(4);
    ll.insertAtTail(5);
    cout << "List after inserting at head and tail: ";
    ll.printForward();

    ll.deleteAtHead();
    cout << "List after deleting from head: ";
    ll.printForward();


    ll.deleteAtTail();
    cout << "List after deleting from tail: ";
    ll.printForward();

    ll.InsertAfter(7,3);
    cout << "List after inserting 7 after 3: ";
    ll.printForward();

    ll.InsertBefore(6, 7);
    cout << "List after inserting 6 before 7: ";
    ll.printForward();

    cout << "Middle element: " << ll.getMiddle() << endl;

    cout << "Size of the list: " << ll.size() << endl;

    cout << "Is the list empty? " << (ll.IsEmpty() ? "Yes" : "No") << endl;

    cout << "Max value in the list: " << ll.getMax() << endl;

    cout << "Min value in the list: " << ll.getMin() << endl;

    cout << "Average value in the list: " << ll.getAvg() << endl;

    cout << "List before swapping nodes at index 0 and 2: ";
    ll.printForward();

    ll.Swap(0, 2);

    cout << "List after swapping nodes at index 0 and 2: ";
    ll.printForward();

    return 0;
}