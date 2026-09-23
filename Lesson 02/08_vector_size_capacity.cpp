/*
    CSCI 272
    Lesson 2 — Vector Size and Capacity

    Instructor: Avijit Roy
    Teaching page: https://avijitroy.com/teaching/

    A vector has two important properties:

    SIZE
        The number of elements currently stored.

    CAPACITY
        The number of elements the vector can
        currently hold before needing more memory.

    This example demonstrates:
    - size()
    - capacity()
    - Automatic vector growth
    - Memory reallocation
*/

#include <iostream>
#include <vector>
using namespace std;


// Show the values that actually exist. Unused capacity
// is storage, so it does not appear in this printout.
void printVector(const vector<int>& values)
{
    cout << "Values: ";

    if (values.empty())
    {
        cout << "(none)";
    }

    for (int value : values)
    {
        cout << value << " ";
    }

    cout << endl;
}


int main()
{
    vector<int> numbers;


    cout << "Before adding anything:" << endl;

    cout << "Size: "
         << numbers.size()
         << endl;

    cout << "Capacity: "
         << numbers.capacity()
         << endl;

    printVector(numbers);


    cout << "\nAdding values..." << endl;


    for (int i = 1; i <= 10; i++)
    {
        numbers.push_back(i * 10);


        cout << "\nAdded: "
             << i * 10
             << endl;


        cout << "Size: "
             << numbers.size()
             << endl;


        cout << "Capacity: "
             << numbers.capacity()
             << endl;

        printVector(numbers);


        // data() returns a pointer to the vector's
        // underlying array.
        //
        // Printing it lets us observe whether
        // the underlying memory location changes.
        cout << "Memory location: "
             << numbers.data()
             << endl;
    }


    return 0;
}


/*
    TRY THIS #1

    Watch the capacity as values are added.

    Does capacity increase every single time?



    TRY THIS #2

    Watch the memory address.

    Does it always stay the same?



    TRY THIS #3

    When the vector runs out of capacity,
    it may need to:

        1. Allocate a larger memory block.
        2. Move/copy existing elements.
        3. Release the old memory.

    This is called reallocation.

    An old pointer, reference, or iterator into the
    vector must not be used after reallocation.

    Growing by more than one slot at a time can
    avoid reallocating on every push_back(), but
    also leaves some storage temporarily unused.



    IMPORTANT

    You may observe capacity values such as:

        1
        2
        4
        8
        16

    on your computer.

    However, C++ does NOT guarantee that
    vector capacity must always double.

    The exact growth strategy depends on
    the Standard Library implementation.
*/
