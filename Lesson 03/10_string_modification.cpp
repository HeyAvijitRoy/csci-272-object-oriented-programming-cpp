/*
   CSCI 272
   Lesson 3 — Modifying Strings

   Instructor: Avijit Roy
   Teaching page: https://avijitroy.com/teaching/

   C++ strings can be changed after they
   are created.

   Some useful operations include:

       toupper()
       tolower()
       replace()
       insert()

   This example demonstrates:
   - Changing characters
   - Converting text to uppercase
   - Replacing part of a string
   - Inserting text into a string
*/

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main()
{
    string message = "Hello, World!";

    cout << "Original: "
         << message
         << endl;

    /*
       The range-based for loop visits
       every character in the string.

       char& means we are working with
       the actual character inside message.

       Therefore, changing c changes message.
    */
    for (char& c : message)
    {
        c = static_cast<char>(
            toupper(
                static_cast<unsigned char>(c)
            )
        );
    }

    cout << "Uppercase: "
         << message
         << endl;

    /*
       Current value:

           HELLO, WORLD!

       Search for WORLD rather than assuming it will
       always begin at index 7. Replace only if found.
    */
    string::size_type wordStart = message.find("WORLD");
    if (wordStart != string::npos)
    {
        message.replace(wordStart, 5, "C++");
        cout << "After replace: " << message << endl;

        // The stored position still marks where C++ begins.
        message.insert(wordStart, "AWESOME ");
        cout << "After insert: " << message << endl;
    }

    return 0;
}

/*
   TRY THIS #1

   Before running the program, predict
   each output:

       Original
       Uppercase
       After replace
       After insert


   TRY THIS #2

   Change:

       message.replace(wordStart, 5, "C++");

   to:

       message.replace(7, 5, "CSCI");

   What happens?


   TRY THIS #3

   Change:

       message.insert(wordStart, "AWESOME ");

   to:

       message.insert(7, "LEARNING ");

   Predict the final string.


   TRY THIS #4

   Change toupper() to tolower().

   What happens to the message? Why does find("WORLD")
   then return string::npos and skip replace/insert?
*/
