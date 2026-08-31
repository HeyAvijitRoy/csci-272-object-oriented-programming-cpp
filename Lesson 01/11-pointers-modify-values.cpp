/*
    CSCI 272
    Lesson 1 — Modifying Values Through Pointers

    Instructor: Avijit Roy
    Teaching page: https://avijitroy.com/teaching/

    pointer stores the address of number. Dereferencing
    pointer with * reaches the same integer that the name
    number reaches. No second integer is created.
*/

#include <iostream>
using namespace std;

int main()
{
    int number = 10;

    int* pointer = &number; // Store number's address.

    cout << "Before:" << endl;
    cout << "number = " << number << endl;
    cout << "*pointer = " << *pointer << endl;

    *pointer = 50; // Follow the address and change number.

    cout << "\nAfter *pointer = 50:" << endl;
    cout << "number = " << number << endl;
    cout << "*pointer = " << *pointer << endl;

    number = 100; // *pointer observes this same change.

    cout << "\nAfter number = 100:" << endl;
    cout << "number = " << number << endl;
    cout << "*pointer = " << *pointer << endl;

    return 0;
}

/*
    MAIN IDEA

    number and *pointer access the same integer.

    There is only one integer value in memory.

    number accesses it by variable name.

    *pointer accesses it through its address.


    TRY THIS

    Add:

        int* secondPointer = &number;

    Then change:

        *secondPointer = 500;

    Print:

        number
        *pointer
        *secondPointer

    Predict all three outputs first.
*/
