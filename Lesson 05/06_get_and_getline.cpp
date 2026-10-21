/*
    CSCI 272 — Lesson 5
    Instructor: Avijit Roy
    Teaching page: https://avijitroy.com/teaching/

    Example 06: get() and getline()

    Topics:
    - cin.get()
    - getline()
    - cin.ignore()
    - Whitespace and newline characters

    Real-world example:
    Reading a student's full name.
*/

#include <iostream>
#include <string>
#include <limits>
using namespace std;

int main()
{
    // ==================================
    // PART 1: Reading one character
    // ==================================

    char ch;

    cout << "Enter a character: ";

    // get() reads the next character. It does NOT skip whitespace.
    if (!cin.get(ch))
    {
        cerr << "Unable to read a character.\n";
        return 1;
    }

    // Print the character between brackets. This makes a space character visible.
    cout << "You entered: ["
         << ch << "]" << endl;

    // ==================================
    // PART 2: Clearing leftover input
    // ==================================

    // If the user typed A and pressed Enter, the newline remains after get() reads A.
    //
    // ignore() discards the rest of this line, including the newline character.
    cin.ignore(
        numeric_limits<streamsize>::max(),
        '\n'
    );

    // ==================================
    // PART 3: Reading a full line
    // ==================================

    string fullName;

    cout << "Enter your full name: ";

    // getline() reads spaces as part of the input until the newline.
    if (!getline(cin, fullName))
    {
        cerr << "Unable to read the full name.\n";
        return 1;
    }

    cout << "Hello, "
         << fullName << "!" << endl;

    /*
        OBSERVE:
        Notice that >> and getline() do not read strings the same way.

        cin >> fullName;
        Usually stops at the first space.

        getline(cin, fullName);
        Reads the whole line.

        PREDICT:
        Why did we use cin.ignore()?

        Answer:
        To discard remaining characters on the character-input line.

        TRY THIS:
        1. Enter A, then Alice Johnson.
        2. Enter a space as the character.
        3. Remove cin.ignore() and test again.
        4. Replace getline(cin, fullName) with cin >> fullName.

        Observe the differences.

        IMPORTANT:
        ignore() is NOT required before every getline(). It is needed here because previous input has left characters in the stream.
    */

    return 0;
}
