/*
    CSCI 272
    Lesson 1 — Default Arguments

    Instructor: Avijit Roy
    Teaching page: https://avijitroy.com/teaching/

    A parameter can have a default value.

    If the caller does not provide an argument,
    the default value is used.
*/

#include <iostream>
#include <string>
using namespace std;

void greet(string name = "Student")
{
    cout << "Hello, " << name << "!" << endl;
}

int main()
{
    greet();

    greet("Alex");

    greet("Maria");

    return 0;
}

/*
    TRY THIS #1

    Change the default parameter:

        "Student"

    to:

        "CSCI 272"


    TRY THIS #2

    Create another function:

        void displayScore(int score = 100)

    Call it both with and without an argument.


    QUESTION

    What is printed by:

        greet();

    and why?
*/
