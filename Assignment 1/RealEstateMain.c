#include "RealEstate.h"

int main(int argc, char *argv[]) {

    struct Company company;
	initializeInfo(&company);
	FILE* fp = NULL;

	// need to add something about argc (check if its 4 or not) and argv to fopen
	if(argc != 4) {
		printf("Invalid argument");
		return -1; // error code if 4 files aren't being opened
	}

	//Retrieve data for apartments
	fp = fopen(argv[1], "r");
	if(fp != NULL) { // checking for a valid file pointer
		for (int i = 0; i < NUM_APART; ++i) {
			fscanf(fp, "%[^\n]s", &company.apartment[i].address);
			fscanf(fp, "%d", &company.apartment[i].roomNum);
			fscanf(fp, "%d", &company.apartment[i].bathroomNum);
			fscanf(fp, "%lf", &company.apartment[i].purchasePrice);
			fscanf(fp, "%lf", &company.apartment[i].monthlyRent);
			fscanf(fp, "%lf", &company.apartment[i].condoFees);
			fscanf(fp, "%lf", &company.apartment[i].timeOwned);
			strcpy(company.apartment[i].type, "Apartments");
			while (fgetc(fp) != '\n' && feof(fp) == 0); // clear input stream
		}
	}
	else {
		printf("Error! File could not be opened");
		return -2; // error code if file pointer is invalid for first file
	}
	fclose(fp);
	
	//Retrieve data for townhouses
	fp = fopen(argv[2], "r");
	if(fp != NULL) {
		for (int i = 0; i < NUM_TOWN; ++i) { // checking for a valid file pointer
			fscanf(fp, "%[^\n]s", &company.townHouse[i].address);
			fscanf(fp, "%d", &company.townHouse[i].roomNum);
			fscanf(fp, "%d", &company.townHouse[i].bathroomNum);
			fscanf(fp, "%lf", &company.townHouse[i].purchasePrice);
			fscanf(fp, "%lf", &company.townHouse[i].monthlyRent);
			fscanf(fp, "%lf", &company.townHouse[i].monthlyUtilities);
			fscanf(fp, "%lf", &company.townHouse[i].condoFees);
			fscanf(fp, "%lf", &company.townHouse[i].monthlyPropertyTax);
			fscanf(fp, "%lf", &company.townHouse[i].timeOwned);
			strcpy(company.townHouse[i].type, "Townhouses");
			while (fgetc(fp) != '\n' && feof(fp) == 0); // clear input stream
		}
	}
	else {
		printf("Error! File could not be opened");
		return -3; // error code if file pointer is invalid for second file
	}
	fclose(fp);

	//Retrieve data for semi-detached houses
	fp = fopen(argv[3], "r");
	if(fp != NULL) { // checking for a valid file pointer
		for (int i = 0; i < NUM_SEMI; ++i) {
			fscanf(fp, "%[^\n]s", &company.semiDetachedHouse[i].address);
			fscanf(fp, "%d", &company.semiDetachedHouse[i].roomNum);
			fscanf(fp, "%d", &company.semiDetachedHouse[i].bathroomNum);
			fscanf(fp, "%lf", &company.semiDetachedHouse[i].purchasePrice);
			fscanf(fp, "%lf", &company.semiDetachedHouse[i].monthlyRent);
			fscanf(fp, "%lf", &company.semiDetachedHouse[i].monthlyUtilities);
			fscanf(fp, "%lf", &company.semiDetachedHouse[i].monthlyPropertyTax);
			fscanf(fp, "%lf", &company.semiDetachedHouse[i].timeOwned);
			strcpy(company.semiDetachedHouse[i].type, "Semi-detached houses");
			while (fgetc(fp) != '\n' && feof(fp) == 0); // clear input stream
		}
	}
	else {
		printf("Error! File could not be opened");
		return -4; // error code if file pointer is invalid for 3rd file
	}
	fclose(fp);

	// calculation for each apartment's performance
    struct BasicInfo *ptr;
	ptr = company.apartment;
	for(int i = 0; i < NUM_APART; i++) {
		monthlyEarnings(ptr);
		ROI(ptr);
		currentValue(ptr);
		capitalGains(ptr);
		capitalGainsRate(ptr);
		performanceIndex(ptr);
		ptr++; // incrementing pointer to next element
	}

	// calculation for each townhouse's performance
	ptr = company.townHouse;
	for(int i = 0; i < NUM_TOWN; i++) {
		monthlyEarnings(ptr);
		ROI(ptr);
		currentValue(ptr);
		capitalGains(ptr);
		capitalGainsRate(ptr);
		performanceIndex(ptr);
		ptr++; // incrementing pointer to next element
	}

	// calculation for each semi-detached house's performance
	ptr = company.semiDetachedHouse;
	for(int i = 0; i < NUM_SEMI; i++) {
		monthlyEarnings(ptr);
		ROI(ptr);
		currentValue(ptr);
		capitalGains(ptr);
		capitalGainsRate(ptr);
		performanceIndex(ptr);
		ptr++; // incrementing pointer to next element
	}

	// calculation for company's total performance
	company.totalMonthlyEarnings = totalMonthlyEarnings(company.apartment, NUM_APART) + totalMonthlyEarnings(company.townHouse, NUM_TOWN) + totalMonthlyEarnings(company.semiDetachedHouse, NUM_SEMI);
	company.totalROI = totalROI(company.apartment, NUM_APART) + totalROI(company.townHouse, NUM_TOWN) + totalROI(company.semiDetachedHouse, NUM_SEMI);
	company.bestPerformanceIndex = topProperty(&company);

	//output
	printf("The following are financial stats for %s, %s.\n\n", company.name, company.address);
	printf("Total Properties Owned: %d\n\n", company.propertiesOwned);
	printf("Total Monthly Earnings: $%.2lf\n\n", company.totalMonthlyEarnings);
	printf("Total ROI (for all units): %.2lf%%\n\n\n", company.totalROI);
	displayInfo(company.apartment, NUM_APART);
	displayInfo(company.townHouse, NUM_TOWN);
	displayInfo(company.semiDetachedHouse, NUM_SEMI);
	displayTopProperty(&company);

	return 0;
}