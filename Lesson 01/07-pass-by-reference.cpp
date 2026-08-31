/*
    CSCI 272
    Lesson 1 — Pass by Reference

    Instructor: Avijit Roy
    Teaching page: https://avijitroy.com/teaching/

    The & in the parameter means that number
    refers to the original argument.

    Changes made inside the function affect
    the original variable.
*/

#include <iostream>
using namespace std;

void changeValue(int& number)
{
    number = 100;
}

void increment(int& number)
{
    number++;
}

void swapValues(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

int main()
{
    int value = 10;

    cout << "Before changeValue: "
         << value << endl;

    changeValue(value);

    cout << "After changeValue: "
         << value << endl;

    increment(value);

    cout << "After increment: "
         << value << endl;

    int x = 5;
    int y = 20;

    cout << "\nBefore swap:" << endl;
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;

    swapValues(x, y);

    cout << "\nAfter swap:" << endl;
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;

    return 0;
}

/*
    TRY THIS #1

    Remove the & from:

        void changeValue(int& number)

    Run the program again.

    What changes?


    TRY THIS #2

    Remove the & characters from swapValues().

    Does the swap still work outside the function?


    TRY THIS #3

    Print:

        &value

    inside main() and:

        &number

    inside changeValue().

    Compare the addresses.


    QUESTION

    Why is pass by reference useful when a
    function needs to modify the original data?
*/
