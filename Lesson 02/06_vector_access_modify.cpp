/*
    CSCI 272
    Lesson 2 — Accessing and Modifying Vector Elements

    Instructor: Avijit Roy
    Teaching page: https://avijitroy.com/teaching/

    Vector elements can be accessed or modified
    using several methods.

    This example demonstrates:
    - []
    - at()
    - front()
    - back()
*/

#include <iostream>
#include <vector>
using namespace std;


void printVector(const vector<int>& numbers)
{
    for (int number : numbers)
    {
        cout << number << " ";
    }

    cout << endl;
}


int main()
{
    vector<int> numbers = {
        10,
        20,
        30,
        40,
        50
    };


    // --------------------------------------------------
    // ACCESSING ELEMENTS
    // --------------------------------------------------

    cout << "First element: "
         << numbers.front()
         << endl;


    // Index 1 is the second element.
    cout << "Second element: "
         << numbers[1]
         << endl;


    // at(2) accesses index 2.
    cout << "Third element: "
         << numbers.at(2)
         << endl;


    cout << "Last element: "
         << numbers.back()
         << endl;


    // --------------------------------------------------
    // MODIFYING ELEMENTS
    // --------------------------------------------------

    // Change first element.
    numbers.front() = 100;


    // Change element at index 1.
    numbers[1] = 200;


    // Change element at index 2.
    numbers.at(2) = 300;


    // Change last element.
    numbers.back() = 500;


    cout << "\nAfter modification:" << endl;

    printVector(numbers);


    return 0;
}


/*
    TRY THIS #1

    Before running the program, predict
    the final contents of the vector.



    TRY THIS #2

    Change:

        numbers.front() = 100;

    to:

        numbers.front() = 999;



    TRY THIS #3

    Try accessing (the program will stop unless
    the exception is handled):

        numbers.at(100)

    What happens?

    at() performs bounds checking and throws
    std::out_of_range for an invalid index.



    TRY THIS #4

    Compare these by reading the code only.
    DO NOT RUN numbers[100]: it is out of bounds
    and has undefined behavior.

    Compare:

        numbers[100]

    and:

        numbers.at(100)

    [] does not perform the same bounds checking
    that at() provides.

    We will study exception handling in more
    detail later in the course.
*/
