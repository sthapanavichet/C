#define MAX_STR 64
#define NUM_APART 2
#define NUM_TOWN 5
#define NUM_SEMI 6
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct BasicInfo {
    char address[MAX_STR];
    int roomNum; //rooms
    int bathroomNum; //rooms
    double monthlyRent; //dollars $
    double purchasePrice; //dollars $
    double condoFees; //dollars $
    double monthlyPropertyTax; //dollars $
    double monthlyUtilities; //dollars $
    double timeOwned; //years
    double currentValue; // dollars $
    double monthlyEarnings; // dollars $
    double ROI; // percentage % 
    double capitalGains; // dollars 
    double capitalGainsRate; //dollars per year $/year
    char type[MAX_STR]; //type of property
    double performanceIndex; //ROI x capital gains rate
};
struct Company {
    char name[MAX_STR]; // company's name
    char address[MAX_STR]; // company's address
    int propertiesOwned; // total property owned by company
    double totalMonthlyEarnings; // company's total monthly earnings
    double totalROI; // company's total ROI
    int bestPerformanceIndex; // index of best performance property
    struct BasicInfo apartment[NUM_APART];
    struct BasicInfo townHouse[NUM_TOWN];
    struct BasicInfo semiDetachedHouse[NUM_SEMI];
};

void initializeInfo(struct Company *property); // chet
void monthlyEarnings(struct BasicInfo *property); // aditti
double totalMonthlyEarnings(struct BasicInfo *property, int num); // aditti 
double averageMonthlyEarnings(struct BasicInfo *property, int num); // hasan
void ROI(struct BasicInfo *property); // sarah
double totalROI(struct BasicInfo *property, int num); // sarah
void currentValue(struct BasicInfo *property); // defne
double totalValue(struct BasicInfo *property, int num); // defne
void capitalGains(struct BasicInfo *property); // hasan
void capitalGainsRate(struct BasicInfo *property); // defne
double totalCapitalGains(struct BasicInfo *property, int num); // aditi
double averageGainsRate(struct BasicInfo *property, int num); // hasan
void performanceIndex(struct BasicInfo *property); // hasan
int topProperty(struct Company *company); // chet
void displayInfo(struct BasicInfo *property, int num); // chet 
void displayTopProperty(struct Company *property); // chet
