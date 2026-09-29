/*
   CSCI 272
   Lesson 3 — Case-Insensitive String Comparison

   Instructor: Avijit Roy
   Teaching page: https://avijitroy.com/teaching/

   Normal C++ string comparison is case-sensitive.

   For example:

       "Hello" != "hello"

   Sometimes we want to ignore uppercase
   and lowercase differences.

   This example demonstrates:
   - String comparison
   - length()
   - Character indexing
   - tolower()
   - Loops
   - Functions
   - const reference parameters
*/

#include <iostream>
#include <string>
#include <cctype>
#include <cstddef>

using namespace std;

// Compare two strings while ignoring letter case.
bool caseInsensitiveCompare(const string& first,
                            const string& second)
{
    /*
       If the strings have different lengths,
       they cannot contain exactly the same characters.
    */
    if (first.length() != second.length())
    {
        return false;
    }

    /*
       Compare the strings one character at a time.
    */
    for (std::size_t i = 0; i < first.length(); i++)
    {
        /*
           Convert both characters to lowercase before
           comparing them. cctype functions require an
           unsigned-char value (or EOF), so make that
           conversion before calling tolower().
        */
        char firstCharacter =
            static_cast<char>(
                tolower(
                    static_cast<unsigned char>(first[i])
                )
            );

        char secondCharacter =
            static_cast<char>(
                tolower(
                    static_cast<unsigned char>(second[i])
                )
            );

        if (firstCharacter != secondCharacter)
        {
            return false;
        }
    }

    // Every character matched. This is a basic single-byte
    // demonstration, not full Unicode case folding.
    return true;
}

int main()
{
    string word1 = "Hello";
    string word2 = "HELLO";

    cout << "Word 1: " << word1 << endl;
    cout << "Word 2: " << word2 << endl;

    cout << endl;

    // Normal comparison is case-sensitive.
    if (word1 == word2)
    {
        cout << "Normal comparison: Equal" << endl;
    }
    else
    {
        cout << "Normal comparison: Not equal" << endl;
    }

    // Our function ignores case.
    if (caseInsensitiveCompare(word1, word2))
    {
        cout << "Case-insensitive comparison: Equal"
             << endl;
    }
    else
    {
        cout << "Case-insensitive comparison: Not equal"
             << endl;
    }

    return 0;
}

/*
   TRY THIS #1

   Compare:

       "APPLE"
       "apple"

   What does normal == comparison say?

   What does caseInsensitiveCompare() say?


   TRY THIS #2

   Compare:

       "Hello"
       "Hello!"

   Why does the function immediately return false?


   TRY THIS #3

   Compare:

       "John"
       "JOAN"

   The strings have the same length.

   At which index will the comparison fail?


   TRY THIS #4

   Notice the function parameters:

       const string& first
       const string& second

   The & avoids making unnecessary copies.

   const means the function cannot change
   the original strings.
*/
