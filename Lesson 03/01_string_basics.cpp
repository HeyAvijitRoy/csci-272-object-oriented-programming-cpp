/*
   CSCI 272
   Lesson 3 — String Basics

   Instructor: Avijit Roy
   Teaching page: https://avijitroy.com/teaching/

   A string is a sequence of characters used to
   represent text.

   In C++, we commonly use the std::string class.

   This example demonstrates:
   - Including the <string> library
   - Declaring string variables
   - Initializing strings
   - Displaying strings
   - Accessing individual characters
   - Modifying individual characters
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
    // Create a string using the assignment operator.
    string greeting = "Hello, World!";

    // Another way to create a string is by using
    // the string constructor.
    string message("Welcome to CSCI 272!");

    cout << "Greeting: " << greeting << endl;
    cout << "Message: " << message << endl;

    // Strings use zero-based indexing.
    // Index 0 represents the first character.
    cout << "First character: " << greeting[0] << endl;

    // Change the W in World to a lowercase w.
    greeting[7] = 'w';

    cout << "Modified greeting: " << greeting << endl;

    return 0;
}

/*
   TRY THIS #1

   Change:

       string greeting = "Hello, World!";

   to:

       string greeting = "Good Morning!";

   Run the program again.


   TRY THIS #2

   Try printing different characters:

       cout << greeting[0] << endl;
       cout << greeting[1] << endl;
       cout << greeting[2] << endl;

   What does each index represent?


   TRY THIS #3

   Change one character:

       greeting[0] = 'Y';

   What does the string become?


   TRY THIS #4

   Remember:

       greeting[0]

   gives us a single character.

   But:

       greeting

   gives us the entire string.
*/
