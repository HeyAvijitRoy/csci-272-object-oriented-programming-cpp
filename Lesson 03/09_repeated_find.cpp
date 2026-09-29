/*
   CSCI 272
   Lesson 3 — Finding Repeated Matches

   Instructor: Avijit Roy
   Teaching page: https://avijitroy.com/teaching/

   find(target, startPosition) starts searching at startPosition.
   A later call can look beyond a match already found.
   When there is no later match, find() returns string::npos.

   This example searches for a nonempty target so advancing
   past each match always makes progress.
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string text = "banana bandana";
    string target = "ana";

    cout << "Text: " << text << endl;
    cout << "Target: " << target << endl;

    if (target.empty())
    {
        cout << "Choose a nonempty target." << endl;
        return 0;
    }

    string::size_type position = text.find(target);
    int matches = 0;

    while (position != string::npos)
    {
        cout << "Match at index " << position << endl;
        ++matches;

        // Move one character past this start so overlapping
        // matches would also be found. Never add to npos.
        position = text.find(target, position + 1);
    }

    cout << "Total matches: " << matches << endl;
    return 0;
}

/*
   TRY THIS #1
   Predict the match indexes for "ana" in "banana bandana".
   Count from zero. Then check your prediction by running.

   TRY THIS #2
   Change text to "aaaa" and target to "aa".
   Which matches overlap? Why are there three starts?

   TRY THIS #3
   Change target to "xyz". What does the loop print?
   Explain why comparing with string::npos matters.

   TRY THIS #4
   Change position + 1 to position + target.length().
   Compare the output for "aaaa" and "aa". Explain why
   this version counts only non-overlapping matches.
*/
