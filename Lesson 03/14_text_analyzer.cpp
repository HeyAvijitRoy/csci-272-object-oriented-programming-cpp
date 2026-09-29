/*
   CSCI 272
   Lesson 3 — Mini Text Analyzer

   Instructor: Avijit Roy
   Teaching page: https://avijitroy.com/teaching/

   This example combines several concepts
   from Lesson 3 into one program.

   This example demonstrates:
   - getline()
   - length()
   - empty()
   - String indexing
   - find()
   - string::npos
   - find_first_of()
   - find_last_of()
   - begin()
   - end()
   - std::count()

   This is intended as a review of the
   major string concepts from Lesson 3.
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <limits>

using namespace std;

int main()
{
    string sentence;

    cout << "Enter a sentence: ";
    if (!getline(cin, sentence))
    {
        return 0;
    }

    cout << endl;
    cout << "========== TEXT ANALYSIS =========="
         << endl;

    cout << endl;

    // Display the original sentence.
    cout << "Sentence: "
         << sentence
         << endl;

    // Display the number of characters.
    cout << "Number of characters: "
         << sentence.length()
         << endl;

    /*
       Check that the string contains something
       before accessing individual characters.
    */
    if (!sentence.empty())
    {
        cout << "First character: "
             << sentence[0]
             << endl;

        cout << "Last character: "
             << sentence[sentence.length() - 1]
             << endl;
    }
    else
    {
        cout << "No first or last character (empty sentence)."
             << endl;
    }

    cout << endl;

    // ------------------------------------
    // Count a character
    // ------------------------------------

    char targetCharacter;

    cout << "Enter a character to count: ";
    if (!(cin >> targetCharacter))
    {
        return 0;
    }

    int characterCount =
        count(
            sentence.begin(),
            sentence.end(),
            targetCharacter
        );

    cout << "'"
         << targetCharacter
         << "' appears "
         << characterCount
         << " time(s)."
         << endl;

    cout << endl;

    // ------------------------------------
    // Find the first and last vowel
    // ------------------------------------

    string vowels = "aeiouAEIOU";

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
        cout << "No vowels were found."
             << endl;
    }

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

    cout << endl;

    // ------------------------------------
    // Search for text
    // ------------------------------------

    string searchWord;

    cout << "Enter text to search for: ";

    /*
       cin >> targetCharacter leaves the rest of that
       input line behind. Discard it before getline().
       Unlike cin >> ws, this allows an empty search
       line and preserves leading spaces if entered.
    */
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    if (!getline(cin, searchWord))
    {
        return 0;
    }

    if (searchWord.empty())
    {
        // find("") would report index 0, which is not
        // useful for this search exercise.
        cout << "Enter nonempty text to search for."
             << endl;
    }
    else
    {
        // find() matches a substring, even inside a longer word.
        size_t position = sentence.find(searchWord);

        if (position != string::npos)
        {
            cout << "\""
                 << searchWord
                 << "\" was found."
                 << endl;

            cout << "Starting index: "
                 << position
                 << endl;
        }
        else
        {
            cout << "\""
                 << searchWord
                 << "\" was not found."
                 << endl;
        }
    }

    cout << endl;
    cout << "==================================="
         << endl;

    return 0;
}

/*
   TRY THIS #1

   Enter:

       C++ programming is fun and useful.

   Then search for:

       programming

   At what index does it begin?


   TRY THIS #2

   Count the character:

       g

   Predict the result before running.


   TRY THIS #3

   Search for:

       Python

   What happens?

   Why does find() return string::npos?


   TRY THIS #4

   Try the sentence:

       Welcome to CSCI 272 Object Oriented Programming

   Find:

       - Number of characters
       - First character
       - Last character
       - First vowel
       - Last vowel
       - Number of times 'o' appears


   CHALLENGE

   Modify the program so that it also counts
   the number of spaces in the sentence.

   Hint:

       count(
           sentence.begin(),
           sentence.end(),
           ' '
       );


   EXTRA CHALLENGE

   Ask the user for TWO words.

   Determine which one appears first
   in the sentence by comparing the
   positions returned by find().

   Check each position against string::npos before
   comparing them. A missing word has no position.
*/
