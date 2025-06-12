#include <iostream>
using namespace std;

template <typename T>
class Stack {
private:
    struct Node 
    {
        T data;
        Node* next;
        Node(T val) : data(val), next(nullptr) {}
    };
    Node* top;
    int size;
    int min;

public:
    Stack() : top(nullptr), size(0), min(0) {}

    ~Stack()
    {
        while (!IsEmpty()) 
	    {
            Pop();
        }
    }

    void Push(T val)
    {
        Node* newNode = new Node(val);
        newNode->next = top;
        top = newNode;
        size++;
        return;
    }

    void Pop() 
    {
        if (IsEmpty()) 
        {
            cout << "Stack underflow\n";
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
        size--;
        return ;
    }

    T Top() const
    {
        if (IsEmpty()) 
            return -1;
        else
            return top->data;

    }

    int getSize() const
    {
        return size;
    }

    bool IsEmpty() const
    {
        return top == nullptr;
    }
};

template <typename T>
class MinStack{
private:
    Stack<T> stack;
    Stack<T> min;

public:

    void push(const T val) 
    {
        stack.Push(val);

        if(stack.getSize() == 0 || val < min.Top())
            min.Push(val);
    }

    void pop()
    {
        if(min.Top() == stack.Top())
            min.Pop();
        
        stack.Pop();
    }

    T top() const
    {
        if(!stack.IsEmpty())
            return stack.Top();
    }

    T getMin() const
    {
        if(!stack.IsEmpty())
            return min.Top();
        else
            cout << "Stack is empty";
        
        return 0;
    }

};
int main()
{
    MinStack<int> ms1;

    cout << "Minimum value is " << ms1.getMin() << endl;
    ms1.push(-23); 
    cout << "Minimum value is " << ms1.getMin() << endl;

    ms1.push(-25); 
    ms1.push(23); 
    ms1.push(0); 

    cout << "Minimum value is " << ms1.getMin() << endl;

    ms1.push(-1223);

    cout << "Minimum value is " << ms1.getMin() << endl;

    ms1.pop();

    cout << "Minimum value is " << ms1.getMin() << endl;



}
