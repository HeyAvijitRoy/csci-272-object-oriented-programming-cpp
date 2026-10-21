/*
    CSCI 272
    Instructor: Avijit Roy
    Teaching page: https://avijitroy.com/teaching/
    Lesson 4 — Objects and Pointers

    Example 6: Dot Operator vs Arrow Operator

    Normal object:
        object.member

    Pointer to object:
        pointer->member
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
    }

    void display() const
    {
        cout << "Model: " << model << endl;
    }
};

int main()
{
    // Normal object
    Car car1("Polo");

    // Use . with a normal object
    car1.display();


    // Pointer stores the address of car1
    Car* carPointer = &car1;

    cout << "Address of car1: "
         << carPointer << endl;


    // Use -> when accessing an object through a pointer.
    carPointer->display();


    // These two statements mean the same thing:
    carPointer->display();

    (*carPointer).display();


    return 0;
}

/*
    PREDICT: Do car1, carPointer->, and (*carPointer). access different objects?
    EXPECTED: Model: Polo appears four times. The printed address may differ between runs.

    TRY THIS:
    1. Point carPointer at a second Car that is still in scope, then display through it.
    2. Explain why (*carPointer).display() needs parentheses.

    The pointer refers to an existing local object and does not own it. Do not delete it. DO NOT RUN a null-pointer dereference or use a pointer after its target's lifetime ends.
*/
