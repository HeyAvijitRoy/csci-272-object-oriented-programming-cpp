/*
    CSCI 272
    Lesson 1 — Variable and Parameter Scope

    Instructor: Avijit Roy
    Teaching page: https://avijitroy.com/teaching/

    Variables declared inside a function are local
    to that function.
*/

#include <iostream>
using namespace std;

void showNumber(int number)
{
    // number is local to showNumber()
    int doubled = number * 2;

    cout << "Inside function: " << doubled << endl;
}

int main()
{
    int value = 10;

    showNumber(value);

    cout << "Inside main: " << value << endl;

    return 0;
}

/*
    TRY THIS #1

    Add this inside main():

        cout << doubled << endl;

    Try compiling.

    Why does it fail?


    TRY THIS #2

    Add this inside showNumber():

        cout << value << endl;

    Why does this also fail?


    MAIN IDEA

    value belongs to main().

    doubled belongs to showNumber().

    Each function has its own local scope.
*/
