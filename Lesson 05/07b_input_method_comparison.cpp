/*
    CSCI 272 - Lesson 5
    Example 07b: One Pending Newline, Four Input Methods

    Instructor: Avijit Roy
    Teaching page: https://avijitroy.com/teaching/

    Each independent stream contains "A\nC\n". Reading the first A leaves exactly the same pending input: \nC\n. Predict each next operation. Strings supply all characters in advance, so no terminal timing is involved. This isolates C++ input behavior from keyboard delivery.
*/

#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main()
{
    // Case 1: formatted char extraction skips the pending newline.
    istringstream formatted("A\nC\n");
    char ch;
    formatted.get(ch); // consumes A
    formatted >> ch;   // skips \n, consumes C
    cout << "Formatted >> char: [" << ch << "]\n";

    // Case 2: get() consumes the pending newline itself.
    istringstream character("A\nC\n");
    character.get(ch); // consumes A
    character.get(ch); // consumes \n
    cout << "get(): " << (ch == '\n' ? "[\\n]" : "[other]") << '\n';

    // Case 3: getline() encounters the newline immediately, discards it, and successfully returns an empty line. Empty is not an error here.
    istringstream lineInput("A\nC\n");
    lineInput.get(ch); // consumes A
    string line;
    getline(lineInput, line);
    cout << "getline(): [" << line << "], length " << line.size()
         << ", fail: " << boolalpha << lineInput.fail() << '\n';
    getline(lineInput, line);
    cout << "Next getline(): [" << line << "]\n";

    // Case 4: read() counts the newline as one of its two characters.
    istringstream counted("A\nC\n");
    counted.get(ch); // consumes A
    char buffer[2];
    counted.read(buffer, 2); // consumes \n and C, leaves the final \n
    const streamsize count = counted.gcount();
    cout << "read(2): ";
    for (streamsize i = 0; i < count; ++i)
    {
        if (buffer[i] == '\n')
            cout << "[\\n]";
        else
            cout << '[' << buffer[i] << ']';
    }
    cout << ", gcount: " << count << '\n';

    return 0;
}

/*
    EXPECTED:
    Formatted >> char: [C]
    get(): [\n]
    getline(): [], length 0, fail: false
    Next getline(): [C]
    read(2): [\n][C], gcount: 2

    TRY THIS:
    1. Replace every "A\nC\n" with "A C\n". Predict how the space affects each method. In the get() output, [other] now means space.
    2. Restore the inputs. Use getline(lineInput >> ws, line) for the FIRST getline(). It skips the newline and reads C instead. Explain why this also prevents preserving leading spaces or an intentional empty first line. Predict the SECOND getline() at EOF.
    3. Change only counted's input to "A\n". The two-character read gets just one character, sets eofbit and failbit, and gcount() is 1.
*/
