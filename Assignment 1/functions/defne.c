#include "RealEstate.h"
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