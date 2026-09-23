/*
    CSCI 272
    Lesson 2 — Adding Elements to a Vector

    Instructor: Avijit Roy
    Teaching page: https://avijitroy.com/teaching/

    Vectors provide several ways to add elements.

    This example demonstrates:
    - push_back()
    - insert()
    - emplace_back()
    - begin()
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;


void printFruits(const vector<string>& fruits)
{
    cout << "\nCurrent vector:" << endl;

    // See Lesson 02's traversal example for why an
    // unsigned size type matches vector::size().
    for (vector<string>::size_type i = 0; i < fruits.size(); i++)
    {
        cout << i
             << ": "
             << fruits[i]
             << endl;
    }
}


int main()
{
    vector<string> fruits = {
        "Apple",
        "Banana"
    };


    printFruits(fruits);


    // --------------------------------------------------
    // push_back()
    // --------------------------------------------------

    // Adds a value to the END.
    fruits.push_back("Orange");

    cout << "\nAfter push_back(\"Orange\"):";
    printFruits(fruits);


    // --------------------------------------------------
    // insert()
    // --------------------------------------------------

    // begin() points to index 0.
    //
    // begin() + 1 represents index 1.
    //
    // Grapes will be inserted at index 1.
    fruits.insert(
        fruits.begin() + 1,
        "Grapes"
    );

    cout << "\nAfter inserting Grapes at index 1:";
    printFruits(fruits);


    // --------------------------------------------------
    // emplace_back()
    // --------------------------------------------------

    // To construct an object means to create it and
    // initialize it with a starting value. Each fruit
    // here is a string object.
    //
    // emplace_back("Mango") passes "Mango" to the
    // string constructor, creating the new string
    // directly at the end of the vector.
    fruits.emplace_back("Mango");

    cout << "\nAfter emplace_back(\"Mango\"):";
    printFruits(fruits);


    return 0;
}


/*
    TRY THIS #1

    Add:

        fruits.push_back("Pineapple");

    Where does Pineapple appear?



    TRY THIS #2

    Insert:

        "Strawberry"

    at index 2.



    TRY THIS #3

    Before inserting Grapes, the vector is:

        Apple
        Banana
        Orange

    Predict what happens after:

        fruits.insert(
            fruits.begin() + 1,
            "Grapes"
        );



    TRY THIS #4

    "Construct" means create and initialize an object.
    For example, a string can be initialized with "Mango".

    With the string literal used above:

    push_back():

        Pass a string value to the vector,
        which may move it into place.

    emplace_back():

        Pass constructor arguments so the vector
        can construct the new string in place.

    This difference becomes more useful later
    when we create vectors containing objects.
    emplace_back() is not automatically faster:
    vector growth may still move existing elements.
*/
