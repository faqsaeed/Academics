#include <iostream>
#include<string>
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
    int capacity;

public:
    Stack(int size = 10) : top(nullptr), size(0), capacity(size) {}

    ~Stack() {
        while (!IsEmpty())
        {
            Pop();
        }
    }

    bool Push(T val) {
        if (IsFull())
        {
            cout << "Stack overflow\n";
            return false;
        }
        Node* newNode = new Node(val);
        newNode->next = top;
        top = newNode;
        size++;
        return true;
    }

    bool Pop() {
        if (IsEmpty())
        {
            cout << "Stack underflow\n";
            return false;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
        size--;
        return true;
    }

    bool Top(T& val) {
        if (IsEmpty()) {

            return false;
        }
        val = top->data;
        return true;
    }

    bool IsEmpty() {
        return top == nullptr;
    }

    bool IsFull() {
        return size == capacity;
    }
};

bool check(string expression)
{
    int num = 0;
    Stack<char> s1;
    int size = expression.length();
    for (int i = 0; i < size; i++)
    {

        if (expression[i] == '(' || expression[i] == '[' || expression[i] == '{')
        {
            num++;
            s1.Push(expression[i]);
            continue;
        }
        if (expression[i] == ')' || expression[i] == '}' || expression[i] == ']')
        {
            if (s1.IsEmpty())
            {
                return false;
            }
            char ch;
            s1.Top(ch);

            if (expression[i] == ')' && ch == '(' || expression[i] == '}' && ch == '{' || expression[i] == ']' && ch == '[')
            {
                s1.Pop();
                num--;
                
            }
            else
            {
                return false;
            }
        }
    }
    return num == 0;
}
int prec(char c) {
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

string infixtopostfix(string s)
{
    string result;
    Stack<char> s1;
    for (int i = 0; i < s.length(); i++)
    {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9'))
        {
            result += s[i];
            continue;
        }
        else if (s[i] == '(')
            continue;

        else if (s[i] == ')')
        {
            while (!(s1.IsEmpty()))
            {
                char ch;
                s1.Top(ch);
                result += ch;
                s1.Pop();
            }
        }

        else
        {
            while (1) {
                char ch;
                s1.Top(ch);
                if (!s1.IsEmpty() && prec(s[i]) < prec(ch) || !s1.IsEmpty() && prec(s[i]) == prec(ch))
                {
                    result += ch;
                    s1.Pop();

                }
                else
                    break;
            }
            s1.Push(s[i]);
        }
    }
    while (!s1.IsEmpty()) 
    {
        char ch;
        s1.Top(ch);
        result += ch;
        s1.Pop();
    }
    return result;
}

int evaluate_postfix(string postfix)
{
    int result = 0;
    Stack<int> s1;
    for (int i = 0; i < postfix.length(); i++)
    {
        if (postfix[i] >= '0' && postfix[i] <= '9')
        {
            int lol;
            s1.Push(postfix[i] - 48);
        }
        else
        {
            char ch = postfix[i];
            int num1, num2;
            s1.Top(num1);
            s1.Pop();
            s1.Top(num2);
            s1.Pop();
            cout << ch << " " << num1 << " " << num2;
            int to;
            if (ch == '+')
            {
                to = num1 + num2;
                s1.Push(to);
            }
            else if(ch == '*')
            {
                to = num1 * num2;
                result += to;
                s1.Push(to);
            }
            else if (ch == '/')
            {
                to = num2 / num1;
                s1.Push(to);
            }
            else if (ch == '-')
            {
                to = num2 - num1;
                s1.Push(to);
            }
            else if (ch == '^')
            {
                to = num2 ^ num1;
                s1.Push(to);
            }
        }
    }
    s1.Top(result);
    return result;
}

int main()
{
    string a;
    cout << "enter string:\t";
    getline(cin, a);
    int choice = 0;
    cout << "1. Parenthesis_Check\n2. Infix_to_Postfix\n3. Evaluate_Postfix:\n";
    cin >> choice;
    
    if (choice == 1)
        cout << (check(a) ? "It is in right order" : "Wrong order");

    else if (choice == 2)
    {
        string result = infixtopostfix(a);
        cout << result;
    }
    else if (choice == 3)
    {
        int num = evaluate_postfix(a);
        cout << "answer is " << num;
    }
    else
    {
        cout << "invalid choice";
    }
}