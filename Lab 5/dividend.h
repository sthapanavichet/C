#define MAX_COMP 5
#define MAX_STR 32
struct CompanyInfo {
    char name[MAX_STR];
    char symbol[MAX_STR];
    float stockPrice;
    double div;
    double divYield;
    char valuation[MAX_STR];
};

// functions prototype
void initializeInfo(struct CompanyInfo * company);
void userInput(struct CompanyInfo * company);
void calculateDivYield(struct CompanyInfo * company);
void companyValue(struct CompanyInfo * company); 
void output(struct CompanyInfo * company);
void clearInputBuffer();
