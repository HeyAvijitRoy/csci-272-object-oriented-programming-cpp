/*
    CSCI 272
    Lesson 2 — Vector Basics

    Instructor: Avijit Roy
    Teaching page: https://avijitroy.com/teaching/

    A vector is a dynamic array.

    Unlike a regular array, a vector can grow
    or shrink while the program is running.

    This example demonstrates:
    - Declaring a vector
    - Initializing a vector
    - Accessing elements
    - push_back()
    - size()
*/

#include <iostream>
#include <vector>
using namespace std;


int main()
{
    // A vector that stores integers.
    vector<int> numbers = {10, 20, 30};


    // --------------------------------------------------
    // Access elements using their index.
    // --------------------------------------------------

    cout << "First element: "
         << numbers[0]
         << endl;

    cout << "Second element: "
         << numbers[1]
         << endl;

    cout << "Third element: "
         << numbers[2]
         << endl;


    // --------------------------------------------------
    // push_back()
    // --------------------------------------------------

    // push_back() adds a NEW element
    // to the end of the vector.
    numbers.push_back(40);


    cout << "\nAfter push_back(40):" << endl;

    // A loop prints every value, including the new one.
    for (int number : numbers)
    {
        cout << number << " ";
    }
    cout << endl;


    // --------------------------------------------------
    // size()
    // --------------------------------------------------

    // size() returns the number of elements
    // currently stored in the vector.
    cout << "\nNumber of elements: "
         << numbers.size()
         << endl;


    return 0;
}


/*
    TRY THIS #1

    Add:

        numbers.push_back(50);
        numbers.push_back(60);

    What is the new size?



    TRY THIS #2

    Change the vector to:

        vector<int> numbers = {5, 10};

    Add three more values using push_back().



    TRY THIS #3

    Compare these two ideas:

        numbers.push_back(40);

    and:

        numbers[3] = 40;

    push_back() ADDS a new element.

    [] is normally used to access an element
    that already exists. If the vector has only
    three elements, numbers[3] is out of bounds.
    DO NOT RUN that access before push_back().



    TRY THIS #4

    Create:

        vector<double> prices = {10.99, 5.50, 7.25};

    Print the first and last values.
*/
