/*
    CSCI 272 — Lesson 5
    Example 01: Standard Streams

    Instructor: Avijit Roy
    Teaching page: https://avijitroy.com/teaching/

    Topics:
    - cin  : standard input
    - cout : standard output
    - cerr : standard error
    - clog : standard logging

    Connection:
    We previously used cin and cout to work with variables. Now we explain the streams behind those operations.
*/

#include <iostream>
using namespace std;

int main()
{
    int age = 0;

    // cout sends formatted output to the screen.
    cout << "Enter your age: ";

    // cin reads input from the keyboard. >> attempts to convert the input to an int.
    if (!(cin >> age))
    {
        // cerr is used for error messages.
        cerr << "Error: Please enter a number.\n";
        return 1;
    }

    // An integer can still be logically invalid.
    if (age < 0 || age > 120)
    {
        cerr << "Error: Invalid age.\n";
        return 1;
    }

    // cout is used for normal program output.
    cout << "Your age is: " << age << endl;

    // clog is intended for diagnostic/log messages. Both clog and cerr normally use standard error.
    clog << "[LOG] Age processed successfully.\n";

    /*
        OBSERVE:
        Is cerr only used when code fails to compile?

        Answer: No. cerr reports errors during program execution.

        TRY THIS:
        Run the program three times:

        1. Enter 25
           Expected: Normal output + log.

        2. Enter hello
           Expected: Input conversion error.

        3. Enter -5
           Expected: Age validation error.
    */

    return 0;
}
