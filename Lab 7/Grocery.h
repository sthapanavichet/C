#include <iostream>
#include <string.h>
#include <string>
#include <iomanip>
#define MAX_GROCERY 5
#define MAX_STR 32

class Grocery{
    private:
        std::string name;
        std::string barcode;
        double cost;
        bool taxable;
        double tax;
        const float HST = 0.13; // 13%
    public:
        // i didn't create a constructor function as we wouldn't need it because we are working with arrays of this class
        // functions for retrieving info from class's members
        std::string getName() const {
            return name;
        }
        std::string getBarcode() const {
            return barcode;
        }
        double getCost() const {
            return cost;
        }
        double getTax() const {
            return tax;
        }

        // functions for inputting info to class's members
        Grocery() {
            name = '\0';
            barcode = '\0';
            cost = 0;
            taxable = false;
            tax = 0;
        }
        bool setName() {
            std::string _name;
            bool ret = false;
            do {
                std::cin.clear();
                fflush(stdin); // clearing input buffer
                std::cout << "Enter the name of the grocery item: ";
                getline(std::cin, _name);
                if(_name.size() > 0) { // if length of name is greater than 0
                    name = _name;
                    ret = true;
                }
                else {
                    std::cout << "Invalid Name" << std::endl; // if length of nasme is smaller than or equal to 0;
                }
            } while(ret != true);
            return ret;
        }
        
        bool setBarcode() {
            std::string _barcode;
            bool ret = false;
            do {
                std::cin.clear();
                fflush(stdin); // clearing input buffer
                std::cout << "Enter the barcode of the grocery item (up to 7 digits): ";
                std::cin >> _barcode;
                if(_barcode.size() <= 7 && stoi(_barcode) > 0) { // checking for max 7 digits and valid number (stoi can't convert a word, it will throw an error) 
                    barcode = _barcode;
                    ret = true;
                    return ret;
                }
                else { // if more than 7 digits or negative numbers
                    std::cout << "Invalid Barcode" << std::endl;
                    printf("%d", _barcode.size());
                }
            } while(ret != true);
            return ret;
        } // function doesn't invalidate decimals

        bool setCost() {
            double _cost;
            bool ret = false;
            do {
                std::cin.clear();
                fflush(stdin); // clearing input buffer
                std::cout << "Enter the cost of the grocery item: ";
                std::cin >> _cost;
                if(_cost > 0) { // checking for negative cost
                    cost = _cost;
                    ret = true;
                    return ret;
                }
                else { // if cost is negative
                    std::cout << "Invalid Cost" << std::endl;
                }
            } while(ret != true);
            return ret;
        }
        
        bool setTax() {
            char _taxable;
            bool ret = false;
            do {
                std::cin.clear();
                fflush(stdin); // clearing input buffer incase 2 or more char was entered
                std::cout << "Is the grocery item taxable? [Y/N] ";
                std::cin >> _taxable;
                if(_taxable == 'Y' || _taxable  == 'y') { // checking for correct answers
                    taxable = true;
                    ret = true;
                }
                else if(_taxable == 'N' || _taxable == 'n') {
                    taxable = false;
                    ret = true;
                }
                else {
                    std::cout << "Invalid Answer" << std::endl; // if answer doesn't match Y or N
                }
            } while(ret != true);
            
            // calculation of tax based on the answer that is given
            if(taxable) {
                tax = cost * HST;
            }
            else {
                tax = 0;
            }
            return ret;
        }
};
