/*
    CSCI 272
    Instructor: Avijit Roy
    Teaching page: https://avijitroy.com/teaching/
    Lesson 4 — Copy Constructor

    A copy constructor creates a NEW object using an EXISTING object of the same class.
*/

#include <iostream>
#include <string>
using namespace std;

class Car
{
private:
    string model;
    int year;

public:

    // Parameterized constructor
    Car(string m, int y)
    {
        model = m;
        year = y;

        cout << "Regular constructor called." << endl;
    }


    // Copy constructor
    Car(const Car& other)
    {
        model = other.model;
        year = other.year;

        cout << "Copy constructor called." << endl;
    }


    void setYear(int y)
    {
        year = y;
    }

    void display() const
    {
        cout << model
             << " | "
             << year
             << endl;
    }
};


int main()
{
    // First object
    Car car1("Polo", 2012);

    // Create car2 by copying car1.
    Car car2(car1);

    cout << endl;

    car1.display();
    car2.display();

    car2.setYear(2025);
    cout << "After changing the copy:" << endl;
    car1.display();
    car2.display();

    return 0;
}

/*
    PREDICT: Does Car car2(car1) create a second object or a pointer to car1?
    EXPECTED: One regular-constructor message, one copy-constructor message, and two Polo | 2012 records. Changing car2's year then leaves car1 unchanged.

    TRY THIS:
    1. Use Car car2 = car1; at the declaration and compare the constructor messages.
    2. Change the copied object's year again and display both objects.

    const Car& other refers to the existing source without making another copy or allowing this constructor to change it. Each string and integer member is copied into the new object. For these members a compiler-generated copy constructor would already work; this explicit version makes the operation visible. Copying classes that own raw pointers requires further study.
*/
