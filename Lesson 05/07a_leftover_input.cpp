/*
    CSCI 272 - Lesson 5
    Example 07a: Leftover Letters and Newlines

    Instructor: Avijit Roy
    Teaching page: https://avijitroy.com/teaching/

    PREDICT FIRST:
    Each round requests TWO characters, including spaces and newlines. Enter Alice followed by Enter at the first prompt. Predict all three rounds before running: [A][l], [i][c], [e][\n]. Later prompts can finish using characters already waiting for input.

    These are three reads in ONE process, not three launches of the program. A fresh launch does not inherit this program's previous cin buffer.
*/

#include <iostream>
#include <limits>
#include <string>
using namespace std;

// Print whitespace visibly instead of letting a newline move the cursor.
void showCharacter(char ch)
{
    if (ch == '\n')
        cout << "[\\n]";
    else if (ch == ' ')
        cout << "[space]";
    else if (ch == '\t')
        cout << "[\\t]";
    else
        cout << '[' << ch << ']';
}

int main()
{
    // TRY THIS: change to true, rebuild, and repeat the same inputs.
    const bool discardRemainingLine = false;
    const streamsize requested = 2;
    char buffer[requested];

    cout << "Three reads of two characters each. Enter counts as \\n.\n";
    cout << "Discard rest of line: " << boolalpha
         << discardRemainingLine << '\n';

    for (int round = 1; round <= 3; ++round)
    {
        cout << "\nRound " << round << ": enter text, then press Enter: ";
        cin.read(buffer, requested);

        // Save gcount BEFORE another unformatted operation such as ignore().
        const streamsize count = cin.gcount();
        cout << "\nRead " << count << " character(s): ";
        for (streamsize i = 0; i < count; ++i)
            showCharacter(buffer[i]);
        cout << '\n';

        if (!cin)
        {
            cerr << "Input ended or failed before two characters arrived.\n";
            return 1;
        }

        // read() may ALREADY have consumed the newline (for example A\n). Ignoring again then would wait for and discard the NEXT line.
        if (discardRemainingLine && buffer[count - 1] != '\n')
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (!cin)
            {
                cerr << "Input ended or failed while discarding the line.\n";
                return 1;
            }
        }
    }

    // Compare with the proposed string test: >> skips leading whitespace, including pending newlines, and extracts one word. It may immediately take a leftover word, but a leftover newline alone is NOT a word.
    string test;
    cout << "\nWord test: enter a word if no word is already waiting: ";
    if (!(cin >> test))
    {
        cerr << "Unable to read a word.\n";
        return 1;
    }
    cout << "Test: " << test << '\n';

    char next;
    cout << "Next character after the word: ";
    if (cin.get(next))
    {
        showCharacter(next);
        cout << '\n';
    }
    else
    {
        cerr << "No next character available.\n";
        return 1;
    }

    return 0;
}

/*
    TRY THIS (restart the program for each experiment):

    1. Keep discardRemainingLine = false. Enter Alice, then Enter. The three reads consume Al, ic, and e\n without more typing. At the word test enter Bob, then Enter: Test: Bob; next: [\n].

    2. Keep false. Enter AB, then Enter. Round 1 reads [A][B]. Round 2 already has [\n] but still needs one more character. Enter C, then Enter: round 2 reads [\n][C]. Enter D, then Enter: round 3 reads [\n][D]. The final pending newline is skipped by the word test; enter Bob.

    3. Keep false. Enter Alice Johnson, then Enter. Rounds read [A][l], [i][c], [e][space]. The word test immediately consumes Johnson; get() consumes [\n].

    4. Set true. Enter Alice, Carol, and David on separate lines. Rounds read Al, Ca, Da; ignore() discards each remaining line. Then enter Bob for the word test. Also try A + Enter each round: read() itself consumes [A][\n].

    In a typical line-based terminal, typing C alone is not delivered until Enter is pressed, even if an earlier newline is still pending. That newline counts as input; it does not submit newly typed characters. IDEs and online consoles may deliver input differently. Record what your environment does. clear() resets error flags; it does not discard waiting characters. None of these successful reads needs clear().
*/
