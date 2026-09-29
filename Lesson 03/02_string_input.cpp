/*
   CSCI 272
   Lesson 3 — String Input

   Instructor: Avijit Roy
   Teaching page: https://avijitroy.com/teaching/

   Strings can receive input from the keyboard.

   Two common ways are:

       cin >> variable;

   and:

       getline(cin, variable);

   Important difference:

   cin >> stops when it reaches whitespace.

   getline() reads the entire line, including spaces.

   This example demonstrates:
   - Reading strings with cin
   - Reading an entire line with getline()
   - Why cin and getline() can behave differently
   - Using cin >> ws before getline()
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string firstName;
    string lastName;

    cout << "Enter your first name: ";
    cin >> firstName;

    cout << "Enter your last name: ";
    cin >> lastName;

    cout << endl;

    cout << "First Name: " << firstName << endl;
    cout << "Last Name: " << lastName << endl;

    string quote;

    cout << endl;
    cout << "Enter your favorite quote: ";

    /*
       cin >> firstName and cin >> lastName leave
       the Enter/newline character in the input stream.

       cin >> ws removes all leading whitespace,
       including that leftover newline. It also removes
       leading spaces typed for the quote.

       getline() can then read the complete sentence.
    */
    getline(cin >> ws, quote);

    cout << "Your quote: " << quote << endl;

    return 0;
}

/*
   TRY THIS #1

   When asked for your first name, enter:

       Avijit Roy

   What happens?

   Notice that:

       cin >> firstName;

   only reads "Avijit".

   cin stops at whitespace.

   "Roy" is still waiting in the input stream. The
   last-name input consumes it before you type again.
   Use separate first- and last-name input for the
   other experiments.


   TRY THIS #2

   Enter this quote:

       Never stop learning new things.

   getline() should store the entire sentence.


   TRY THIS #3

   Change:

       getline(cin >> ws, quote);

   to:

       getline(cin, quote);

   Run the program.

   Does the program allow you to type the quote?

   Why not?

   The newline left behind by the previous cin
   is immediately read by getline().


   TRY THIS #4

   Create another variable:

       string city;

   Then ask:

       Enter the city where you live:

   Use getline() so a value such as:

       New York City

   can be stored completely.

   If you add this after the quote input, use
   getline(cin, city): getline() already consumed
   the quote's newline.
*/
