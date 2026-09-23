/*
    CSCI 272
    Lesson 2 — Vector Operations and Algorithms

    Instructor: Avijit Roy
    Teaching page: https://avijitroy.com/teaching/

    Some operations belong directly to vector:

        size()
        empty()
        clear()

    Other operations come from the
    Standard Library <algorithm> header:

        sort()
        reverse()

    This example demonstrates:
    - size()
    - empty()
    - sort()
    - reverse()
    - clear()
*/

#include <iostream>
#include <vector>
#include <algorithm>
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
        5,
        2,
        8,
        3,
        1
    };


    cout << "Original vector:" << endl;
    printVector(numbers);


    // --------------------------------------------------
    // size()
    // --------------------------------------------------

    cout << "\nSize: "
         << numbers.size()
         << endl;


    // --------------------------------------------------
    // empty()
    // --------------------------------------------------

    // empty() returns true if there are no elements.
    // boolalpha makes cout display true/false instead
    // of its usual 1/0 for a bool value.
    cout << boolalpha;

    cout << "Is empty? "
         << numbers.empty()
         << endl;


    // --------------------------------------------------
    // sort()
    // --------------------------------------------------

    // sort() comes from <algorithm>.
    //
    // It is NOT called like:
    //
    //     numbers.sort();
    //
    // We give sort() the beginning and ending
    // positions of the range we want to sort.
    sort(
        numbers.begin(),
        numbers.end()
    );


    cout << "\nAfter sort():" << endl;
    printVector(numbers);


    // --------------------------------------------------
    // reverse()
    // --------------------------------------------------

    // reverse() flips the current order.
    reverse(
        numbers.begin(),
        numbers.end()
    );


    cout << "\nAfter reverse():" << endl;
    printVector(numbers);


    // --------------------------------------------------
    // clear()
    // --------------------------------------------------

    // clear() removes all elements.
    numbers.clear();


    cout << "\nAfter clear():" << endl;

    cout << "Size: "
         << numbers.size()
         << endl;

    cout << "Is empty? "
         << numbers.empty()
         << endl;


    return 0;
}


/*
    TRY THIS #1

    Remove:

        sort(numbers.begin(), numbers.end());

    Run only reverse().

    Does reverse() sort the values?

    No.

    reverse() simply flips the current order.



    TRY THIS #2

    Try:

        numbers.sort();

    Does it compile?

    Why not?

    sort() is an algorithm from <algorithm>,
    not a member function of vector.



    TRY THIS #3

    Start with:

        vector<int> numbers = {9, 4, 7, 1, 5};

    First sort the vector.

    Then reverse it.

    What order do you get?



    TRY THIS #4

    What does empty() return:

        before clear()?
        after clear()?
*/
