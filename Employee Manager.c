/*----
You've been assigned the task of developing a program to manage employee records for a company. Each employee's record should include details such as their employee ID, name, age. The program should allow users to add a new employee, update employee information and display details of all employees.
Tasks:
1. Create a structure named Employee which can store the following information:
● Employee ID (an integer)
● Name (a string)
● Age (an integer)
2. void addEmployee(struct Employee *EmployeeList, int *numEmployees) which allows the management to add employees to the system if the number of employees does not exceed 100. If an employee can be added then It should update the EmployeeList and increment the value of numEmployees.
3. void displayEmployee(struct Employee *Employee_ptr) which prints the details of the employee Employee_ptr is pointing to.
4. void updateEmployeeInfo(struct Employee *EmployeeList, int *numEmployees, char *EmployeeName) allows a user to update Age of a particular employee using the employee name. If no such employee exists, add the information as a new employee.
In the main function:
● Create an array of Employees. [ There can be 100 employees at max ]
● Create an int variable numEmployees which will store the number of employees present in the company.
● Provide a menu for management to add employees (using addEmployee(-) function), update employee information and show the updated information (using updateEmployeeInfo(-) and displayEmployee(-) function).
-----*/
#include <stdio.h>
#include <string.h>

// Define the structure for Employee
struct Employee {
    int employeeID;
    char name[50];
    int age;
};

// Function to add a new employee
void addEmployee(struct Employee *EmployeeList, int *numEmployees) {
    if (*numEmployees < 100) {
        printf("Enter Employee ID: ");
        scanf("%d", &EmployeeList[*numEmployees].employeeID);

        printf("Enter Employee Name: ");
        scanf("%s", EmployeeList[*numEmployees].name);

        printf("Enter Employee Age: ");
        scanf("%d", &EmployeeList[*numEmployees].age);

        (*numEmployees)++;
        printf("Employee added successfully!\n");
    } else {
        printf("Maximum number of employees reached!\n");
    }
}

// Function to display details of an employee
void displayEmployee(struct Employee *Employee_ptr) {
    printf("Employee ID: %d\n", Employee_ptr->employeeID);
    printf("Employee Name: %s\n", Employee_ptr->name);
    printf("Employee Age: %d\n", Employee_ptr->age);
}

// Function to update employee information or add a new employee
void updateEmployeeInfo(struct Employee *EmployeeList, int *numEmployees, char *EmployeeName) {
    int found = 0;

    for (int i = 0; i < *numEmployees; i++) {
        if (strcmp(EmployeeList[i].name, EmployeeName) == 0) {
            printf("Enter new age for %s: ", EmployeeName);
            scanf("%d", &EmployeeList[i].age);
            found = 1;
            printf("Employee information updated successfully!\n");
            break;
        }
    }

    if (!found) {
        // If the employee is not found, add a new employee with the given name
        strcpy(EmployeeList[*numEmployees].name, EmployeeName);
        printf("Enter Employee ID: ");
        scanf("%d", &EmployeeList[*numEmployees].employeeID);

        printf("Enter Employee Age: ");
        scanf("%d", &EmployeeList[*numEmployees].age);

        (*numEmployees)++;
        printf("New employee added successfully!\n");
    }
}

int main() {
    struct Employee EmployeeList[100];
    int numEmployees = 0;
    int choice;
    char employeeName[50];

    do {
        // Display menu
        printf("\nEmployee Management System\n");
        printf("1. Add Employee\n");
        printf("2. Update Employee Information\n");
        printf("3. Display All Employees\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEmployee(EmployeeList, &numEmployees);
                break;
            case 2:
                printf("Enter the name of the employee to update: ");
                scanf("%s", employeeName);
                updateEmployeeInfo(EmployeeList, &numEmployees, employeeName);
                break;
            case 3:
                printf("\nEmployee Details:\n");
                for (int i = 0; i < numEmployees; i++) {
                    displayEmployee(&EmployeeList[i]);
                    printf("\n");
                }
                break;
            case 4:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 4);

    return 0;
}

