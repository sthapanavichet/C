#include "RealEstate.h"
// aditi
//Calculation for monthly earnings for each property
void monthlyEarnings(struct BasicInfo* property) {
    property->monthlyEarnings = property->monthlyRent - property->condoFees - property->monthlyPropertyTax-property->monthlyUtilities;
}
//Calculation for total monthly earnings for all properties
double totalMonthlyEarnings(struct BasicInfo* properties, int num) {
    double total = 0.0;
    for (int i = 0; i < num; i++) {
        total += properties[i].monthlyEarnings;
    }
    return total;
}
//Calculation for total capital gains
double totalCapitalGains(struct BasicInfo* property, int num) {
    double total_gains = 0.0;
    for (int i = 0; i < num; i++) {
        total_gains += property[i].currentValue - property[i].purchasePrice;
    }
    return total_gains;
}

//defne
//calculation for current value of each property
void currentValue(struct BasicInfo* property) {
	property->currentValue = 12 * property->monthlyEarnings / 0.05;
}

//calculation for total value of apartments, townhouses and semi-detached houses
double totalValue(struct BasicInfo* property, int num) {
	double total = 0.0;
	for (int i = 0; i < num; i++) {
		total += property[i].currentValue;
	}
	return total;
}

//calculation for capital gain rate
void capitalGainsRate(struct BasicInfo* property) {
	property->capitalGainsRate = property->capitalGains / property->timeOwned;
}

//sarah
// function for calculating the ROI of individual properties
void ROI(struct BasicInfo *property) {
	property->ROI = (12 * 100 * property->monthlyEarnings) / property->purchasePrice;
	}
	
// function for calculating the total ROI
double totalROI(struct BasicInfo *property, int num) {
	double roiRunningTotal = 0;
	double priceRunningTotal = 0;
	for(int i = 0; i < num; i++) {
		roiRunningTotal += property->monthlyEarnings * 12 * 100; // total roi
		priceRunningTotal += property->purchasePrice; // total purchaseprice
		property++;
	}
	return roiRunningTotal / priceRunningTotal;
}

//hasan
// calculating performance index
void performanceIndex(struct BasicInfo *property) {
	property->performanceIndex = property->ROI * property->capitalGainsRate;
}

double averageMonthlyEarnings(struct BasicInfo *property, int num){
	double runningTotal = 0;
	double average;
	for(int i = 0; i < num; i++) {
		runningTotal += property[i].monthlyEarnings;
	} 
	average = runningTotal / num; // return average
	return average;	
}

// calculating capital gains
void capitalGains(struct BasicInfo *property) {
	property->capitalGains = property->currentValue - property->purchasePrice;
}

// calculating average of capital gains
double averageGainsRate(struct BasicInfo *property, int num) { // hasan
	double runningTotal = 0;// we ad up all the rates in this variable.
	double average; // we do the average and return it.
	for(int i = 0; i < num; i++) {
		runningTotal += property[i].capitalGainsRate;
	}
	average = runningTotal / num;
	return average; // return average
}

//chet
// function for printing out best real estate's performance and the top performing real estate type
void displayTopProperty(struct Company *company) {
	printf("Top performing property (investment recommendation):\n");
	struct BasicInfo *property = (company->apartment);
	int num;
	for(int i = 0; i < company->bestPerformanceIndex; i++) { //increment the pointer to the property with best performance index
		property++;
	} 
	printf("%s\n", property->address);
	printf("Type: %s\n", property->type);
	printf("ROI: %.2lf\n", property->ROI);
	printf("Capital Gains Rate: %.2lf\n", property->capitalGainsRate);
	printf("Number of Rooms: %d\n", property->roomNum);
	printf("Number of Bathrooms: %d\n", property->bathroomNum);
	printf("ROI x Capital Gains Rate: %.2lf\n\n", property->performanceIndex);
	
	// checking for real estate type and assigning the proper pointer and value
	if(strcmp(property->type, "Apartments") == 0) {
    	property = company->apartment;
		num = NUM_APART;
	}
	else if(strcmp(property->type, "Townhouses") == 0) {
		property = company->townHouse;
		num = NUM_TOWN;
	}
    else if(strcmp(property->type, "Semi-detached houses") == 0) {
		property = company->semiDetachedHouse;
		num = NUM_SEMI;
	}
	printf("Top performing property type:\n");
	printf("Type: %s\n", property->type);
	printf("ROI: %.2lf\n", totalROI(property, num)); 
	printf("Average Capital Gains Rate: %.2lf\n", averageGainsRate(property, num));
	printf("ROI x Average Capital Gains Rate: %.2lf", totalROI(property, num) * averageGainsRate(property, num));
}

// function for determining the best property's index
int topProperty(struct Company *company) {
	int topIndex = 0;
	double topPerformaceIndex = 0;
	struct BasicInfo *property = company->apartment; // start at apartment because it is declared first in the struct company
	for(int i = 0; i < company->propertiesOwned; i++) {
		if(property->performanceIndex > topPerformaceIndex) { // storing the index of the best performance index
			topPerformaceIndex = property->performanceIndex;
			topIndex = i;
		}
		property++;
	}
	return topIndex;
}

// initializing struct
void initializeInfo(struct Company *company) {
	strcpy(company->name, "Brookfield Asset Management"); // these aren't initialized to '0' or 0 because they will never change
	strcpy(company->address, "11 Yonge Street");
	company->propertiesOwned = NUM_APART + NUM_TOWN + NUM_SEMI;
	company->totalMonthlyEarnings = 0;
	company->totalROI = 0;
	company->bestPerformanceIndex = 0;
	struct BasicInfo *property = company->apartment;
	for(int i = 0; i < company->propertiesOwned; i++) {
		property->address[0] = '\0';
		property->roomNum = 0;
		property->bathroomNum = 0;
		property->monthlyRent = 0;
		property->purchasePrice = 0;
		property->condoFees = 0;
		property->monthlyPropertyTax = 0;
		property->monthlyUtilities = 0;
		property->timeOwned = 0;
		property->currentValue = 0;
		property->monthlyEarnings = 0;
		property->ROI = 0;
		property->capitalGains = 0;
		property->capitalGainsRate = 0;
		property->type[0] = '\0';
		property->performanceIndex = 0;
		property++;
	}
}

// displaying each type of real estate's performance
void displayInfo(struct BasicInfo *property, int num) {
	printf("%s:\n\n", property->type);
    printf("Total units owned: %d\n", num);
    printf("Monthly earnings: $%.2lf\n", totalMonthlyEarnings(property, num));
	printf("Avg monthly earnings (per unit): $%.2lf\n", averageMonthlyEarnings(property, num));
	printf("ROI (for all units): %.2lf%%\n", totalROI(property, num));
	printf("Total value: $%.2lf\n", totalValue(property, num));
	printf("Capital gains: $%.2lf\n", totalCapitalGains(property, num));
	printf("Average capital gains rate: %.2lf\n\n\n", averageGainsRate(property, num));
}