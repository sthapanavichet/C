#include "RealEstate.h"
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