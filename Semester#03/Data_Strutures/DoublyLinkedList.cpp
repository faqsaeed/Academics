#include <iostream>
using namespace std;

template <typename T>
class DoublyLinkedList 
{
private:
    class Node 
    {
    public:
        T data;
        Node* next;
        Node* prev;

        Node(T value) : data(value), next(nullptr), prev(nullptr) {}
    };

    Node* head;
    Node* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    ~DoublyLinkedList()
    {
        Node* current = head;

        while (current)
        {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }

    class Iterator {
    private:
        Node* current;

    public:
        Iterator(Node* node) : current(node) {}

        Iterator& operator++()
        {
            if (current) current = current->next;
            return *this;
        }

        Iterator operator++(int)
        {
            Iterator temp = *this;
            if (current) current = current->next;
            return temp;
        }

        Iterator& operator--()
        {
            if (current) 
                current = current->prev;

            return *this;
        }

        Iterator operator--(int)
        {
            Iterator temp = *this;
            if (current) 
                current = current->prev;

            return temp;
        }

        T& operator*() const
        {
            return current->data;
        }

        bool operator==(const Iterator& rhs) const
        {
            return current == rhs.current;
        }

        bool operator!=(const Iterator& rhs) const
        {
            return current != rhs.current;
        }
    };

    Iterator begin() const
    {
        return Iterator(head);
    }

    Iterator end() const
    {
        return Iterator(nullptr);
    }

    void insert(T value)
    {
        Node* newNode = new Node(value);
        if (!head)
        {
            head = tail = newNode;
        }
        else
        {
            Node* current = head;

            while (current && current->data < value)
            {
                current = current->next;
            }

            if (!current)
            {
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;
            }
            else if (current == head)
            {
                newNode->next = head;
                head->prev = newNode;
                head = newNode;
            }
            else
            {
                newNode->next = current;
                newNode->prev = current->prev;
                current->prev->next = newNode;
                current->prev = newNode;
            }
        }
    }

    void printForward() const
    {
        Node* current = head;
        while (current)
        {
            std::cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    void printBackward() const
    {
        Node* current = tail;

        while (current)
        {
            cout << current->data << " ";
            current = current->prev;
        }

        cout << endl;
    }

    bool search(T value) const
    {
        Node* start = head;
        Node* end = tail;

        while (start != end && start->prev != end)
        {
            if (start->data == value || end->data == value)
                return true;

            start = start->next;
            end = end->prev;
        }
        return false;
    }

    void erase(T value)
    {
        Node* current = head;
        while (current)
        {
            if (current->data == value)
            {
                if (current == head)
                {
                    head = head->next;
                    if (head) 
                        head->prev = nullptr;
                }
                else if (current == tail) 
                {
                    tail = tail->prev;
                    if (tail) 
                        tail->next = nullptr;
                }
                else 
                {
                    current->prev->next = current->next;
                    current->next->prev = current->prev;
                }
                delete current;
                return;
            }
            current = current->next;
        }
    }
};

template <typename T>
void printList(DoublyLinkedList<T>& list)
{

    for (typename DoublyLinkedList<T>::Iterator it = list.begin(); it != list.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

template <typename T>
void intersectionList(DoublyLinkedList<T>& a, DoublyLinkedList<T>& b, DoublyLinkedList<T>& c)
{
    for (typename DoublyLinkedList<T>::Iterator itA = a.begin(); itA != a.end(); itA++)
    {

        for (typename DoublyLinkedList<T>::Iterator itB = b.begin(); itB != b.end(); itB++)
        {
            if (*itA == *itB)
            {
                c.insert(*itA);
            }
        }
    }
}

template <typename T>
void unionList(DoublyLinkedList<T>& a, DoublyLinkedList<T>& b, DoublyLinkedList<T>& c)
{
    for (typename DoublyLinkedList<T>::Iterator itA = a.begin(); itA != a.end(); itA++)
    {
        c.insert(*itA);
    }
    for (typename DoublyLinkedList<T>::Iterator itB = b.begin(); itB != b.end(); itB++)
    {
        if (c.search(*itB))
            continue;
        else
            c.insert(*itB);

    }
}

template <typename T>
void differenceList(DoublyLinkedList<T>& a, DoublyLinkedList<T>& b, DoublyLinkedList<T>& c)
{
    for (typename DoublyLinkedList<T>::Iterator itA = a.begin(); itA != a.end(); itA++)
    {
        c.insert(*itA);
    }
    for (typename DoublyLinkedList<T>::Iterator itB = b.begin(); itB != b.end(); itB++)
    {
        if (c.search(*itB))
            c.erase(*itB);
    }
}

template <typename T>
void bubbleSort(DoublyLinkedList<T>& a)
{
    bool swapped;
    typename DoublyLinkedList<T>::Iterator end = a.end();
    
    do 
    {
        swapped = false;
        typename DoublyLinkedList<T>::Iterator current = a.begin();
        typename DoublyLinkedList<T>::Iterator next = a.begin();
        
        if (next != end) 
        {
            ++next;
        }
        
        while (next != end) 
        {
            if (*current < *next) 
            {  
                swap(*current, *next);
                swapped = true;
            }
            ++current;
            ++next;
        }
        
        --end;
    } while (swapped);
}

int main() {
    DoublyLinkedList<int> list;
    list.insert(5);
    list.insert(3);
    list.insert(8);
    list.insert(1);


    DoublyLinkedList<int> notlist;
    notlist.insert(2);
    notlist.insert(5);
    notlist.insert(7);
    notlist.insert(6);

    cout << "List1:\t";
    printList(list);

    cout << "List2:\t";
    printList(notlist);

    DoublyLinkedList<int> mylist;
    intersectionList(list, notlist, mylist);
    cout << "After Intersection:\t";
    printList(mylist);

    DoublyLinkedList<int> notmylist;
    unionList(list, notlist, notmylist);
    cout << "After Union:\t";
    printList(notmylist);

    DoublyLinkedList<int> mlist;
    differenceList(list, notlist, mlist);
    cout << "After Difference:\t";
    printList(mlist);

    bubbleSort(list);
    printList(list);


    return 0;
}