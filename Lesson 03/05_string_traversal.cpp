/*
   CSCI 272
   Lesson 3 — Traversing a String

   Instructor: Avijit Roy
   Teaching page: https://avijitroy.com/teaching/

   Traversing means visiting each character in order.
   This bridge between indexing and later algorithms uses:
   - An index when we need a character's position
   - A range-based loop when we only need each character
   - A reference when we want to change the stored character
*/

#include <cstddef>
#include <iostream>
#include <string>

using namespace std;

void printCharacters(const string& text)
{
    // const string& reads the original string without copying it.
    for (std::size_t index = 0; index < text.size(); ++index)
    {
        cout << "Index " << index << ": " << text[index] << endl;
    }
}

int main()
{
    string word = "Code";

    cout << "Original: " << word << endl;
    printCharacters(word);

    // A plain char is a copy. Changing it does not change word.
    for (char character : word)
    {
        character = '*';
        cout << "Copy now: " << character << endl;
    }
    cout << "After changing copies: " << word << endl;

    // char& refers to each actual character stored in word.
    for (char& character : word)
    {
        if (character == 'o')
        {
            character = '0';
        }
    }
    cout << "After changing a reference: " << word << endl;

    return 0;
}

/*
   TRY THIS #1
   Predict all four index-and-character lines before running.

   TRY THIS #2
   Change word to "Book". How many 'o' characters become '0'?

   TRY THIS #3
   Remove the & from the second loop, run it, and explain why
   the printed string no longer changes. Restore the &.

   TRY THIS #4
   Add a counter to the index-based loop and count the
   characters without using size() for the final answer.
*/
