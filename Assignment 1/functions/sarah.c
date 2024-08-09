#include "RealEstate.h"
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