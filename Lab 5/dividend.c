// Name: Sthapanavichet Long 
// Student ID: 1375802215
// email: slong17@myseneca.ca

#include <stdio.h>
#include <string.h>
#include "dividend.h"
int main() {
    struct CompanyInfo company[MAX_COMP];
    initializeInfo(company);
    for(int i = 0; i < MAX_COMP; i++) { // looping through struct CompanyInfo for input and calculating div yield and value
        userInput(company+i);
        calculateDivYield(company+i);
        companyValue(company+i);
    }
    // Output
    output(company);
    return 0;
}

void initializeInfo(struct CompanyInfo * company) { // initializing struct so it doesn't hold garbage value
    for(int i = 0; i < MAX_COMP; i++) {
        company->name[0] = '\0';
        company->symbol[0] = '\0';
        company->stockPrice = 0;
        company->div = 0;
        company->divYield = 0;
        company->valuation[0] = '\0';
        ++company;
    }
}

void userInput(struct CompanyInfo * company) { // taking user's input
    printf("Enter the Company Name: ");
    scanf("%[^\n]s", company->name, MAX_STR);
    clearInputBuffer();
    printf("Enter %s's stock symbol: ", company->name);
    scanf("%[^\n]s", company->symbol, MAX_STR);
    clearInputBuffer();
    printf("Enter %s's current stock price: ", company->name);
    scanf("%f", &company->stockPrice);
    clearInputBuffer();
    printf("Enter %s's annual dividend per share: ", company->name);
    scanf("%lf", &company->div);
    clearInputBuffer();
}

void calculateDivYield(struct CompanyInfo * company) { // Calculating dividend yield
    if(company->stockPrice >= company->div && company->div > 0 && company->stockPrice > 0) { // wont execute unless inputs are valid
        company->divYield = company->div / company->stockPrice * 100;
    }
}

void companyValue(struct CompanyInfo * company) { // Evaluating company's value into 3 categories
    if(company->divYield > 0) {
        if(company->divYield == 5) {
            strcpy(company->valuation, "fully Valued");
        }
        else if(company->divYield > 5) {
            strcpy(company->valuation, "Under Valued");
        }
        else if(company->divYield < 5) {
            strcpy(company->valuation, "Over Valued");
        }
    }
    else { // divyield < 0 invalid
        strcpy(company->valuation, "ERROR");
    }
}

void output(struct CompanyInfo * company) { // printing out companyinfo into the console
    printf("%25s  %8s   %-8s   %-8s   %8s   %-15s\n", "COMPANY", "SYMBOL", "PRICE", "DIVIDEND", "YIELD", "VALUATION");
    for(int i = 0; i < MAX_COMP; i++) {
        printf("%25s  %8s   $%-8.2f  $%-8.3f %8.3lf%%   %-15s\n", company->name, company->symbol, company->stockPrice, company->div, company->divYield, company->valuation);
        ++company;
    }
}

void clearInputBuffer() { //getting the \n character from the buffer
    char c;
	do {
		c = getchar();
	} while (c != '\n');
}