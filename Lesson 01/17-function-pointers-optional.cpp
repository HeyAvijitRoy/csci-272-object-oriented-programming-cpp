/*
    CSCI 272
    Lesson 1 — Function Pointers

    Instructor: Avijit Roy
    Teaching page: https://avijitroy.com/teaching/

    OPTIONAL / ADVANCED REVIEW

    Functions also have addresses in memory.

    A function pointer can store the address
    of a function and call it indirectly.
*/

#include <iostream>
using namespace std;

void displayValues(int x, int y)
{
    cout << x << ", " << y << endl;
}

int main()
{
    // Declare a pointer to a function that:
    // - returns void
    // - accepts two int parameters
    void (*functionPointer)(int, int);

    functionPointer = &displayValues;

    // Call through the pointer.
    functionPointer(2, 2);

    // Alternative syntax.
    (*functionPointer)(10, 20);

    return 0;
}

/*
    TRY THIS #1

    Remove the &:

        functionPointer = displayValues;

    Compile and run.

    Does it still work?


    TRY THIS #2

    Create:

        void addAndDisplay(int x, int y)

    Then make functionPointer point to
    addAndDisplay instead.


    THINK ABOUT IT

    The pointer does not contain the result
    of the function.

    It contains the address of the function.
*/
