/*
   CSCI 272
   Lesson 3 — Comparing Strings

   Instructor: Avijit Roy
   Teaching page: https://avijitroy.com/teaching/

   C++ strings can be compared using:

       ==
       !=
       <
       >
       <=
       >=

   String comparisons are lexicographical.

   This is similar to dictionary ordering:
   compare characters from left to right, and if
   one word is a prefix, the shorter word comes first.
   Capital and lowercase letters are different;
   do not assume comparisons ignore letter case.

   String comparison is also case-sensitive.

   This example demonstrates:
   - Checking whether strings are equal
   - Checking whether strings are different
   - Lexicographical comparison
   - Case sensitivity
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string first = "apple";
    string second = "banana";

    cout << "First: " << first << endl;
    cout << "Second: " << second << endl;

    cout << endl;

    if (first == second)
    {
        cout << "The strings are equal." << endl;
    }
    else
    {
        cout << "The strings are not equal." << endl;
    }

    // Lexicographical comparison.
    if (first < second)
    {
        cout << first
             << " comes before "
             << second
             << endl;
    }
    else
    {
        cout << first
             << " does not come before "
             << second
             << endl;
    }

    cout << endl;

    string word1 = "Hello";
    string word2 = "hello";

    cout << "Comparing "
         << word1
         << " and "
         << word2
         << endl;

    if (word1 == word2)
    {
        cout << "They are equal." << endl;
    }
    else
    {
        cout << "They are NOT equal." << endl;
    }

    return 0;
}

/*
   TRY THIS #1

   Change:

       first = "apple"
       second = "banana"

   to:

       first = "cat"
       second = "dog"

   Which string comes first?


   TRY THIS #2

   Try:

       first = "banana"
       second = "apple"

   What changes?


   TRY THIS #3

   Compare:

       "Hello"
       "hello"

   Are they considered equal?


   TRY THIS #4

   Try:

       "Apple"
       "apple"

   C++ string comparison is case-sensitive.


   TRY THIS #5

   Compare "app" with "apple". The first three
   characters match. Which string comes first?
*/
