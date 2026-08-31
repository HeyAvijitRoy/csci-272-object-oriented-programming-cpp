/*
    CSCI 272
    Lesson 1 — Function Prototypes

    Instructor: Avijit Roy
    Teaching page: https://avijitroy.com/teaching/

    A function prototype tells the compiler that
    a function exists before the function is called.
*/

#include <iostream>
using namespace std;

// Function prototype / declaration
double multiply(double a, double b);

int main()
{
    double result = multiply(5, 4);

    cout << "Result: " << result << endl;

    return 0;
}

// Function definition
double multiply(double a, double b)
{
    return a * b;
}

/*
    TRY THIS #1

    Comment out the function prototype:

        double multiply(double a, double b);

    Compile the program.

    What error does the compiler produce?

    Why?


    TRY THIS #2

    Move the complete multiply() function above main().

    Do you still need the prototype?


    THINK ABOUT IT

    C++ reads the source code in order.

    When the compiler reaches:

        multiply(5, 4)

    it must already know that multiply() exists.
*/
