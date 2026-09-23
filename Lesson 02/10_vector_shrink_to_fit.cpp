/*
    CSCI 272
    Lesson 2 — shrink_to_fit()

    Instructor: Avijit Roy
    Teaching page: https://avijitroy.com/teaching/

    A vector may have more capacity than it
    currently needs.

    shrink_to_fit() asks the vector to reduce
    unused capacity.

    This example demonstrates:
    - reserve()
    - size()
    - capacity()
    - shrink_to_fit()
*/

#include <iostream>
#include <vector>
using namespace std;


// Print the actual elements so we can compare them
// before and after the capacity change request.
void printVector(const vector<int>& values)
{
    cout << "Values: ";

    for (int value : values)
    {
        cout << value << " ";
    }

    cout << endl;
}


int main()
{
    vector<int> numbers;


    // Prepare storage for at least 100 integers.
    numbers.reserve(100);


    // But only store three actual values.
    numbers.push_back(10);
    numbers.push_back(20);
    numbers.push_back(30);


    cout << "Before shrink_to_fit():" << endl;

    cout << "Size: "
         << numbers.size()
         << endl;

    cout << "Capacity: "
         << numbers.capacity()
         << endl;

    printVector(numbers);


    // Request that unnecessary capacity
    // be reduced.
    numbers.shrink_to_fit();


    cout << "\nAfter shrink_to_fit():" << endl;

    cout << "Size: "
         << numbers.size()
         << endl;

    cout << "Capacity: "
         << numbers.capacity()
         << endl;

    // Compare with the values above: asking for less
    // unused storage does not remove the elements.
    printVector(numbers);


    return 0;
}


/*
    TRY THIS #1

    Change:

        numbers.reserve(100);

    to:

        numbers.reserve(10);

    Compare the results.



    TRY THIS #2

    Add five more values before calling:

        shrink_to_fit();

    What are the new:

        size?
        capacity?



    IMPORTANT

    shrink_to_fit() is a request to reduce
    unused capacity.

    The C++ standard does not require the
    implementation to reduce the capacity
    to exactly the size in every situation.
*/
