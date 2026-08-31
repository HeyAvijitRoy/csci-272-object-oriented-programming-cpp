/*
    CSCI 272
    Lesson 1 — Dynamic Memory

    Instructor: Avijit Roy
    Teaching page: https://avijitroy.com/teaching/

    new
        allocates memory while the program runs.

    delete
        releases dynamically allocated memory.

    nullptr
        represents a pointer that currently
        points to no valid object.
*/

#include <iostream>
using namespace std;

int main()
{
    // new reserves space for one int and returns its address.
    int* pointer = new int;

    // Dereference the pointer to store a value in that space.
    *pointer = 25;

    cout << "Value: "
         << *pointer << endl;

    cout << "Address: "
         << pointer << endl;

    // Match one-object new with one-object delete.
    delete pointer;

    // Avoid keeping a dangling pointer.
    pointer = nullptr;

    return 0;
}

/*
    TRY THIS #1

    Change:

        *pointer = 25;

    to another value.


    REASON ABOUT THIS #2 — DO NOT RUN THE INVALID VERSION

    Why would dereferencing pointer after delete be invalid?

    delete ends the lifetime of the allocated integer.
    The address is no longer permission to access that object.
    Setting pointer to nullptr makes the invalid state visible,
    but it does not undo an earlier invalid access.


    IMPORTANT

    After deleting dynamically allocated memory,
    setting the pointer to nullptr helps indicate
    that it no longer points to a valid object.
*/
