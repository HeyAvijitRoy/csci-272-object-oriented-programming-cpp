/*
    CSCI 272
    Lesson 2 — Vector Practice: Student Scores

    Instructor: Avijit Roy
    Teaching page: https://avijitroy.com/teaching/

    This example combines several concepts
    from Lesson 2 into one small program.

    This example demonstrates:
    - vector
    - push_back()
    - size()
    - Range-based loops
    - Passing a vector by const reference
    - Functions
    - sort()
    - front()
    - back()
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


// Print all student scores.
//
// const prevents modification.
//
// & avoids making a copy of the entire vector.
void printScores(const vector<int>& scores)
{
    if (scores.empty())
    {
        cout << "(none)";
    }

    for (int score : scores)
    {
        cout << score << " ";
    }

    cout << endl;
}


// Calculate the average score.
// Call this only when scores is not empty:
// an empty group has no average, and dividing
// by scores.size() would divide by zero.
double calculateAverage(const vector<int>& scores)
{
    int total = 0;


    // Add every score to total.
    for (int score : scores)
    {
        total = total + score;
    }


    // Convert total to double so that
    // decimal division can occur.
    return static_cast<double>(total)
           / scores.size();
}


int main()
{
    // Start with an empty vector.
    vector<int> scores;


    // Add student scores.
    scores.push_back(82);
    scores.push_back(91);
    scores.push_back(74);
    scores.push_back(96);
    scores.push_back(88);


    cout << "Student scores:" << endl;

    printScores(scores);


    // size() tells us how many scores exist.
    cout << "\nNumber of students: "
         << scores.size()
         << endl;

    // With no scores, there is no average, minimum,
    // or maximum to report. This check also keeps
    // front() and back() away from an empty vector.
    if (scores.empty())
    {
        cout << "No scores to summarize." << endl;
        return 0;
    }


    // Calculate the average.
    cout << "Average score: "
         << calculateAverage(scores)
         << endl;


    // --------------------------------------------------
    // Sort scores from smallest to largest.
    // --------------------------------------------------

    sort(
        scores.begin(),
        scores.end()
    );


    cout << "\nSorted scores:" << endl;

    printScores(scores);


    // Once sorted:
    //
    // front() is the smallest value.
    //
    // back() is the largest value.
    cout << "\nLowest score: "
         << scores.front()
         << endl;


    cout << "Highest score: "
         << scores.back()
         << endl;


    return 0;
}


/*
    TRY THIS #1

    Add another student score:

        scores.push_back(100);

    How does the average change?



    TRY THIS #2

    Add:

        scores.push_back(50);

    Predict whether the average
    increases or decreases.



    TRY THIS #3

    After sorting, reverse the vector:

        reverse(
            scores.begin(),
            scores.end()
        );

    What order are the scores now in?



    TRY THIS #4

    Change printScores() from:

        const vector<int>& scores

    to:

        vector<int> scores

    Will the program still work?

    Yes.

    But now the entire vector is copied
    when the function is called.

    Passing by const reference avoids
    that unnecessary copy.



    TRY THIS #5

    Temporarily comment out all five push_back()
    calls and run the program. It should print an
    empty list and "No scores to summarize."
    Explain why calculateAverage(), front(), and
    back() are skipped. Restore the scores afterward.



    CHALLENGE

    Write a function:

        int countPassing(
            const vector<int>& scores
        )

    that counts how many students
    have a score of 60 or higher.

    Example:

        82 91 74 96 88

    should return:

        5
*/
