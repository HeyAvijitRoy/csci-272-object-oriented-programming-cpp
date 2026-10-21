/*
    CSCI 272
    Instructor: Avijit Roy
    Teaching page: https://avijitroy.com/teaching/
    Lesson 4 — Encapsulation

    Example 8: Bank Account

    This example demonstrates WHY we use private data and public member functions.

    The object's internal state cannot be modified arbitrarily from outside the class.
*/

#include <iostream>
#include <string>
using namespace std;

class BankAccount
{
private:

    string owner;
    double balance;

public:

    // Constructor
    BankAccount(string accountOwner, double startingBalance)
    {
        owner = accountOwner;

        // Do not allow an invalid starting balance.
        if (startingBalance >= 0)
        {
            balance = startingBalance;
        }
        else
        {
            balance = 0;
        }
    }


    void deposit(double amount)
    {
        // Validate before changing the object's state.
        if (amount > 0)
        {
            balance = balance + amount;

            cout << "Deposited: $"
                 << amount << endl;
        }
        else
        {
            cout << "Invalid deposit amount." << endl;
        }
    }


    void withdraw(double amount)
    {
        // Two conditions must be satisfied.
        if (amount > 0 && amount <= balance)
        {
            balance = balance - amount;

            cout << "Withdrawn: $"
                 << amount << endl;
        }
        else
        {
            cout << "Withdrawal denied." << endl;
        }
    }


    void displayAccount() const
    {
        cout << endl;
        cout << "Account Owner: " << owner << endl;
        cout << "Current Balance: $" << balance << endl;
    }
};


int main()
{
    BankAccount account1("Avijit", 1000);

    account1.displayAccount();

    account1.deposit(500);

    account1.withdraw(300);

    account1.displayAccount();


    // Try these:
    //
    // account1.deposit(-500);
    //
    // account1.withdraw(100000);
    //
    // account1.balance = 1000000;
    //
    // The last statement will not compile because balance is PRIVATE.


    return 0;
}

/*
    PREDICT: What is the balance after depositing 500 and withdrawing 300 from 1000?
    EXPECTED: The first balance is $1000 and the final balance is $1200.

    TRY THIS:
    1. Try deposit(-500) and withdraw(100000). Display the balance after each rejected operation; it should stay unchanged.
    2. Create another account with a negative starting balance. Its constructor substitutes 0.
    3. Explain why direct assignment to account1.balance fails to compile.

    This is a simplified model for practicing encapsulation. The double representation and default output format are for this example; monetary rounding and production banking rules are outside its scope.
*/
