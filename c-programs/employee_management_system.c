#include <stdio.h>
#include <string.h>

#define MAX_EMPLOYEES 100

typedef struct {
    int id;
    char name[50];
    float salary;
} Employee;

Employee employees[MAX_EMPLOYEES];
int employeeCount = 0;

void addEmployee() {
    if (employeeCount >= MAX_EMPLOYEES) {
        printf("Employee limit reached!\n");
        return;
    }
    printf("Enter Employee ID: ");
    scanf("%d", &employees[employeeCount].id);
    printf("Enter Employee Name: ");
    scanf(" %[^\n]", employees[employeeCount].name);
    printf("Enter Employee Salary: ");
    scanf("%f", &employees[employeeCount].salary);
    employeeCount++;
    printf("Employee added successfully!\n");
}

void updateEmployee() {
    int id, found = 0;
    printf("Enter Employee ID to update: ");
    scanf("%d", &id);
    for (int i = 0; i < employeeCount; i++) {
        if (employees[i].id == id) {
            found = 1;
            printf("Updating Employee ID: %d\n", id);
            printf("Enter new name: ");
            scanf(" %[^\n]", employees[i].name);
            printf("Enter new salary: ");
            scanf("%f", &employees[i].salary);
            printf("Employee updated successfully!\n");
            break;
        }
    }
    if (!found) {
        printf("Employee with ID %d not found!\n", id);
    }
}

void deleteEmployee() {
    int id, found = 0;
    printf("Enter Employee ID to delete: ");
    scanf("%d", &id);
    for (int i = 0; i < employeeCount; i++) {
        if (employees[i].id == id) {
            found = 1;
            for (int j = i; j < employeeCount - 1; j++) {
                employees[j] = employees[j + 1];
            }
            employeeCount--;
            printf("Employee with ID %d deleted successfully!\n", id);
            break;
        }
    }
    if (!found) {
        printf("Employee with ID %d not found!\n", id);
    }
}

void showAllEmployees() {
    if (employeeCount == 0) {
        printf("No employees to display.\n");
        return;
    }
    printf("Employee List:\n");
    for (int i = 0; i < employeeCount; i++) {
        printf("ID: %d, Name: %s, Salary: %.2f\n", employees[i].id, employees[i].name, employees[i].salary);
    }
}

void searchHighestSalary() {
    if (employeeCount == 0) {
        printf("No employees to search.\n");
        return;
    }
    float highestSalary = employees[0].salary;
    int highestId = employees[0].id;
    char highestName[50];
    strcpy(highestName, employees[0].name);

    for (int i = 1; i < employeeCount; i++) {
        if (employees[i].salary > highestSalary) {
            highestSalary = employees[i].salary;
            highestId = employees[i].id;
            strcpy(highestName, employees[i].name);
        }
    }
    printf("Employee with highest salary: ID: %d, Name: %s, Salary: %.2f\n", highestId, highestName, highestSalary);
}

void searchEmployeeById() {
    int id, found = 0;
    printf("Enter Employee ID to search: ");
    scanf("%d", &id);
    for (int i = 0; i < employeeCount; i++) {
        if (employees[i].id == id) {
            found = 1;
            printf("Employee found: ID: %d, Name: %s, Salary: %.2f\n", employees[i].id, employees[i].name, employees[i].salary);
            break;
        }
    }
    if (!found) {
        printf("Employee with ID %d not found!\n", id);
    }
}

int main() {
    int choice;
    do {
        printf("\nEmployee Management System\n");
        printf("1. Add Employee\n");
        printf("2. Update Employee\n");
        printf("3. Delete Employee\n");
        printf("4. Show All Employees\n");
        printf("5. Search Employee by Highest Salary\n");
        printf("6. Search Employee by ID\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addEmployee(); break;
            case 2: updateEmployee(); break;
            case 3: deleteEmployee(); break;
            case 4: showAllEmployees(); break;
            case 5: searchHighestSalary(); break;
            case 6: searchEmployeeById(); break;
            case 7: printf("Exiting...\n"); break;
            default: printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 7);

    return 0;
}
