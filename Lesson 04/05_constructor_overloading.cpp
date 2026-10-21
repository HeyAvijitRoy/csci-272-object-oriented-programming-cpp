/*
    CSCI 272
    Instructor: Avijit Roy
    Teaching page: https://avijitroy.com/teaching/
    Lesson 4 — Constructor Overloading

    Example 5: Multiple Constructors

    Constructors can be overloaded just like regular functions.

    The compiler determines which constructor to call based on the arguments.
*/

#include <iostream>
#include <string>
using namespace std;

class Car
{
private:
    string brand;
    string model;
    int year;

public:

    // Default constructor Takes no arguments.
    Car()
    {
        cout << "Default constructor called." << endl;

        brand = "Unknown";
        model = "Unknown";
        year = 0;
    }

    // Parameterized constructor
    Car(string b, string m, int y)
    {
        cout << "Parameterized constructor called." << endl;

        brand = b;
        model = m;
        year = y;
    }

    void display() const
    {
        cout << brand << " | "
             << model << " | "
             << year << endl;
    }
};

int main()
{
    // No arguments -> default constructor
    Car car1;

    // Three arguments -> parameterized constructor
    Car car2("Volkswagen", "Polo", 2012);

    Car car3("Tesla", "Model X", 2022);

    cout << endl;

    car1.display();
    car2.display();
    car3.display();

    return 0;
}

/*
    PREDICT: Which constructor is selected for each of the three objects?
    EXPECTED: One default-constructor message, two parameterized-constructor messages, then the three records. The default record is Unknown | Unknown | 0.

    TRY THIS:
    1. Change the default model and predict which record changes.
    2. Predict whether Car car4("Honda"); compiles. No one-argument constructor exists here.
    3. Add a one-argument constructor and give the remaining members explicit initial values.

    Here, year 0 means unspecified. A default constructor takes no arguments; it is not automatically supplied when you declare only a parameterized constructor.
*/
