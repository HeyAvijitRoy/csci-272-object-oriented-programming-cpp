/*
    CSCI 272 — Lesson 5
    Instructor: Avijit Roy
    Teaching page: https://avijitroy.com/teaching/

    Example 03: typedef and Card Pointer

    Connection to previous lessons:
    - Classes and objects
    - Pointers and memory addresses
    - The dot (.) and arrow (->) operators
*/

#include <iostream>
#include <string>
using namespace std;

// A simple class representing a card.
class Card
{
public:
    int cardNumber;
    string cardHolder;
};

// CardPtr is another name for Card*. It represents a pointer to a Card object.
typedef Card* CardPtr;

int main()
{
    // Create a normal Card object.
    Card myCard;

    // Assign values using the dot operator.
    myCard.cardNumber = 12345;
    myCard.cardHolder = "Alice";

    // &myCard gives the object's address.
    CardPtr ptrToCard = &myCard;

    // Access directly through the object.
    cout << "Using the object:\n";
    cout << myCard.cardNumber << endl;
    cout << myCard.cardHolder << endl;

    // Access through the pointer. -> is used for members through a pointer.
    cout << "\nUsing the pointer:\n";
    cout << ptrToCard->cardNumber << endl;
    cout << ptrToCard->cardHolder << endl;

    // Both methods refer to the same Card object.

    /*
        OBSERVE:
        CardPtr does not create a new Card. It only represents a pointer type.

        The pointer stores the address of myCard.

        PREDICT:
        What happens if we change the card number through the pointer?

        TRY THIS:
        Add this before return:

        ptrToCard->cardNumber = 99999;
        cout << myCard.cardNumber << endl;

        Expected: 99999.

        WHY? The pointer and the object refer to the same underlying memory.
    */

    return 0;
}
