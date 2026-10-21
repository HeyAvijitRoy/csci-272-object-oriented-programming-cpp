/*
    CSCI 272
    Instructor: Avijit Roy
    Teaching page: https://avijitroy.com/teaching/
    Lesson 4 — Encapsulation

    Example 3: Private Data

    Private data cannot be accessed directly from outside the class.

    Public member functions provide controlled access to that data.
*/

#include <iostream>
#include <string>
using namespace std;

class Car
{
private:

    // These members belong to the object, but outside code cannot directly access them.
    string brand = "Unknown";
    string model = "Unknown";
    int year = 1886;

public:

    // This public function allows us to safely set the object's data.
    void setData(string b, string m, int y)
    {
        brand = b;
        model = m;

        // Simple validation
        if (y > 1885)
        {
            year = y;
        }
        else
        {
            year = 1886;
        }
    }

    // Public function can access private data.
    void display() const
    {
        cout << "Brand: " << brand << endl;
        cout << "Model: " << model << endl;
        cout << "Year: " << year << endl;
    }
};

int main()
{
    Car car1;

    car1.setData("Volkswagen", "Polo", 2012);

    car1.display();

    // Try uncommenting this:
    //
    // car1.year = 2025;
    //
    // It will NOT compile because year is private.

    return 0;
}

/*
    PREDICT: Can main() assign car1.year directly now that year is private?
    EXPECTED: setData() stores Volkswagen, Polo, and 2012; display() can read the private members.

    TRY THIS:
    1. Pass -5000 as the year to setData(). The example substitutes 1886.
    2. Display a newly created Car before setData() to inspect its initial values.
    3. Predict the compiler error from direct access to car1.year; restore the commented line afterward.

    The minimum year of 1886 is this example's chosen validation rule. Private access alone does not validate data; setData() implements that rule.
*/
