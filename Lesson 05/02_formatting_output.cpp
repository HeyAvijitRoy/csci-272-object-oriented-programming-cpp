/*
    CSCI 272 — Lesson 5
    Example 02: Formatted Output

    Instructor: Avijit Roy
    Teaching page: https://avijitroy.com/teaching/

    Topics:
    - setw()
    - setprecision()
    - fixed
    - setfill()
    - left and right
    - hexadecimal output

    Real-world example:
    Displaying a formatted student record.
*/

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
    string name = "Alice Johnson";
    int age = 25;
    double gpa = 3.87654321;
    double pi = 3.14159265359;

    // ====================================
    // PART 1: Floating-point precision
    // ====================================

    cout << "=== Precision Example ===\n";

    // Without fixed, precision means approximately 2 significant digits.
    cout << "Pi (precision 2): "
         << setprecision(2) << pi << endl;

    // fixed makes precision represent the number of decimal places.
    cout << "Pi (fixed, 2 decimals): "
         << fixed << setprecision(2)
         << pi << endl;

    // Restore general floating-point format.
    cout << defaultfloat << setprecision(6);

    // ====================================
    // PART 2: Column width and alignment
    // ====================================

    cout << "\n=== Student Record ===\n";

    // setfill('-') uses dashes for padding. setw(35) reserves at least 35 positions.
    cout << setfill('-') << setw(35)
         << "" << endl;

    // Restore normal space padding.
    cout << setfill(' ');

    // Print table column headings.
    cout << left << setw(17) << "Name"
         << right << setw(6) << "Age"
         << setw(12) << "GPA"
         << endl;

    // Print the data in the same columns.
    cout << left << setw(17) << name
         << right << setw(6) << age
         << fixed << setprecision(2)
         << setw(12) << gpa
         << endl;

    // Print another separator line.
    cout << setfill('-') << setw(35)
         << "" << endl;

    // ====================================
    // PART 3: Number representation
    // ====================================

    int number = 255;

    cout << setfill(' ');

    // dec: decimal representation.
    cout << dec << "\nDecimal: "
         << number << endl;

    // hex: hexadecimal representation.
    cout << hex << "Hexadecimal: "
         << number << endl;

    // oct: octal representation.
    cout << oct << "Octal: "
         << number << endl;

    // Restore decimal for future output.
    cout << dec;

    /*
        OBSERVE:
        The actual integer is always 255. Only its displayed representation changes.

        PREDICT:
        Will setprecision(2) permanently change the GPA stored in memory?

        Answer: No. It only affects output.

        TRY THIS:
        1. Change GPA to 3.999.
        2. Change setw(17) to setw(10).
        3. Change the name to "Christopher".
        4. Remove fixed. Compare precision.

        Important:
        setw() provides MINIMUM width. It does not truncate a longer value.
    */

    return 0;
}
