/*
    CSCI 272
    Lesson 1 — Advanced Pointer Examples

    Instructor: Avijit Roy
    Teaching page: https://avijitroy.com/teaching/

    OPTIONAL / ADVANCED REVIEW

    This file demonstrates why passing a pointer
    by value behaves differently from changing
    the pointer itself through:

    1. Pointer to pointer
    2. Reference to pointer
*/

#include <iostream>
using namespace std;

int globalValue = 77;

// ------------------------------------------------
// Example 1:
// Pointer itself is passed by value.
// ------------------------------------------------

void changePointerByValue(int* pointer)
{
    // Only this local copy is redirected.
    pointer = &globalValue;

    cout << "Inside function: " << *pointer << endl;
}

// ------------------------------------------------
// Example 2:
// Pointer to pointer.
// ------------------------------------------------

void changePointerUsingPointerToPointer(int** pointer)
{
    *pointer = &globalValue;
}

// ------------------------------------------------
// Example 3:
// Reference to pointer.
// ------------------------------------------------

void changePointerUsingReference(int*& pointer)
{
    pointer = &globalValue;
}

int main()
{
    int localValue = 15;

    // --------------------------------------------
    // Pointer passed by value
    // --------------------------------------------

    int* pointer1 = &localValue;

    cout << "Example 1" << endl;
    cout << "Before: " << *pointer1 << endl;

    changePointerByValue(pointer1);

    cout << "After:  " << *pointer1 << endl;

    // pointer1 still points to localValue.

    // --------------------------------------------
    // Pointer to pointer
    // --------------------------------------------

    int* pointer2 = &localValue;

    cout << "\nExample 2" << endl;
    cout << "Before: " << *pointer2 << endl;

    changePointerUsingPointerToPointer(&pointer2);

    cout << "After:  " << *pointer2 << endl;

    // pointer2 now points to globalValue.

    // --------------------------------------------
    // Reference to pointer
    // --------------------------------------------

    int* pointer3 = &localValue;

    cout << "\nExample 3" << endl;
    cout << "Before: " << *pointer3 << endl;

    changePointerUsingReference(pointer3);

    cout << "After:  " << *pointer3 << endl;

    return 0;
}

/*
    EXPECTED IDEA

    Example 1:
        Before: 15
        Inside function: 77
        After:  15

    Example 2:
        Before: 15
        After:  77

    Example 3:
        Before: 15
        After:  77


    WHY?

    Example 1 receives a COPY of the pointer.

    Example 2 receives the ADDRESS of the pointer.

    Example 3 receives a REFERENCE to the pointer.


    CHALLENGE

    Print the pointer addresses before and after
    each function call.

    Try to explain exactly which pointer changes
    and which one does not.
*/
