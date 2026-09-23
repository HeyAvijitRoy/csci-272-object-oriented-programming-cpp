/*
    CSCI 272
    Lesson 2 — Inserting and Removing Elements

    Instructor: Avijit Roy
    Teaching page: https://avijitroy.com/teaching/

    Vector elements can be inserted or removed
    from different positions.

    Accessing a vector element using an index
    is very fast.

    However, inserting or removing an element
    from the middle may require other elements
    to shift.

    This example demonstrates:
    - insert()
    - erase()
    - Element shifting
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


    cout << "Original vector:" << endl;
    printVector(numbers);


    // --------------------------------------------------
    // INSERT
    // --------------------------------------------------

    // Insert 25 at index 2.
    // Elements at and after index 2 shift right.
    //
    // begin()      -> index 0
    // begin() + 1  -> index 1
    // begin() + 2  -> index 2
    numbers.insert(
        numbers.begin() + 2,
        25
    );


    cout << "\nAfter inserting 25 at index 2:"
         << endl;

    printVector(numbers);


    // Vector is now:
    //
    // 10 20 25 30 40 50


    // --------------------------------------------------
    // ERASE
    // --------------------------------------------------

    // Remove the element at index 3.
    //
    // Index 3 currently contains 30.
    // Later elements shift left to fill the gap.
    numbers.erase(
        numbers.begin() + 3
    );


    cout << "\nAfter erasing index 3:"
         << endl;

    printVector(numbers);


    return 0;
}


/*
    TRY THIS #1

    Before running:

        numbers.erase(
            numbers.begin() + 3
        );

    determine which VALUE is currently
    stored at index 3.



    TRY THIS #2

    Insert:

        99

    at index 1.

    Which existing elements must move?



    TRY THIS #3

    Remove the first element:

        numbers.erase(numbers.begin());

    What happens to the remaining elements?



    TRY THIS #4

    Why can insertion in the middle be slower
    than accessing:

        numbers[3]

    ?

    Accessing one index can happen directly.

    But inserting into the middle may require
    several existing elements to shift.



    IMPORTANT

    Inserting may reallocate the vector's storage.
    Erasing shifts elements. Either operation can
    invalidate iterators or references you kept
    earlier. Obtain a fresh iterator after changing
    the vector before accessing it again.
*/
