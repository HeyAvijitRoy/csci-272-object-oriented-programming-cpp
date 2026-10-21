/*
    CSCI 272
    Instructor: Avijit Roy
    Teaching page: https://avijitroy.com/teaching/
    Lesson 4 — Classes and Objects

    Example 1: Our First Class

    A class is a blueprint. An object is an instance of that class.

    This example demonstrates:
    - Creating a class
    - Data members
    - Member functions
    - Creating an object
    - Using the dot operator
*/

#include <iostream>
#include <string>
using namespace std;

// Define a new class called Car
class Car
{
public:

    // Data members These variables describe the state of a Car object.
    string brand;
    string model;
    int year = 0; // Initialize before any experiment reads this member.

    // Member function This function describes something a Car can do.
    void startEngine()
    {
        cout << "Engine started!" << endl;
    }
};

int main()
{
    // car1 is an OBJECT of the Car class.
    Car car1;

    // Assign values to the object's data members.
    car1.brand = "Volkswagen";
    car1.model = "Polo";
    car1.year = 2012;

    // Access data using the dot operator.
    cout << "Brand: " << car1.brand << endl;
    cout << "Model: " << car1.model << endl;
    cout << "Year: " << car1.year << endl;

    // Call a member function.
    car1.startEngine();

    return 0;
}

/*
    PREDICT: Which values belong to the class definition, and which belong to car1?
    EXPECTED: Volkswagen, Polo, 2012, followed by Engine started!

    TRY THIS:
    1. Change car1.model and predict which output line changes.
    2. Add a second Car, assign its data, and call its startEngine().
    3. Add a color data member and print it through the dot operator.
*/
