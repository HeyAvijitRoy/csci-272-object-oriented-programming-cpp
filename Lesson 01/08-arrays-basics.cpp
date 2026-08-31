/*
    CSCI 272
    Lesson 1 — Arrays

    Instructor: Avijit Roy
    Teaching page: https://avijitroy.com/teaching/

    Arrays store multiple values of the same
    data type in contiguous memory locations.

    Array indexes start at 0.
*/

#include <iostream>
using namespace std;

int main()
{
    int numbers[6] = {19, 10, 8, 17, 9, 15};

    cout << "First element: "
         << numbers[0] << endl;

    cout << "Second element: "
         << numbers[1] << endl;

    cout << "Last element: "
         << numbers[5] << endl;

    cout << "\nAll elements:" << endl;

    for (int i = 0; i < 6; i++)
    {
        cout << "Index " << i
             << " = "
             << numbers[i]
             << endl;
    }

    return 0;
}

/*
    TRY THIS #1

    Change one of the array values.


    REASON ABOUT THIS #2 — DO NOT RUN THE INVALID VERSION

    Why would changing i < 6 to i <= 6 be unsafe?

    Valid indexes are:

        0, 1, 2, 3, 4, 5

    Index 6 is outside the array. Accessing it would
    cause undefined behavior, so leave the valid bound
    in place.


    TRY THIS #3

    Add another element.

    Remember to update the array size if needed.
*/
