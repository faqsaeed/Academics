#include <iostream>
using namespace std;

struct node {
    char data;
    node* next;

    node(char element)
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

    void insertAtHead(char element)
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

    void insertAtTail(const char element)
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

    void split(list& firstHalf, list& secondHalf)
    {
        if (head == nullptr) 
            return;

        int count = this->size();
        int half = count / 2;
        node* temp = head;

        for (int i = 0; i < half; i++)
        {
            firstHalf.insertAtTail(temp->data);
            temp = temp->next;
        }

        for (int i = half; i < count; i++)
        {
            secondHalf.insertAtTail(temp->data);
            if(temp->next != nullptr)
                temp = temp->next;
        }
    }

    void merge(list& firstHalf, list& secondHalf)
    {
        
        node* temp = firstHalf.head;
        int half = firstHalf.size();
        for(int i = 0; i < half; i++)        
        {
            this->insertAtTail(temp->data);
            temp = temp->next;
        }

        temp = secondHalf.head;
        
        half = firstHalf.size();
        for(int i = 0; i < half; i++)        
        {
            this->insertAtTail(temp->data);
            temp = temp->next;
        }
    }
};

int main() {
    list l1;
    
    // Testing insertion at head and tail
    l1.insertAtHead('C');
    l1.insertAtTail('D');
    l1.insertAtHead('B');
    l1.insertAtHead('A');
    cout << "List after insertion: ";
    l1.printForward(); 
    l1.deleteAtHead();
    cout << "List after deleting from head: ";
    l1.printForward();  

    l1.deleteAtTail();
    cout << "List after deleting from tail: ";
    l1.printForward();  


    cout << "Total characters in the l1: " << l1.size() << endl; 


    
    list firstHalf, secondHalf;

    l1.split(firstHalf, secondHalf);
    cout << "First half after split: ";
    firstHalf.printForward();  
    cout << "Second half after split: ";
    secondHalf.printForward(); 

    list mergedList;
    mergedList.merge(firstHalf, secondHalf);
    cout << "Merged list: ";
    mergedList.printForward();  

    return 0;
}