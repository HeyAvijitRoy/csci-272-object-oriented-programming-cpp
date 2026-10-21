/*
    CSCI 272 — Lesson 5
    Instructor: Avijit Roy
    Teaching page: https://avijitroy.com/teaching/

    Example 04: Stream Output Operations

    Topics:
    - cout << value
    - cout.put()
    - cout.write()
    - string::c_str()
    - fixed and scientific notation

*/

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
    double pi = 3.14159265359;
    char ch = 'X';

    // ==================================
    // PART 1: Formatted output
    // ==================================

    // << formats pi as a floating-point value.
    cout << "Formatted double: "
         << pi << endl;

    // Convert double to a string. to_string normally produces 6 digits after the decimal for this example.
    string strValue = to_string(pi);

    cout << "Converted string: "
         << strValue << endl;

    // ==================================
    // PART 2: Unformatted write()
    // ==================================

    // c_str() returns a pointer to the character data inside the string.
    const char* charPtr = strValue.c_str();

    cout << "First 7 characters: ";

    // Write exactly 7 characters. No terminating '\0' is required.
    cout.write(charPtr, 7);

    cout << endl;

    // ==================================
    // PART 3: put()
    // ==================================

    cout << "Character output: ";

    // put() outputs one character.
    cout.put(ch);

    // We can chain put() calls.
    cout.put('!').put('\n');

    // ==================================
    // PART 4: Scientific notation
    // ==================================

    cout << scientific << setprecision(2);

    cout << "Scientific pi: "
         << pi << endl;

    cout << fixed << setprecision(2);

    cout << "Fixed pi: "
         << pi << endl;

    // Restore default formatting.
    cout << defaultfloat << setprecision(6);

    /*
        OBSERVE:
        write() sends the requested characters directly. Use readable character data for these experiments. Raw memory bytes of a double are not its decimal text.

        PREDICT:
        If charPtr points to "3.141593", what does write(charPtr, 7) print?

        Answer: 3.14159

        TRY THIS:
        Change 7 to 3, then 5, then 8. Observe that write() uses the count.

        Never request more bytes than the available character data.
    */

    return 0;
}
