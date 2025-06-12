#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include "3-1.h"  
using namespace std;

struct Student 
{

    int rollNumber;
    string firstName;
    string lastName;
    int batch;
    string department;
    float cgpa;

    Student() = default;
    Student(int rn, const string& fn, const string& ln, int b, const string& dep, float c)
        : rollNumber(rn), firstName(fn), lastName(ln), batch(b), department(dep), cgpa(c) {}
};

class StudentList {
private:
    SpecialBST<int, Student> bst;

public:
    bool InsertNewStudent(int rollNumber, const string& firstName, const string& lastName, int batch, const string& department, float cgpa) {
        if (rollNumber <= 0 || batch <= 0 || cgpa < 0.0 || cgpa > 4.0) 
        {
            cout << "Invalid data provided. Roll number, batch, and CGPA must be valid." << endl;
            return false;
        }

        Student student(rollNumber, firstName, lastName, batch, department, cgpa);

        if (!bst.insert(rollNumber, student)) 
        {
            cout << "Roll Number already exists!" << endl;
            return false;
        }

        cout << "New student inserted successfully!" << endl;
        return true;
    }

    bool deleteStudent(int rollNumber) 
    {
        if (bst.deleteKey(rollNumber)) 
        {
            cout << "Student deleted successfully." << endl;
            return true;
        }
        else 
        {
            cout << "Student with this roll number does not exist!" << endl;
            return false;
        }
    }

    bool updateStudent(int oldRollNumber, int newRollNumber, const string& newFirstName, const string& newLastName, int newBatch, const string& newDepartment, float newCgpa) 
    {
        if (newRollNumber <= 0 || newBatch <= 0 || newCgpa < 0.0 || newCgpa > 4.0) 
        {
            cout << "Invalid data provided. Roll number, batch, and CGPA must be valid." << endl;
            return false;
        }

        Student* student = bst.search(oldRollNumber);
        if (!student) 
        {
            cout << "Student with this roll number does not exist!" << endl;
            return false;
        }

        if (oldRollNumber != newRollNumber) 
        {
            Student originalStudent = *student;  // Preserve the original data for rollback

            if (!bst.deleteKey(oldRollNumber)) 
            {
                cout << "Failed to delete old roll number. Update failed." << endl;
                return false;
            }

            if (!bst.insert(newRollNumber, Student(newRollNumber, newFirstName, newLastName, newBatch, newDepartment, newCgpa))) 
            {
                cout << "Failed to update student roll number due to duplicate or insertion error." << endl;
                bst.insert(oldRollNumber, originalStudent);  // Rollback original data
                return false;
            }
        } 
        else 
        {
            *student = Student(newRollNumber, newFirstName, newLastName, newBatch, newDepartment, newCgpa);
        }

        cout << "Student data updated successfully." << endl;
        return true;
    }


    void printAllStudents() const 
    {
        vector<Student> students = bst.getValuesInOrder();
        cout << "Total Students: " << students.size() << endl;
        for (const Student& student : students) 
        {
            cout << "Roll Number: " << student.rollNumber << "\n" << "First Name: " << student.firstName << "\n" << "Last Name: " << student.lastName << "\n" << "Batch: " << student.batch << "\n" << "Department: " << student.department << "\n" << "CGPA: " << student.cgpa << "\n\n";
        }
    }

    Student* searchStudent(int rollNumber) 
    {
        return bst.search(rollNumber);
    }
};

#include <iostream>
#include <string>
using namespace std;

int main() {
    StudentList studentList;
    char choice;
    do {
        cout << "\nPress I to insert a new student.\n";
        cout << "Press D to delete a student.\n";
        cout << "Press S to search a student by roll number.\n";
        cout << "Press U to update the data of a student.\n";
        cout << "Press P to print all students sorted by roll number.\n";
        cout << "Press E to exit.\n";
        cout << "> ";
//cin.ignore();
        cin >> choice;
        //cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear any extra input
        system("clear");
        switch (choice) {
            case 'I': {
                int rollNumber, batch;
                string firstName, lastName, department;
                float cgpa;
                cout << "Please enter the data of new student in the order:\nRoll Number, First Name, Last Name, Batch, Department, CGPA\n> ";
                cin >> rollNumber >> firstName >> lastName >> batch >> department >> cgpa;
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear buffer after reading inputs
                studentList.InsertNewStudent(rollNumber, firstName, lastName, batch, department, cgpa);
                break;
            }
            case 'D': {
                int rollNumber;
                cout << "Please enter the roll number of the student that you want to delete:\n> ";
                cin >> rollNumber;
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear buffer
                studentList.deleteStudent(rollNumber);
                break;
            }
            case 'S': {
                int rollNumber;
                cout << "Please enter the roll number of the student that you want to search:\n> ";
                cin >> rollNumber;
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear buffer
                Student* student = studentList.searchStudent(rollNumber);
                if (student) {
                    cout << "Roll Number: " << student->rollNumber << "\n"
                         << "First Name: " << student->firstName << "\n"
                         << "Last Name: " << student->lastName << "\n"
                         << "Batch: " << student->batch << "\n"
                         << "Department: " << student->department << "\n"
                         << "CGPA: " << student->cgpa << "\n";
                } else {
                    cout << "Student with this roll number does not exist!" << endl;
                }
                break;
            }
            case 'U': {
                int oldRollNumber, newRollNumber, batch;
                string firstName, lastName, department;
                float cgpa;
                cout << "Please enter the roll number of the student whose data you want to update:\n> ";
                cin >> oldRollNumber;
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear buffer
                cout << "Please enter new data of student in this order: Roll Number, First Name, Last Name, Batch, Department, CGPA\n> ";
                cin >> newRollNumber >> firstName >> lastName >> batch >> department >> cgpa;
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear buffer after reading inputs
                studentList.updateStudent(oldRollNumber, newRollNumber, firstName, lastName, batch, department, cgpa);
                break;
            }
            case 'P': {
                studentList.printAllStudents();
                break;
            }
            case 'E':
                cout << "Exiting the program." << endl;
                break;

            default:
                cout << "Invalid choice! Please try again." << endl;
                cin.clear(); // Clear error state
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
        }
    } while (choice != 'E');
    
    return 0;
}

