/*
    CSCI 272 — Lesson 5
    Example 08: Stream Error Recovery

    Instructor: Avijit Roy
    Teaching page: https://avijitroy.com/teaching/

    Topics:
    - cin.good()
    - cin.fail()
    - cin.bad()
    - cin.eof()
    - cin.rdstate()
    - cin.clear()
    - cin.ignore()

    Real-world example:
    Validate age input and let the user try again when the wrong type is entered.

*/

#include <iostream>
#include <limits>
using namespace std;

// ========================================
// Function 1: Display input stream flags
// ========================================

void displayCinFlags()
{
    // boolalpha prints true/false instead of 1/0.
    cout << boolalpha;

    cout << "\n=== Stream State ===\n";

    // rdstate() returns the state-bit value.
    cout << "cin.rdstate(): "
         << cin.rdstate() << endl;

    // true if end-of-file was encountered.
    cout << "cin.eof(): "
         << cin.eof() << endl;

    // true if a failure condition exists.
    cout << "cin.fail(): "
         << cin.fail() << endl;

    // true if a serious I/O error occurred.
    cout << "cin.bad(): "
         << cin.bad() << endl;

    // true only if no error flags are set.
    cout << "cin.good(): "
         << cin.good() << endl;
}

// ========================================
// Function 2: Recover from invalid input
// ========================================

void recoverFromInvalidInput()
{
    // STEP 1:
    // Clear the stream's error flags.
    cin.clear();

    // STEP 2:
    // Discard characters left on the current input line.
    //
    // max() allows ignore() to continue until it finds '\n' or reaches EOF.
    cin.ignore(
        numeric_limits<streamsize>::max(),
        '\n'
    );
}

// ========================================
// Main program
// ========================================

int main()
{
    int age = 0;

    cout << "Before input:\n";
    displayCinFlags();

    // Keep asking until an integer is read.
    while (true)
    {
        cout << "\nEnter your age: ";

        // Successful extraction returns a stream that converts to true.
        if (cin >> age)
        {
            cout << "\nValid integer received!"
                 << endl;

            // Discard remaining characters from this input line.
            cin.ignore(
                numeric_limits<streamsize>::max(),
                '\n'
            );

            break;
        }

        // The input conversion failed.
        cerr << "\nError: Expected an integer."
             << endl;

        cout << "\nAfter failed input:\n";
        displayCinFlags();

        // EOF and serious I/O errors must be handled separately. If no more input exists or the stream is broken, stop.
        if (cin.eof() || cin.bad())
        {
            cerr << "Input ended or a serious I/O error occurred.\n";
            return 1;
        }

        cout << "\nRecovering stream...\n";

        // Reset flags and remove bad input.
        recoverFromInvalidInput();

        cout << "\nAfter recovery:\n";
        displayCinFlags();

        // Loop begins again.
    }

    // At this point we received an integer.
    cout << "\nYour age is: "
         << age << endl;

    /*
        OBSERVE:
        Use these inputs in sequence:

        First: abc
        Second: 25

        After abc:
        fail() is true. good() is false.

        After clear() and ignore():
        good() is normally true again.

        After 25:
        The program finishes successfully.

        IMPORTANT:
        clear() does NOT remove bad text. ignore() discards it.

        PREDICT:
        What happens if we remove clear()?

        The extraction stream remains in its failed state.

        What happens if we remove ignore()?

        The invalid characters remain. The next extraction can fail again.

        TRY THIS:
        1. Enter abc, then 25.
        2. Predict what happens without clear().
        3. Predict what happens without ignore().
        DO NOT RUN either removal in this retry loop:
        it can repeatedly fail and flood the console. Use a single input attempt to investigate instead.

        NOTE:
        This checks whether an integer can be extracted. Input like "25abc" can still extract 25 successfully. Full-line validation is a separate enhancement.
    */

    return 0;
}
