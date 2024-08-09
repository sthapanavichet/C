#include <stdio.h>
struct Employee {
    int id;
    int age;
    double salary;
};

// prompting user for input
int userPrompt() {
    int option;
    printf("\n---===EMPLOYEE DATA===---\n");
    printf("1. Display Employee Information\n");
    printf("2. Add Employee\n");
    printf("3. Update Employee Salary\n");
    printf("4. Remove Employee\n");
    printf("0. Exit\n");
    printf("Please select from the above options: ");
    scanf("%d", &option);

    return option;
}