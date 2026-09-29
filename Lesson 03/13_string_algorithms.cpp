/*
   CSCI 272
   Lesson 3 — Strings and Standard Algorithms

   Instructor: Avijit Roy
   Teaching page: https://avijitroy.com/teaching/

   Strings work with many algorithms from
   the C++ Standard Library.

   begin() represents the beginning
   of the string.

   end() represents the position immediately
   AFTER the final character.

   std::count() can count how many times
   a value appears within a range.

   This example demonstrates:
   - begin()
   - end()
   - std::count()
   - Counting characters
*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    string sentence =
        "This is a sample sentence.";

    char targetCharacter = 's';

    cout << "Sentence: "
         << sentence
         << endl;

    /*
       begin() is an iterator to the first character.

       * means:
       give us the value stored at that position.
       An empty string has no first character.
    */
    if (!sentence.empty())
    {
        cout << "First character: "
             << *sentence.begin()
             << endl;

        // end() is one past the final character. It cannot
        // be dereferenced. Moving back one is safe here
        // because the string is nonempty.
        cout << "Last character: "
             << *(sentence.end() - 1)
             << endl;
    }
    else
    {
        cout << "The string has no first or last character."
             << endl;
    }

    /*
       count() examines all characters
       from begin() to end().

       It counts how many match targetCharacter.
       Character comparison is case-sensitive.
    */
    int characterCount =
        count(
            sentence.begin(),
            sentence.end(),
            targetCharacter
        );

    cout << "Number of occurrences of '"
         << targetCharacter
         << "': "
         << characterCount
         << endl;

    return 0;
}

/*
   TRY THIS #1

   Change:

       targetCharacter = 's';

   to:

       targetCharacter = 'e';

   Predict the count before running.


   TRY THIS #2

   Try:

       targetCharacter = 'z';

   What result do you expect?


   TRY THIS #3

   Notice:

       sentence.begin()

   represents the beginning of the string.

   And:

       sentence.end()

   represents the position AFTER the
   last character.


   TRY THIS #4

   Change the sentence to:

       "mississippi"

   Count:

       'i'
       's'
       'p'

   Predict each result first.


   TRY THIS #5

   Change the sentence to "". The count is still safe:
   begin() equals end() for the empty range. Explain why
   the first/last-character code must be skipped.

   DO NOT RUN a direct dereference of sentence.end().
*/
