/*
    CSCI 272
    Lesson 2 — Vector Initialization

    Instructor: Avijit Roy
    Teaching page: https://avijitroy.com/teaching/

    Vectors can be created in several different ways.

    This example demonstrates:
    - Empty vectors
    - Initializing with values
    - Initializing with a size and default value
    - Copying another vector
    - Creating a vector from part of another vector
*/

#include <iostream>
#include <vector>
using namespace std;


// This function prints all elements.
//
// const:
// The function is not allowed to modify the vector.
//
// &:
// The vector is passed by reference so an unnecessary
// copy of the entire vector is not created.
void printVector(const vector<int>& values)
{
    for (int value : values)
    {
        cout << value << " ";
    }

    cout << endl;
}


int main()
{
    // --------------------------------------------------
    // 1. Empty vector
    // --------------------------------------------------

    vector<int> emptyVector;

    cout << "Empty vector: ";
    printVector(emptyVector);


    // --------------------------------------------------
    // 2. Initialize with values
    // --------------------------------------------------

    vector<int> numbers = {10, 20, 30, 40, 50};

    cout << "Numbers: ";
    printVector(numbers);


    // --------------------------------------------------
    // 3. Initialize with size and default value
    // --------------------------------------------------

    // Create 5 integers.
    // Every integer starts with the value 0.
    vector<int> zeros(5, 0);

    cout << "Five zeros: ";
    printVector(zeros);


    // --------------------------------------------------
    // 4. Copy another vector
    // --------------------------------------------------

    vector<int> copyVector(numbers);

    cout << "Copied vector: ";
    printVector(copyVector);


    // --------------------------------------------------
    // 5. Copy part of another vector
    // --------------------------------------------------

    // numbers.begin()
    // points to the first element.
    //
    // numbers.begin() + 3
    // represents the position after the first
    // three elements. The range includes begin()
    // but excludes begin() + 3. This position must
    // not go beyond numbers.end().
    vector<int> firstThree(
        numbers.begin(),
        numbers.begin() + 3
    );

    cout << "First three values: ";
    printVector(firstThree);


    return 0;
}


/*
    TRY THIS #1

    Change:

        vector<int> zeros(5, 0);

    to:

        vector<int> zeros(10, 7);

    What does the vector contain?



    TRY THIS #2

    Change:

        numbers.begin() + 3

    to:

        numbers.begin() + 2

    How many elements are copied?



    TRY THIS #3

    Modify copyVector:

        copyVector[0] = 999;

    Then print both:

        numbers
        copyVector

    Does changing the copy also change the original?



    TRY THIS #4

    Create a vector containing:

        100 200 300 400 500

    Then create another vector containing
    only the first two values.
*/
