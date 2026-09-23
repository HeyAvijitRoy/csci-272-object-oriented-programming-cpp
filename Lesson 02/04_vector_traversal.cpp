/*
    CSCI 272
    Lesson 2 — Traversing a Vector

    Instructor: Avijit Roy
    Teaching page: https://avijitroy.com/teaching/

    Traversing means visiting the elements
    of a collection one at a time.

    This example demonstrates three methods:

    1. Index-based loop
    2. Range-based loop
    3. Iterator

    It also demonstrates:
    - size_t
    - begin()
    - end()
    - Dereferencing an iterator with *
*/

#include <cstddef>
#include <iostream>
#include <vector>
using namespace std;


int main()
{
    vector<int> numbers = {10, 20, 30, 40, 50};


    // --------------------------------------------------
    // METHOD 1
    // Index-based loop
    // --------------------------------------------------

    cout << "Index-based loop:" << endl;


    // For this vector, size() returns an unsigned size type
    // (std::size_t). An int is signed: it can hold negative
    // values. std::size_t cannot be negative; it represents
    // sizes and can cover the size of an object in memory.
    //
    // Using std::size_t for i matches the type of size().
    // An int index compared with size() mixes signed and
    // unsigned values and can cause surprising conversions.
    // Neither type has one fixed size on every computer.
    for (std::size_t i = 0; i < numbers.size(); i++)
    {
        cout << "Index "
             << i
             << " contains "
             << numbers[i]
             << endl;
    }


    // --------------------------------------------------
    // METHOD 2
    // Range-based loop
    // --------------------------------------------------

    cout << "\nRange-based loop:" << endl;


    // number receives each value from the vector.
    for (int number : numbers)
    {
        cout << number << " ";
    }

    cout << endl;


    // --------------------------------------------------
    // METHOD 3
    // Iterator
    // --------------------------------------------------

    cout << "\nIterator:" << endl;


    // begin()
    // points to the first element.
    //
    // end()
    // points just AFTER the last element.
    for (vector<int>::iterator it = numbers.begin();
         it != numbers.end();
         ++it)
    {
        // *it gets the value the iterator refers to.
        cout << *it << " ";
    }

    cout << endl;


    return 0;
}


/*
    TRY THIS #1

    Change the vector to:

        vector<int> numbers = {5, 10, 15, 20};

    Run all three loops.



    TRY THIS #2

    Modify the index-based loop so that it prints:

        Index 0 = 10
        Index 1 = 20
        Index 2 = 30
        ...



    TRY THIS #3

    Change:

        for (int number : numbers)

    to:

        for (int& number : numbers)
        {
            number = number * 2;
        }

    Print the vector afterward.

    What happened?



    TRY THIS #4

    First try:

        for (int number : numbers)
        {
            number = number * 2;
        }

    Then print the original vector.

    Why does the original vector NOT change?

    Remember:

        int number

    creates a copy.

    But:

        int& number

    refers to the original element.



    TRY THIS #5

    Why would a negative index make no sense here?

    For example, comparing an int index of -1 with
    numbers.size() can convert -1 to a very large
    unsigned value. This is one reason to avoid
    mixing signed indexes with unsigned sizes.

    std::size_t cannot represent -1. Subtracting 1 from
    an unsigned zero wraps to a very large value, so do
    not use numbers.size() - 1 if the vector might be empty.
    Check !numbers.empty() before accessing the last item.
*/
