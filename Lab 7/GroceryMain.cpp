// Name: Sthapanavichet Long 
// Student ID: 1375802215
// email: slong17@myseneca.ca
#include "Grocery.h"

int main() {
    Grocery groceries[MAX_GROCERY];
    int numGrocery;
    double subTotal = 0, taxes = 0, total = 0;
    bool flag = false;
    do {
        std::cout << "Enter the number of grocery items (5 max): "; 
        std::cin >> numGrocery; // number of groceries that user want to input
        if(numGrocery < 6 && numGrocery > 0) { // validating input
            flag = true;
        }
        else {
            std::cout << "Invalid number of groceries" << std::endl; // if input is not valid
        }
    } while(flag == false);

    for(int i = 0; i < numGrocery; i++) { // input
        groceries[i].setName();
        groceries[i].setBarcode();
        groceries[i].setCost();
        groceries[i].setTax();
        std::cout << std::endl; // newline after taking one set of input
        }

    for(int i = 0; i < numGrocery; i++) { // calculation of subtotal and taxes
        subTotal += groceries[i].getCost();
        taxes += groceries[i].getTax();
    }

    for(int i = 0; i < numGrocery; i++) { //output
        std::cout.setf(std::ios::left); // justifying to the left
        std::cout << "Name: " << std::setw(20) << groceries[i].getName(); // set 20 width for name
        std::cout << " Cost: $" << groceries[i].getCost();
        std::cout << " Tax: $" << groceries[i].getTax() << std::endl;
    }
    std::cout << std::setw(25) << std::setfill('-') << '-' << std::endl; // make a line of 26 '-' characters
    std::cout << "Subtotal: $" << subTotal << std::endl << "Taxes: $" << taxes << std::endl << "Total: $" << subTotal + taxes << std::endl;

    return 0;
}