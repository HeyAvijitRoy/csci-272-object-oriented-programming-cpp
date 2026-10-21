/*
    CSCI 272
    Instructor: Avijit Roy
    Teaching page: https://avijitroy.com/teaching/
    Lesson 4 — Constructors

    Example 4: Parameterized Constructor

    A constructor:
    - Has the same name as the class
    - Has no return type
    - Runs automatically when an object is created
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

    // Constructor
    //
    // Notice:
    // - Same name as the class
    // - No void
    // - No return type
    Car(string b, string m, int y)
    {
        cout << "Constructor called!" << endl;

        brand = b;
        model = m;
        year = y;
    }

    void display() const
    {
        cout << brand << " "
             << model << " "
             << year << endl;
    }
};

int main()
{
    // The constructor runs automatically here.
    Car car1("Volkswagen", "Polo", 2012);

    Car car2("Tesla", "Model X", 2022);

    car1.display();
    car2.display();

    return 0;
}

/*
    PREDICT: How many constructor messages appear before the two car records?
    EXPECTED: Two constructor calls, followed by Volkswagen Polo 2012 and Tesla Model X 2022.

    TRY THIS:
    1. Create a third Car and predict where its constructor message appears.
    2. Predict whether Car car3; compiles when only this three-argument constructor is provided.
    3. Add the year validation from example 03 to this constructor.

    A constructor has the class name and no return type. This version initializes data but does not validate the year.
*/
