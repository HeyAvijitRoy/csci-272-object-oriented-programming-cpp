/*
    CSCI 272
    Lesson 1 — Pass by Value

    Instructor: Avijit Roy
    Teaching page: https://avijitroy.com/teaching/

    With pass by value, the function receives
    a COPY of the argument.

    Changing the parameter does not change
    the original variable.
*/

#include <iostream>
using namespace std;

void changeValue(int number)
{
    cout << "Inside function before change: "
         << number << endl;

    number = 100;

    cout << "Inside function after change: "
         << number << endl;
}

int main()
{
    int value = 10;

    cout << "Before function: " << value << endl;

    changeValue(value);

    cout << "After function: " << value << endl;

    return 0;
}

/*
    BEFORE RUNNING:

    Predict the final value of:

        value


    TRY THIS #1

    Change:

        number = 100;

    to:

        number = 500;

    Does value inside main() change?


    TRY THIS #2

    Print the addresses:

    Inside main():

        cout << &value << endl;

    Inside changeValue():

        cout << &number << endl;

    Are the addresses the same?

    Why or why not?


    KEY IDEA

    Pass by value creates a separate copy.
*/
