 #include "RealEstate.h"

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