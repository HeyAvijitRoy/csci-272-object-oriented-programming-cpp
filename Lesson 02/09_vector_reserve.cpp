/*
    CSCI 272
    Lesson 2 — reserve()

    Instructor: Avijit Roy
    Teaching page: https://avijitroy.com/teaching/

    reserve() allows us to request memory
    for a certain number of elements ahead of time.

    This can reduce unnecessary reallocations
    when we already know approximately how many
    elements we plan to store.

    This example demonstrates:
    - reserve()
    - resize()
    - size()
    - capacity()
    - push_back()
*/

#include <cstddef>
#include <iostream>
#include <vector>
using namespace std;


// Print the elements that exist, not the unused
// storage counted by capacity().
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


    // Reserve enough storage for at least
    // 5 integers.
    //
    // IMPORTANT:
    //
    // reserve(5) does NOT create 5 elements.
    numbers.reserve(5);


    cout << "After reserve(5):" << endl;

    cout << "Size: "
         << numbers.size()
         << endl;

    cout << "Capacity: "
         << numbers.capacity()
         << endl;

    printVector(numbers);

    // Compare a separate vector made with resize().
    // resize(5) CREATES five elements. For int, each
    // new element starts at 0. Its size is now 5.
    vector<int> resizedNumbers;
    resizedNumbers.resize(5);

    cout << "\nSeparate vector after resize(5):" << endl;
    cout << "Size: " << resizedNumbers.size() << endl;
    cout << "Capacity: " << resizedNumbers.capacity() << endl;
    printVector(resizedNumbers);

    // Continue with numbers, whose size is still 0.
    // The two vectors are independent.

    cout << "\nAdding elements..." << endl;


    // Add more than five values so we can observe
    // what happens after the reserved space fills.
    for (int i = 1; i <= 12; i++)
    {
        // Keep the old capacity so changes are visible.
        // std::size_t is explained in the traversal file.
        const std::size_t oldCapacity = numbers.capacity();
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

        if (numbers.capacity() != oldCapacity)
        {
            cout << "Capacity grew from "
                 << oldCapacity
                 << " to "
                 << numbers.capacity()
                 << endl;
        }


        cout << "Memory location: "
             << numbers.data()
             << endl;
    }

    // When size() reaches capacity(), the next
    // push_back() needs more storage. The vector
    // allocates a larger block, moves or copies its
    // elements, and frees the old block. Many
    // implementations grow by a factor near 2, so
    // several later insertions can reuse the extra
    // space. This avoids reallocating for every add.
    // For example, capacity might go 5 -> 10 when
    // adding the sixth item, then 10 -> 20 when
    // adding the eleventh. Growing by only one slot
    // each time would repeatedly move all old items.
    // The tradeoff is unused capacity. C++ does not
    // require doubling or any exact growth factor.


    return 0;
}


/*
    TRY THIS #1

    Immediately after:

        numbers.reserve(5);

    what are:

        size?
        capacity?

    Remember:

        reserve() prepares memory.

        resize() creates elements up to the new size.

        push_back() adds actual elements.

    Compare the printed values of numbers and
    resizedNumbers before any push_back() calls.



    TRY THIS #2

    Watch what happens when adding the sixth element.
    Did the capacity change? It may already be more
    than five, since reserve(5) promises at least five.

    Find each "Capacity grew" message in the output.
    Why does capacity stay the same on the other adds?



    TRY THIS #3

    Change:

        numbers.reserve(5);

    to:

        numbers.reserve(20);

    Change the loop to add only 5 elements.

    Compare size and capacity.



    TRY THIS #4

    Think of reserve() like reserving seats
    before people arrive.

    reserve(5):

        Five seats are prepared.

    resize(5):

        Five elements exist, initialized to 0.

    But:

        Zero people are sitting there yet.

    push_back():

        A person actually occupies a seat.
*/
