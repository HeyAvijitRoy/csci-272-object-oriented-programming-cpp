/*
    CSCI 272
    Instructor: Avijit Roy
    Teaching page: https://avijitroy.com/teaching/
    Lesson 4 — Classes and Objects

    Example 2: Multiple Objects

    Every object created from the same class has its own copy of the data members.
*/

#include <iostream>
#include <string>
using namespace std;

class Car
{
public:
    string brand;
    string model;
    int year = 0; // Initialize before any experiment reads this member.

    void display() const
    {
        cout << brand << " "
             << model << " "
             << year << endl;
    }
};

int main()
{
    // Both objects come from the SAME class.
    Car car1;
    Car car2;

    // But they contain DIFFERENT values.

    car1.brand = "Volkswagen";
    car1.model = "Polo";
    car1.year = 2012;

    car2.brand = "Tesla";
    car2.model = "Model X";
    car2.year = 2022;

    cout << "Car 1:" << endl;
    car1.display();

    cout << endl;

    cout << "Car 2:" << endl;
    car2.display();

    return 0;
}

/*
    PREDICT: If car1.year changes, will car2.year also change?
    EXPECTED: Car 1 displays Volkswagen Polo 2012; Car 2 displays Tesla Model X 2022.

    TRY THIS:
    1. Set car1.year = 2025 after both objects are initialized, then display both.
    2. Add a third object and give it different values.
    3. Explain why these non-static data members belong to individual objects.
*/
