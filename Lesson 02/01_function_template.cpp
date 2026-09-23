/*
    CSCI 272
    Lesson 2 — Function Templates

    Instructor: Avijit Roy
    Teaching page: https://avijitroy.com/teaching/

    A function template allows us to write one function
    that can work with different data types.

    Instead of creating separate functions for:

        int
        double
        char
        string

    we can create one generic function.

    This example demonstrates:
    - Function templates
    - typename
    - Generic parameters
    - Reusing the same function with different data types
*/

#include <iostream>
#include <string>
using namespace std;


// T is a placeholder for a data type.
//
// When the function is called, C++ determines
// what type T should represent.
template <typename T>
T largerOf(T first, T second)
{
    if (first > second)
    {
        return first;
    }

    return second;
}


int main()
{
    // --------------------------------------------------
    // Example 1: integers
    // --------------------------------------------------

    int a = 10;
    int b = 25;

    // Here, T becomes int.
    cout << "Larger integer: "
         << largerOf(a, b)
         << endl;


    // --------------------------------------------------
    // Example 2: doubles
    // --------------------------------------------------

    double x = 7.5;
    double y = 3.2;

    // Here, T becomes double.
    cout << "Larger double: "
         << largerOf(x, y)
         << endl;


    // --------------------------------------------------
    // Example 3: characters
    // --------------------------------------------------

    char letter1 = 'A';
    char letter2 = 'Z';

    // Characters can also be compared.
    cout << "Larger character: "
         << largerOf(letter1, letter2)
         << endl;


    // --------------------------------------------------
    // Example 4: strings
    // --------------------------------------------------

    string word1 = "Apple";
    string word2 = "Banana";

    // Strings are compared lexicographically
    // (similar to dictionary/alphabetical order).
    cout << "Larger string: "
         << largerOf(word1, word2)
         << endl;


    return 0;
}


/*
    TRY THIS #1

    Change:

        int a = 10;
        int b = 25;

    to:

        int a = 100;
        int b = 50;

    Predict the result before running the program.



    TRY THIS #2

    Add another call:

        cout << largerOf(50, 75) << endl;

    What data type does T represent?



    TRY THIS #3

    Try:

        cout << largerOf(10, 5.5) << endl;

    Does it compile?

    Why might C++ have difficulty deciding
    what type T should be when the arguments
    have different types?



    TRY THIS #4

    Create:

        string name1 = "John";
        string name2 = "Alice";

    Call largerOf() using the two strings.

    Which string is returned?
*/
