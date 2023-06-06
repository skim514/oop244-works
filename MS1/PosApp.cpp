#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "PosApp.h"

using namespace std;

namespace sdds{
    int PosApp::menu(){
        int userInput = 0;
        bool isValid = false;
        
        cout << "The Sene-Store" << endl;
        cout << "1- List items" << endl << "2- Add item" << endl << "3- Remove item" << endl;
        cout << "4- Stock item" << endl << "5- Point of Sale" << endl << "0- exit program" << endl << "> ";
        
        do{
            isValid = true;
            
            cin >> userInput;
            if (cin.fail()) {
                cout << "Invalid Integer, try again: ";
                cin.clear();
                cin.ignore(10, '\n');
            }
            else if(userInput < 0 || userInput > 5) {
                cout << "[0<=value<=5], retry: > ";
            }
            else {
                isValid = false;
            }
        } while(isValid);
        return userInput;
    }
    void PosApp::addItem(){
        
    }
    void PosApp::removeItem(){
        
    }
    void PosApp::stockItem(){
        
    }
    void PosApp::listItems(){
        
    }
    void PosApp::POS(){
        
    }
    void PosApp::saveRecs(){
        
    }
    void PosApp::loadRecs(){
        
    }
    PosApp::PosApp(){
        
    }
    PosApp::PosApp(const char* fileName){
        
    }
    PosApp::~PosApp(){
        
    }
    void PosApp::run(){
        int input = 0;
        bool isValid = true;
        
        cout << ">>>> Loading Items";
        cout.width(60);
        cout.fill('.');
        cout << '\n';
        cout << "Loading data from datafile.csv" << endl;
        do {
            isValid = true;
            input = menu();
            if (input == 1) {
                cout << ">>>> Listing Items";
                cout.width(60);
                cout.fill('.');
                cout << '\n';
                cout << "Running listItems()" << endl;
            }
            else if(input == 2){
                cout << ">>>> Adding Item to the store";
                cout.width(49);
                cout.fill('.');
                cout << '\n';
                cout << "Running addItem()" << endl;
            }
            else if(input == 3){
                cout << ">>>> Remove Item";
                cout.width(62);
                cout.fill('.');
                cout << '\n';
                cout << "Running removeItem()" << endl;
            }
            else if(input == 4){
                cout << ">>>> Select an item to stock";
                cout.width(50);
                cout.fill('.');
                cout << '\n';
                cout << "Running stockItem()" << endl;
            }
            else if(input == 5){
                cout << ">>>> Starting Point of Sale";
                cout.width(51);
                cout.fill('.');
                cout << '\n';
                cout << "Running POS()" << endl;
            }
            else if (input == 0){
                cout << ">>>> Saving Data";
                cout.width(62);
                cout.fill('.');
                cout << '\n';
                cout << "Saving data in datafile.csv" << endl << "Goodbye!" << endl;
                isValid = false;
            }
        } while (isValid);
    }
}
