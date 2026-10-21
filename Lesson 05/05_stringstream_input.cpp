/*
    CSCI 272 — Lesson 5
    Instructor: Avijit Roy
    Teaching page: https://avijitroy.com/teaching/

    Example 05: String Stream Input

    Topics:
    - istringstream
    - Formatted input using >>
    - Reading data into an object
    - Input validation

    Connection to Lesson 4:
    We use a Person class to store input.
*/

#include <iostream>
#include <sstream>
#include <string>
using namespace std;

// A simple class representing a person.
class Person
{
public:
    string name;
    int age;
};

int main()
{
    // Data is already stored in a string.
    string inputString = "Alice 30";

    // Create an input stream from the string. It behaves similarly to cin, but reads from inputString instead of the keyboard.
    istringstream input(inputString);

    // Create a Person object.
    Person person;

    // >> extracts individual values. It skips leading whitespace.
    //
    // First extraction:
    // "Alice" goes into person.name.
    //
    // Second extraction:
    // "30" goes into person.age.
    if (input >> person.name >> person.age)
    {
        cout << "Name: "
             << person.name << endl;

        cout << "Age: "
             << person.age << endl;
    }
    else
    {
        cerr << "Error: Invalid person data.\n";
    }

    /*
        OBSERVE:
        Compare the following:

        cin >> person.age;

        Reads from keyboard input.

        input >> person.age;

        Reads from the stringstream.

        The extraction operation is similar;
        only the source of data changes.

        PREDICT:
        What happens if inputString is:

        "Alice Johnson 30"

        The first extraction reads "Alice". The second tries to convert "Johnson" into an integer and fails.

        TRY THIS:
        Try these input strings:

        1. "Bob 22"
        2. "Bob twenty"
        3. "Bob Smith 22"

        Observe which ones can be parsed using these two extractions.
    */

    return 0;
}
