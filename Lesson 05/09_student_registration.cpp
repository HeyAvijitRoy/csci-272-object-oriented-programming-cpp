/*
    CSCI 272 — Lesson 5
    Example 09: Student Registration System

    Instructor: Avijit Roy
    Teaching page: https://avijitroy.com/teaching/

    Combined concepts:
    - Classes and objects
    - Private and public members
    - Member functions
    - Function templates
    - cin and getline
    - Stream error recovery
    - Formatted output with iomanip

    This is an integrated practice example.
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
using namespace std;

// =====================================
// Student class
// =====================================

class Student
{
private:
    string name;
    int age;
    double gpa;

public:
    // Store the student's information.
    void setData(string n, int a, double g)
    {
        name = n;
        age = a;
        gpa = g;
    }

    // Display a formatted student record.
    void printRecord() const
    {
        cout << "\n=== STUDENT RECORD ===\n";

        cout << left << setw(12)
             << "Name:" << name << endl;

        cout << left << setw(12)
             << "Age:" << age << endl;

        cout << left << setw(12)
             << "GPA:"
             << fixed << setprecision(2)
             << gpa << endl;

        cout << "======================\n";

        // Restore usual formatting.
        cout << defaultfloat << setprecision(6);
    }
};

// =====================================
// Reusable numeric input function
// =====================================

// A function template works with different numeric types, such as int and double.
template <typename T>
bool readNumber(string prompt, T& value)
{
    while (true)
    {
        cout << prompt;

        // Attempt formatted extraction.
        if (cin >> value)
        {
            // Discard the rest of the line.
            cin.ignore(
                numeric_limits<streamsize>::max(),
                '\n'
            );

            return true;
        }

        // Stop if the input source ended or a serious I/O error occurred.
        if (cin.eof() || cin.bad())
        {
            return false;
        }

        cerr << "Invalid input. Try again.\n";

        // Clear failed state.
        cin.clear();

        // Remove invalid input.
        cin.ignore(
            numeric_limits<streamsize>::max(),
            '\n'
        );
    }
}

// =====================================
// Main program
// =====================================

int main()
{
    string name;
    int age = 0;
    double gpa = 0.0;

    // Read a full name, including spaces.
    cout << "Enter full name: ";
    getline(cin, name);

    if (name.empty())
    {
        cerr << "Name cannot be empty.\n";
        return 1;
    }

    // Request a valid age.
    do
    {
        if (!readNumber("Enter age: ", age))
            return 1;

        if (age < 0 || age > 120)
            cerr << "Age must be 0-120.\n";

    } while (age < 0 || age > 120);

    // Request GPA within the accepted range.
    do
    {
        if (!readNumber("Enter GPA: ", gpa))
            return 1;

        if (gpa < 0.0 || gpa > 4.0)
            cerr << "GPA must be 0-4.\n";

    } while (gpa < 0.0 || gpa > 4.0);

    // Create a Student object.
    Student student;

    // Store the information inside the object.
    student.setData(name, age, gpa);

    // Display the formatted record.
    student.printRecord();

    // Log successful completion.
    clog << "[LOG] Student record created.\n";

    /*
        OBSERVE:
        Notice how the concepts connect:

        1. getline() handles full names.
        2. >> handles typed numeric input.
        3. clear() and ignore() recover from invalid input.
        4. A Student object stores the data.
        5. iomanip formats the output.
        6. clog reports program activity.

        TRY THIS:
        1. Enter letters for the GPA.
        2. Try a GPA of 4.5.
        3. Change precision from 2 to 3.
        4. Add another private data member.
    */

    return 0;
}
