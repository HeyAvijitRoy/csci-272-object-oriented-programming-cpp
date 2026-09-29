/*
   CSCI 272
   Lesson 3 — Converting Strings to Numbers

   Instructor: Avijit Roy
   Teaching page: https://avijitroy.com/teaching/

   Sometimes numeric data is stored as text.

   Example:

       string age = "25";

   "25" looks like a number, but it is
   currently stored as a string.

   C++ provides conversion functions such as:

       stoi()   -> string to int
       stol()   -> string to long
       stof()   -> string to float
       stod()   -> string to double
       stold()  -> string to long double

   This example demonstrates:
   - stoi()
   - stod()
   - Difference between string concatenation
     and numeric addition
   - How much of a string a conversion consumed
   - Converting a number back to text
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string ageText = "25";

    // Convert the string "25" into integer 25.
    int age = stoi(ageText);

    cout << "Age stored as string: "
         << ageText
         << endl;

    cout << "Age stored as integer: "
         << age
         << endl;

    // Now arithmetic can be performed.
    cout << "Age next year: "
         << age + 1
         << endl;

    cout << endl;

    string gpaText = "3.75";

    // Convert string to double.
    double gpa = stod(gpaText);

    cout << "GPA: "
         << gpa
         << endl;

    cout << "GPA + 0.10: "
         << gpa + 0.10
         << endl;

    cout << endl;

    /*
       Observe the difference between
       strings and numbers.
    */

    string first = "10";
    string second = "20";

    // + concatenates strings.
    cout << "String result: "
         << first + second
         << endl;

    // Convert both strings first.
    cout << "Numeric result: "
         << stoi(first) + stoi(second)
         << endl;

    // stoi() can convert a numeric prefix even if text follows.
    // consumed receives the index after the converted part.
    string mixedText = "12cats";
    string::size_type consumed = 0;
    int quantity = stoi(mixedText, &consumed);

    cout << "Converted prefix: " << quantity << endl;
    cout << "Characters consumed: " << consumed << endl;
    cout << "Whole string numeric? "
         << (consumed == mixedText.size() ? "yes" : "no")
         << endl;

    // to_string() travels in the other direction.
    cout << "Label: " << string("Age: ") + to_string(age)
         << endl;

    return 0;
}

/*
   TRY THIS #1

   Change:

       ageText = "25"

   to:

       ageText = "40"

   What is age + 1?


   TRY THIS #2

   Change:

       first = "10"
       second = "20"

   to:

       first = "100"
       second = "50"

   Compare:

       first + second

   with:

       stoi(first) + stoi(second)


   TRY THIS #3

   Try:

       string priceText = "19.99";

   Convert it using:

       stod(priceText)


   TRY THIS #4

   Reason about this invalid conversion:

       stoi("hello")

   DO NOT RUN it as an unhandled call. It throws
   std::invalid_argument. A value outside int's range
   throws std::out_of_range. Exception handling comes
   later in the course.


   TRY THIS #5

   Change mixedText to "12". Why does the answer to
   "Whole string numeric?" change?
*/
