/*
    CSCI 272
    Lesson 1 — Pointer Basics

    Instructor: Avijit Roy
    Teaching page: https://avijitroy.com/teaching/

    A pointer is a variable that stores
    the memory address of another variable.

    &variable
        means "address of variable"

    *pointer
        means "value stored at the address
        contained by pointer"
*/

#include <iostream>
using namespace std;

int main()
{
    int number = 15;

    int* pointer = &number;

    cout << "number:   "
         << number << endl;

    cout << "&number:  "
         << &number << endl;

    cout << "pointer:  "
         << pointer << endl;

    cout << "*pointer: "
         << *pointer << endl;

    cout << "&pointer: "
         << &pointer << endl;

    return 0;
}

/*
    BEFORE RUNNING:

    Which two outputs should contain the
    same address?

        &number
        pointer


    TRY THIS #1

    Change:

        number = 15

    to another value.

    Which outputs change?


    TRY THIS #2

    Add:

        *pointer = 50;

    Then print number again.

    Predict what happens first.


    IMPORTANT

    The pointer has its own address.

    Therefore:

        pointer

    and:

        &pointer

    mean completely different things.
*/
