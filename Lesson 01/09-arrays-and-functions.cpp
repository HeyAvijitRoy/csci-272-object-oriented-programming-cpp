/*
    CSCI 272
    Lesson 1 — Arrays and Functions

    Instructor: Avijit Roy
    Teaching page: https://avijitroy.com/teaching/

    Arrays can be passed to functions.

    We also pass the size so the function knows
    how many elements it should process.
*/

#include <iostream>
using namespace std;

void printArray(const int numbers[], int size)
{
    // const means this function may read the elements
    // but may not change them through numbers.
    for (int i = 0; i < size; i++)
    {
        cout << numbers[i] << " ";
    }

    cout << endl;
}

int findMaximum(const int numbers[], int size)
{
    // This example always passes a nonempty array, so
    // using the first element as the starting maximum is safe.
    int maximum = numbers[0];

    for (int i = 1; i < size; i++)
    {
        if (numbers[i] > maximum)
        {
            maximum = numbers[i];
        }
    }

    return maximum;
}

int findMinimum(const int numbers[], int size)
{
    // Start with an actual array value instead of guessing
    // a value that might be too large or too small.
    int minimum = numbers[0];

    for (int i = 1; i < size; i++)
    {
        if (numbers[i] < minimum)
        {
            minimum = numbers[i];
        }
    }

    return minimum;
}

int main()
{
    int numbers[] = {19, 10, 8, 27, 9, 15};
    int size = 6;

    cout << "Array: ";
    printArray(numbers, size);

    cout << "Maximum: "
         << findMaximum(numbers, size)
         << endl;

    cout << "Minimum: "
         << findMinimum(numbers, size)
         << endl;

    return 0;
}

/*
    TRY THIS #1

    Change the numbers in the array.

    Predict the minimum and maximum before running.


    TRY THIS #2

    Change:

        int size = 6;

    to:

        int size = 4;

    What happens?

    Why are only four values processed?


    TRY THIS #3

    Write:

        int calculateSum(const int numbers[], int size)

    Then calculate the sum of all elements.


    CHALLENGE

    Write:

        double calculateAverage(
            const int numbers[],
            int size
        );
*/
