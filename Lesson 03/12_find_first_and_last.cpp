/*
   CSCI 272
   Lesson 3 — find_first_of() and find_last_of()

   Instructor: Avijit Roy
   Teaching page: https://avijitroy.com/teaching/

   find_first_of() searches for the first
   occurrence of ANY character from a set
   of characters.

   find_last_of() searches for the last
   occurrence.

   These functions search for ANY character in
   "aeiouAEIOU". They do not search for that whole
   sequence as a substring.

   This example demonstrates:
   - find_first_of()
   - find_last_of()
   - Searching for vowels
   - string::npos
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string sentence =
        "The quick brown fox jumps over the lazy dog.";

    // Characters we want to search for.
    string vowels = "aeiouAEIOU";

    cout << "Sentence:" << endl;
    cout << sentence << endl;

    cout << endl;

    // Search for the first vowel.
    size_t firstVowel =
        sentence.find_first_of(vowels);

    if (firstVowel != string::npos)
    {
        cout << "First vowel: "
             << sentence[firstVowel]
             << endl;

        cout << "First vowel index: "
             << firstVowel
             << endl;
    }
    else
    {
        cout << "No vowel was found."
             << endl;
    }

    cout << endl;

    // Search for the last vowel.
    size_t lastVowel =
        sentence.find_last_of(vowels);

    if (lastVowel != string::npos)
    {
        cout << "Last vowel: "
             << sentence[lastVowel]
             << endl;

        cout << "Last vowel index: "
             << lastVowel
             << endl;
    }
    else
    {
        cout << "No vowel was found."
             << endl;
    }

    return 0;
}

/*
   TRY THIS #1

   Change the sentence to:

       "Computer Science"

   Predict the first vowel.


   TRY THIS #2

   Predict the last vowel before running.


   TRY THIS #3

   Change:

       string vowels = "aeiouAEIOU";

   to:

       string numbers = "0123456789";

   Then search a string such as:

       "CSCI 272"


   TRY THIS #4

   Try a string containing no vowels:

       "rhythm"

   What does find_first_of() return?


   TRY THIS #5

   Explain why find_first_of("aeiou") is different
   from find("aeiou"). Which one could find the
   first vowel in "Computer Science"?
*/
