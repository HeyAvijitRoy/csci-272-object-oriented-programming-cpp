/*
    CSCI 272
    Lesson 1 — Dynamic Arrays

    Instructor: Avijit Roy
    Teaching page: https://avijitroy.com/teaching/

    A dynamic array can have a size determined
    while the program is running.
*/

#include <iostream>
using namespace std;

int main()
{
    int size;

    cout << "How many numbers? ";
    cin >> size;

    // Validate the size before asking new[] to allocate memory.
    if (!cin || size <= 0)
    {
        cout << "Size must be a positive integer." << endl;
        return 1;
    }

    // new[] creates exactly size integer elements.
    int* numbers = new int[size];

    for (int i = 0; i < size; i++)
    {
        numbers[i] = (i + 1) * 10;
    }

    cout << "\nArray values:" << endl;

    for (int i = 0; i < size; i++)
    {
        cout << numbers[i] << " ";
    }

    cout << endl;

    // Match array new[] with array delete[].
    delete[] numbers;

    // The allocation is gone; do not keep its old address.
    numbers = nullptr;

    return 0;
}

/*
    TRY THIS #1

    Run the program several times using:

        3
        5
        10

    as the size.


    TRY THIS #2

    Instead of automatically generating values,
    ask the user to enter each value.


    TRY THIS #3

    Calculate the total of all array elements.


    IMPORTANT

    One dynamically allocated value:

        delete pointer;

    Dynamic array:

        delete[] pointer;
*/
