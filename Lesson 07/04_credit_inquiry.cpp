//Credit Inquiry

#include <iostream>
#include <fstream>
#include <iomanip>
#include <limits>
#include <string>

using namespace std;

enum class RequestType {
    ZERO = 1,
    CREDIT,
    DEBIT,
    END
};

// obtain a valid menu choice
RequestType getRequest(){
    int choice;
    
    while (true) {
        cout << "\n1 Zero balances\n"
             << "2 Credit balances (negative)\n"
             << "3 Debit balances (Positive)\n"
             << "4 End\n"
             << "Choice: ";
             
        if(cin >> choice){
            if (choice >=1 && choice <= 4){
                return static_cast<RequestType>(choice);
            }
        } else {
            // End the program if input is closed or cannot continue
            if(cin.eof() || cin.bad()){
                return RequestType::END;
            }
            
            //clear the failure cause by nonnumeric input.
            cin.clear();
        }
        
        //Discard the rest of the invalid input line
        cin.ignore(
            numeric_limits<streamsize>::max(), '\n'
        );
        
        cout << "Please enter a number from 1 to 4." << endl;    
    }
}

// determine wheather a balance matches the requested category
bool shouldDisplay(RequestType request, double balance){
    return (request == RequestType::ZERO && balance == 0.00)
        || (request == RequestType::CREDIT && balance < 0.00)
        || (request == RequestType::DEBIT && balance > 0.00);
}

void outputLine (int account, const string& name, double balance){
    cout << left << setw(10) << account
                 << setw(15) << name
        << right << setw(12) << fixed << setprecision(2) << balance << endl;
}


int main(){
    ifstream inFile("clients.txt");
    
    if(!inFile){
        cerr << "Could not open clients.txt. Run code 1 first.\n";
        return 1;
    }
    
    RequestType request = getRequest();
    
    while (request != RequestType::END) {
        // reset flags left by the previous scans
        inFile.clear();
        
        //move the reading position to the beginning
        inFile.seekg(0, ios::beg);
        
        if(!inFile){
            cerr << "Could not return to the start of the file." << endl;
            
            return 1;
        }
        
        int account;
        string name;
        double balance;
        int matches = 0;
        
        cout << "\nMatching accounts:\n";
        
        // read first; process successful extraction.
        while (inFile >> account >> name >> balance){
            if (shouldDisplay(request, balance)){
                outputLine(account, name, balance);
                ++matches;
            }
        }
        
        if (inFile.bad() || !inFile.eof()){
            cerr << "Stopped becase of a read error or invalid record.\n";
            
            return 1;
        }
        
        cout << "Matches: " << matches << endl;
        
        request = getRequest();
    }
    
    cout << "End of run.\n";
}