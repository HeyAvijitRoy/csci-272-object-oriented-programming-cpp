/*
   CSCI 272
   Lesson 3 — substr() and find()

   Instructor: Avijit Roy
   Teaching page: https://avijitroy.com/teaching/

   Two useful string functions are:

       substr()
       find()

   substr() extracts part of a string.

   find() searches for characters or text
   inside a string.

   If find() cannot find something, it returns:

       string::npos

   This example demonstrates:
   - Extracting substrings
   - Searching strings
   - Working with string positions
   - string::npos
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string sentence =
        "The quick brown fox jumps over the lazy dog.";

    cout << "Sentence:" << endl;
    cout << sentence << endl;

    cout << endl;

    /*
       substr(startPosition, numberOfCharacters)

       Start at index 4
       and take 5 characters.
    */
    string word = sentence.substr(4, 5);

    cout << "Substring: " << word << endl;

    /*
       Search for the word "lazy".

       find() returns the index where
       the word begins. A missing word gives string::npos,
       which is not a usable character index.
    */
    size_t position = sentence.find("lazy");

    if (position != string::npos)
    {
        cout << "\"lazy\" was found." << endl;
        cout << "Starting index: "
             << position
             << endl;
    }
    else
    {
        cout << "\"lazy\" was not found."
             << endl;
    }

    return 0;
}

/*
   TRY THIS #1

   Change:

       sentence.substr(4, 5)

   to:

       sentence.substr(4, 11)

   What substring is produced?


   TRY THIS #2

   Search for:

       "fox"

   Predict its starting index before running.


   TRY THIS #3

   Search for:

       "cat"

   What happens?

   find() returns:

       string::npos

   DO NOT RUN sentence[string::npos].


   TRY THIS #4

   Change the sentence to:

       "C++ programming is fun."

   Use substr() to extract:

       programming

   Remember: the second argument is a count, not
   an ending index. Confirm the start and length
   before changing the call.
*/
