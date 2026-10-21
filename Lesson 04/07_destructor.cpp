/*
    CSCI 272
    Instructor: Avijit Roy
    Teaching page: https://avijitroy.com/teaching/
    Lesson 4 — Destructors

    Example 7: Object Lifetime

    A destructor runs automatically when an object is destroyed.

    This example uses a nested scope so that we can clearly see when destruction occurs.
*/

#include <iostream>
#include <string>
using namespace std;

class Car
{
private:
    string model;

public:

    Car(string m)
    {
        model = m;

        cout << "Constructor: "
             << model
             << " created."
             << endl;
    }

    // Destructor
    ~Car()
    {
        cout << "Destructor: "
             << model
             << " destroyed."
             << endl;
    }
};

int main()
{
    cout << "Program starts." << endl;

    Car car1("Polo");

    cout << endl;

    {
        cout << "Entering inner scope..." << endl;

        Car car2("Tesla");

        cout << "Leaving inner scope..." << endl;

    } // car2 is destroyed HERE

    cout << endl;

    cout << "Back inside main()." << endl;

    cout << "Program ending..." << endl;

    return 0;

} // car1 is destroyed HERE

/*
    PREDICT: Which object is destroyed first, and at which closing brace?
    EXPECTED: Tesla is destroyed when the inner scope ends; Polo is destroyed as main() exits, after Program ending...

    TRY THIS:
    1. Add another named Car inside the inner scope and predict destruction order.
    2. Move the inner Car outside the nested braces and compare its lifetime.

    Automatic local objects are destroyed in reverse construction order within their scope. Do not explicitly call a destructor in these experiments. This class owns no manual resource; its destructor prints messages to make lifetime visible.
*/
