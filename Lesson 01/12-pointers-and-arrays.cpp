/*
    CSCI 272
    Lesson 1 — Pointers and Arrays

    Instructor: Avijit Roy
    Teaching page: https://avijitroy.com/teaching/

    In most expressions, an array name is converted
    to a pointer to its first element.

    numbers[0]
    and
    *numbers

    access the same element.
*/

#include <iostream>
using namespace std;

int main()
{
    int numbers[] = {10, 20, 30, 40, 50};
    int size = 5;

    cout << "Using array notation:" << endl;

    for (int i = 0; i < size; i++)
    {
        cout << numbers[i] << " ";
    }

    cout << "\n\nUsing pointer arithmetic:"
         << endl;

    for (int i = 0; i < size; i++)
    {
        // Adding i advances by i integer elements,
        // not by i individual bytes.
        cout << *(numbers + i) << " ";
    }

    cout << "\n\nAddresses:" << endl;

    for (int i = 0; i < size; i++)
    {
        cout << "numbers[" << i << "]"
             << " value = " << numbers[i]
             << ", address = "
             << &numbers[i]
             << endl;
    }

    return 0;
}

/*
    KEY RELATIONSHIPS

        numbers[0] == *numbers

        numbers[1] == *(numbers + 1)

        numbers[2] == *(numbers + 2)


    TRY THIS #1

    Print:

        *numbers

        *(numbers + 3)

        *(numbers + 4)


    TRY THIS #2

    Compare:

        numbers

    and:

        &numbers[0]

    What do you notice?


    THINK ABOUT IT

    Why do the addresses of array elements
    appear close together?

    Arrays use contiguous memory locations.
*/
