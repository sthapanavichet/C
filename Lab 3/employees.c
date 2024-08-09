// Name: Sthapanavichet Long 
// Student ID: 1375802215

#include <stdio.h>
#include <windows.h>
#include "employees.h"
#define MAX_EMP 4

int main() {
    int exit = 0, done = 0, emptyslot = 0; // flags for exiting loops
    int option;
    struct Employee employee[MAX_EMP]; // initializing struct
    for(int i = 0; i < MAX_EMP; i++) { // initialize employee id as 0, so it won't display random numbers.
        employee[i].id = 0;
    }
    do 
    { 
        option = userPrompt(); // User's input
        int inputID = 0; 
        switch (option) {
            case 1: // Display Employee's ID, Age, Salary
                printf("\n%-10s %-10s %-10s\n", "EMP ID", "EMP AGE", "EMP SALARY");
                printf("=================================\n");
                for(int i = 0; i < MAX_EMP ; i++) {
                    if(employee[i].id != 0) {
                    printf("%-10d %-10d %-10.3lf$\n", employee[i].id, employee[i].age, employee[i].salary);
                    }
                }
                break;
            case 2: // Adding new employee
                printf("\nAdding Empolyee\n");
                printf("===============\n");
                done = 0;
                for(int i = 0; i < MAX_EMP && done == 0; i++) { // checking for available slots in struct for new employee
                    if(employee[i].id == 0) {
                        printf("Enter Empolyee ID: ");
                        scanf("%d", &employee[i].id);
                        printf("Enter Empolyee Age: ");
                        scanf("%d", &employee[i].age);
                        printf("Enter Empolyee Salary: ");
                        scanf("%lf", &employee[i].salary);
                        done = 1;
                    }
                    else if(i == MAX_EMP-1 && done == 0) { 
                        printf("ERROR!!! Maximum Number of Employees Reached\n");
                        done = 1;
                    }
                    
                }
                break;
            case 3: // Update employee salary
                printf("\nUpdate Employee Salary\n");
                printf("======================\n");
                done = 0;
                do // Checking for correct ID
                {
                    for(int i = 0; i < MAX_EMP; i++) {
                    if(employee[i].id == 0) {
                            emptyslot += 1;
                            if(emptyslot == MAX_EMP) {
                                printf("*** ERROR: There is no employees in the database. ***");
                                done = 1;
                            }
                        }
                    }
                    printf("Enter Employee ID: ");
                    scanf("%d", &inputID);
                    for(int i = 0; i < MAX_EMP && done == 0; i++) {
                        if(employee[i].id == inputID) {
                            printf("The current Salary is: %lf$\n", employee[i].salary);
                            printf("Enter Employee New Salary: ");
                            scanf("%lf", &employee[i].salary);
                            done = 1;
                        }
                        if(i == MAX_EMP - 1 && done == 0) {
                            printf("*** ERROR: Employee ID not found! ***\n");
                        }
                    }
                } while(done == 0);
                break;
            case 4: // Removing employee
                printf("\nRemove Employee\n");
                printf("===============\n");
                done = 0;
                int emptyslot = 0;
                do // Checking for correct ID
                {
                    for(int i = 0; i < MAX_EMP; i++) {
                    if(employee[i].id == 0) {
                            emptyslot += 1;
                            if(emptyslot == MAX_EMP) {
                                printf("*** ERROR: There is no employees in the database. ***");
                                done = 1;
                            }
                        }
                    }
                    printf("Enter Employee ID: ");
                    scanf("%d", &inputID);
                    for(int i = 0; i < MAX_EMP; i++) {
                        if(employee[i].id == inputID) {
                            printf("\nEmployee %d is removed\n", employee[i].id);
                            employee[i].id = 0;
                            employee[i].age = 0;
                            employee[i].salary = 0;
                            done = 1;
                        }
                        if(i == MAX_EMP - 1 && done == 0) {
                            printf("*** ERROR: Employee ID not found! ***\n");
                        }
                    }
                } while(done == 0);
                break;
            case 0: // exit program
                printf("Bye, Have a great day!");
                exit = 1;
                break;
            default: // Incorrect option
                printf("\nIncorrect Option, Try Again!");
                break;
        }   
    } while(exit == 0);

    return 0;
}

