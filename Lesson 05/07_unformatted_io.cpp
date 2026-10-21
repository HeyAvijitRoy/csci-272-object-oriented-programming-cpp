/*
    CSCI 272 — Lesson 5
    Instructor: Avijit Roy
    Teaching page: https://avijitroy.com/teaching/

    Example 07: Unformatted Input/Output

    Topics:
    - read()
    - write()
    - gcount()
    - Character buffers
    - End-of-file and partial reads

*/

#include <iostream>
#include <sstream>
using namespace std;

int main()
{
    // ====================================
    // PART 1: write() example
    // ====================================

    cout << "First 10 letters: ";

    // Write exactly 10 bytes.
    cout.write(
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ",
        10
    );

    cout << endl;

    // ====================================
    // PART 2: read() example
    // ====================================

    const int SIZE = 80;

    // A char array holds the extracted bytes.
    char buffer[SIZE];

    // A fixed string makes the demonstration repeatable without keyboard blocking.
    //
    // cin.read(buffer, 20) would use keyboard input. Here the source is a fixed string instead.
    istringstream input(
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    );

    // Request the next 20 characters.
    input.read(buffer, 20);

    // How many characters were extracted?
    streamsize count = input.gcount();

    cout << "\nFirst read:\n";

    // Output only the characters read.
    cout.write(buffer, count);

    cout << "\nCharacters read: "
         << count << endl;

    // ====================================
    // PART 3: Reading past available data
    // ====================================

    // Only 6 characters remain. This operation requests 20 anyway.
    input.read(buffer, 20);

    count = input.gcount();

    cout << "\nSecond read:\n";

    // Print the actual number read.
    cout.write(buffer, count);

    cout << "\nCharacters read: "
         << count << endl;

    // The requested 20 bytes were not all available, so the read fails.
    cout << boolalpha;

    cout << "End of file? "
         << input.eof() << endl;

    cout << "Read failed? "
         << input.fail() << endl;

    /*
        OBSERVE:
        A read of 20 bytes does not mean that 20 bytes always exist.

        gcount() gives the actual number of characters extracted.

        IMPORTANT:
        read() does not append a '\0'. Therefore, do not assume that buffer is a C-style string.

        This is why we use:
        cout.write(buffer, count);

        Instead of:
        cout << buffer;

        TRY THIS:
        Change the first read from 20 to 10.

        Predict the size of the second read.

        Then change the input string to:
        "HELLO"

        What happens if we request 20 bytes?
    */

    return 0;
}
