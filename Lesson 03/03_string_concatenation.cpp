/*
   CSCI 272
   Lesson 3 — String Concatenation

   Instructor: Avijit Roy
   Teaching page: https://avijitroy.com/teaching/

   Concatenation means combining strings.

   In C++, strings can be combined using:

       +

   We can also add more text to an existing
   string using:

       +=

   This example demonstrates:
   - Combining strings with +
   - Adding spaces between strings
   - Appending text using +=
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string firstName = "John";
    string lastName = "Doe";

    // Combine firstName, a space, and lastName.
    string fullName = firstName + " " + lastName;

    cout << "First Name: " << firstName << endl;
    cout << "Last Name: " << lastName << endl;
    cout << "Full Name: " << fullName << endl;

    // += adds more text to the existing string.
    fullName += " Jr.";

    cout << "Updated Full Name: " << fullName << endl;

    return 0;
}

/*
   TRY THIS #1

   Remove the space:

       string fullName = firstName + lastName;

   What happens?

   Why do we need:

       " "

   between the two names?


   TRY THIS #2

   Change:

       firstName = "John"
       lastName = "Doe"

   to your own first and last name.


   TRY THIS #3

   Add another string:

       string title = "Professor";

   Create:

       Professor John Doe


   TRY THIS #4

   Add more text using +=:

       fullName += " Ph.D.";

   Observe how the existing string changes.
*/
