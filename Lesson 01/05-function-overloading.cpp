/*
    CSCI 272
    Lesson 1 — Function Overloading

    Instructor: Avijit Roy
    Teaching page: https://avijitroy.com/teaching/

    C++ allows multiple functions to have the
    same name when their parameter lists differ.

    The compiler determines which function to call
    based on the arguments.
*/

#include <iostream>
using namespace std;

// Version 1: two integers
int add(int a, int b)
{
    cout << "Using add(int, int)" << endl;
    return a + b;
}

// Version 2: three integers
int add(int a, int b, int c)
{
    cout << "Using add(int, int, int)" << endl;
    return a + b + c;
}

// Version 3: two doubles
double add(double a, double b)
{
    cout << "Using add(double, double)" << endl;
    return a + b;
}

int main()
{
    cout << add(5, 10) << endl;

    cout << endl;

    cout << add(2, 4, 6) << endl;

    cout << endl;

    cout << add(2.5, 3.7) << endl;

    return 0;
}

/*
    TRY THIS #1

    Predict which function is called by:

        add(5, 10)

        add(2, 4, 6)

        add(2.5, 3.7)


    TRY THIS #2

    Create another overloaded function:

        double add(double a, double b, double c)


    TRY THIS #3 — COMPILER EXPERIMENT

    Try creating:

        int test(int x)
        {
            return x;
        }

        double test(int x)
        {
            return x;
        }

    Compile the program.

    Does C++ allow overloading based only on
    the return type?

    Answer: No.

    Overloaded functions must differ in their
    parameter lists.
*/
