#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <string>

using namespace std;

int main(){
    // create a csv file, replacing any previous content
    ofstream outFile("clients.csv");
    
    if (!outFile){
        cerr << "couldn't create the file" << endl;
        return 1;
    }
    
    outFile << "account,name,balance\n"
            << "100,Ana Lopez,125.50\n"
            << "200,Ben Chen,-40.00\n"
            << "300,Avijit Roy,-999.99\n";
            
    outFile.close();
    
    if(!outFile){
        cerr << "Couldn't finish saving/writing.\n";
        return 1;
    }
    
    ifstream inFile("clients.csv");
    if(!inFile){
        cerr << "couldn't open the file" << endl;
        return 1;
    }
    
    string line;
    //skip the header file
    getline(inFile, line);
    
    while(getline(inFile, line)){
        istringstream row(line);
        
        int account;
        char comma;
        string name;
        double balance;
        
        if(!(row >> account >> comma) || comma != ','
          || !getline(row, name, ',') || !(row >> balance)
        ){
            cerr << "Invalid csv row: " << line << endl;
            return 1;
        }
        
        //skips trailing whitespaces
        row >> ws;
        
        if (!row.eof()){
            cerr << "Extra content in CSV row." << endl;
            return 1;
        }
        
        cout << account << " | " << name << " | " << fixed << setprecision(2) << balance << endl;
    }
    
    if (inFile.bad() || !inFile.eof()){
        cerr << "couldn't finish reading.\n";
        return 1;
    }
}