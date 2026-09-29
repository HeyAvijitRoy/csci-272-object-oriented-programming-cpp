/*
   CSCI 272
   Lesson 3 — String Length and Indexing

   Instructor: Avijit Roy
   Teaching page: https://avijitroy.com/teaching/

   A string is a sequence of characters.

   Every character has an index.

   String indexing begins at 0.

   Example:

       H e l l o
       0 1 2 3 4

   Strings also provide:

       length()
       size()

   Both return the number of stored char elements.
   With UTF-8 text, one visible symbol may use
   more than one char.

   This example demonstrates:
   - length()
   - size()
   - Zero-based indexing
   - Finding the first character
   - Finding the last character
   - Checking whether a string is empty
   - Using at() for a checked index
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string message = "Hello, World!";

    cout << "Message: " << message << endl;

    // length() returns the number of characters.
    cout << "Length: " << message.length() << endl;

    // size() returns the same value for a string.
    cout << "Size: " << message.size() << endl;

    // size() is an unsigned count. An empty string has no last
    // character; subtracting 1 from size() would wrap around.
    if (!message.empty())
    {
        // First character is always index 0.
        cout << "First character: "
             << message[0]
             << endl;

        // Last valid index is length - 1.
        cout << "Last character: "
             << message[message.length() - 1]
             << endl;

    }
    else
    {
        cout << "This string has no characters to index." << endl;
    }

    // Index 4 exists only when the string has at least 5 characters.
    if (message.size() > 4)
    {
        cout << "Character at index 4: " << message.at(4) << endl;
    }

    // [] assumes a valid index. at() checks and throws
    // std::out_of_range for an invalid one.

    return 0;
}

/*
   TRY THIS #1

   For:

       Hello

   Predict:

       message[0]
       message[1]
       message[4]

   before running the program.


   TRY THIS #2

   Change:

       string message = "Hello, World!";

   to:

       string message = "C++";

   What are:

       message.length()
       message[0]
       message[2]


   TRY THIS #3

   Print:

       message[message.length() - 1]

   Explain why we subtract 1.


   TRY THIS #4

   Change the string to:

       string message = "";

   The string now has zero characters.

   Why is checking:

       if (!message.empty())

   useful before accessing message[0]?

   DO NOT RUN an invalid message[0] access.


   TRY THIS #5

   Change message to "C++". Why is index 4 skipped?
   What would message.at(4) do without the size check?
*/
