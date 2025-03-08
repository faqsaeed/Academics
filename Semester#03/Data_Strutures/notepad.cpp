#include <iostream>
#include <fstream>
#include "conio.h"

using namespace std;

struct Node
{
    char data;
    Node* prev;
    Node* next;
    Node(char c) : data(c), prev(nullptr), next(nullptr) {}
};

class Notepad
{
private:
    Node* head;
    Node* tail;
    Node* cursor;
    int cursorIndex;

public:
    Notepad() : head(nullptr), tail(nullptr), cursorIndex(0)
    {
        cursor = new Node('|');
        head = cursor;
        tail = cursor;
    }

    void insertChar(char c)
    {
        Node* newNode = new Node(c);

        if (head == cursor)
        {
            head = newNode;
            newNode->next = cursor;
            cursor->prev = newNode;
            cursorIndex++;
        }
        else if (tail == cursor)
        {
            cursor->prev->next = newNode;
            newNode->prev = cursor->prev;
            newNode->next = cursor;
            cursor->prev = newNode;
            cursorIndex++;
        }
        else
        {
            newNode->next = cursor;
            newNode->prev = cursor->prev;
            cursor->prev = newNode;
            newNode->prev->next = newNode;
            cursorIndex++;
        }
    }

    void deleteChar()
    {
        if (head == cursor)
            return;

        if (cursor->prev == head)
        {
            head = cursor;
            delete cursor->prev;
            cursor->prev = nullptr;
            cursorIndex--;
            return;
        }

        cursor->prev = cursor->prev->prev;
        delete cursor->prev->next;
        cursor->prev->next = cursor;
        cursorIndex--;

    }

    void moveCursorLeft()
    {
        if (cursor == head || cursor == nullptr)
            return;

        Node* prevNode = cursor->prev;

        if (cursor == tail)
            tail = prevNode;

        if (cursor->next != nullptr)
            cursor->next->prev = cursor->prev;


        if (cursor->prev != nullptr)
            cursor->prev->next = cursor->next;


        cursor->next = prevNode;
        cursor->prev = prevNode->prev;

        if (prevNode->prev != nullptr)
            prevNode->prev->next = cursor;

        prevNode->prev = cursor;

        if (prevNode == head)
            head = cursor;


        cursorIndex--;
    }

    // Move cursor right
    void moveCursorRight()
    {
        if (cursor == tail || cursor == nullptr)
            return;

        Node* nextNode = cursor->next;

        if (cursor == head)
            head = nextNode;

        if (cursor->prev != nullptr)
            cursor->prev->next = cursor->next;


        cursor->next->prev = cursor->prev;
        cursor->prev = nextNode;
        cursor->next = nextNode->next;

        if (nextNode->next != nullptr)
            nextNode->next->prev = cursor;

        nextNode->next = cursor;

        if (nextNode == tail)
            tail = cursor;

        cursorIndex++;

    }


    void loadFromFile(const string& filename)
    {
        ifstream inFile(filename);

        if (!inFile)
        {
            cout << "Error opening file for loading!" << endl;
            return;
        }


        while (head != cursor)  // delete all nodes except the cursor
        {
            Node* temp = head;
            head = head->next;
            delete temp;
        }

        tail = cursor;
        cursor->prev = nullptr;
        cursorIndex = 0;

        char c;
        while (inFile.get(c))
        {
            insertChar(c);
        }

        inFile.close();
        cout << "File loaded successfully!" << endl;
    }

    void saveToFile(const string& filename)
    {
        ofstream outFile(filename);

        if (!outFile)
        {
            cout << "Error opening file for saving!" << endl;
            return;
        }

        Node* current = head;

        while (current)
        {
            if (current != cursor) // Exclude the cursor ('|') character from being saved
                outFile << current->data;
            current = current->next;
        }

        outFile.close();
        cout << "File saved successfully!" << endl;
    }

    void display()
    {
        //system("clear");
        printf("\033[H\033[J"); // ANSI escape sequence to clear the screen without flicker

        Node* current = head;
        int index = 1;
        while (current)
        {
            cout << current->data;
            current = current->next;
            index++;
        }


        cout << "\n\nCursor position: " << cursorIndex << endl;
        cout << "Press Escape to exit\nCtrl+S to Save file\n";
        cout << "Ctrl+O to Open file\n";
    }


    void run()
    {
        enableRawMode();
        string filename;
        while (true)
        {
            display();

            int c = getch();

        if (c == 27)  
        {
            char next = getch();
            if (next == '[')
            {
                switch (getch())
                {
                    case 'D':  // Left arrow
                        moveCursorLeft();
                        break;
                    case 'C':  // Right arrow
                        moveCursorRight();
                        break;
                }
            }
            else
            {
                break; 
            }
        }
             /*if(c == 27) //for msvs
                 break;

             else if(c == 75)
                 moveCursorLeft();

             else if(c == 77)
                 moveCursorRight();

            else if (c == '\b')
                deleteChar();*/


            else if (c == 8 || c == 127) 
                deleteChar();

            else if (c >= 32 && c <= 126)
                insertChar(c);

            else if (c == 19)
            {
                cout << "\nEnter filename to save:\t";
                cin >> filename;
                saveToFile(filename + ".txt");
            }
            else if (c == 15)
            {
                cout << "\nEnter filename to open:\t";
                cin >> filename;
                loadFromFile(filename + ".txt");
            }
        }
    }
};

int main()
{
    Notepad notepad;
    notepad.run();
    return 0;
}