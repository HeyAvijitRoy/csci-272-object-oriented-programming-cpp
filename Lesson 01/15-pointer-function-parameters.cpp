/*
    CSCI 272
    Lesson 1 — Passing Pointers to Functions

    Instructor: Avijit Roy
    Teaching page: https://avijitroy.com/teaching/

    A pointer parameter allows a function to
    access an original variable through its address.
*/

#include <iostream>
using namespace std;

void changeValue(int* pointer)
{
    // A pointer might contain nullptr, so verify that it
    // points to an integer before dereferencing it.
    if (pointer != nullptr)
    {
        // Follow the address to modify the caller's integer.
        *pointer = 100;
    }
}

int main()
{
    int number = 10;

    cout << "Before: "
         << number << endl;

    changeValue(&number);

    cout << "After: "
         << number << endl;

    return 0;
}

/*
    FOLLOW THE DATA

    number
        contains 10

    &number
        is the address of number

    changeValue(&number)
        passes that address

    pointer
        receives the address

    *pointer = 100
        changes the value stored at that address


    TRY THIS #1

    Change:

        *pointer = 100;

    to:

        *pointer = 500;


    TRY THIS #2

    Call:

        changeValue(nullptr);

    Why does the if statement prevent a problem?


    COMPARE THIS FILE WITH:

        07-pass-by-reference.cpp

    Both techniques can allow a function
    to modify the original value.
*/
