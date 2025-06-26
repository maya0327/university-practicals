#include <iostream>
#include <string>

using namespace std;

const int MAX_EMPLOYEES = 100;

struct Employee {
    int id;
    string name;
    float salary;
};

Employee employees[MAX_EMPLOYEES];
int employeeCount = 0;

void addEmployee() {
    if (employeeCount >= MAX_EMPLOYEES) {
        cout << "Employee limit reached!" << endl;
        return;
    }
    cout << "Enter Employee ID: ";
    cin >> employees[employeeCount].id;
    cout << "Enter Employee Name: ";
    cin.ignore(); // To ignore the newline character left in the buffer
    getline(cin, employees[employeeCount].name);
    cout << "Enter Employee Salary: ";
    cin >> employees[employeeCount].salary;
    employeeCount++;
    cout << "Employee added successfully!" << endl;
}

void updateEmployee() {
    int id;
    cout << "Enter Employee ID to update: ";
    cin >> id;

    for (int i = 0; i < employeeCount; i++) {
        if (employees[i].id == id) {
            cout << "Updating Employee ID: " << id << endl;
            cout << "Enter new name: ";
            cin.ignore();
            getline(cin, employees[i].name);
            cout << "Enter new salary: ";
            cin >> employees[i].salary;
            cout << "Employee updated successfully!" << endl;
            return;
        }
    }
    cout << "Employee with ID " << id << " not found!" << endl;
}

void deleteEmployee() {
    int id;
    cout << "Enter Employee ID to delete: ";
    cin >> id;

    for (int i = 0; i < employeeCount; i++) {
        if (employees[i].id == id) {
            for (int j = i; j < employeeCount - 1; j++) {
                employees[j] = employees[j + 1];
            }
            employeeCount--;
            cout << "Employee with ID " << id << " deleted successfully!" << endl;
            return;
        }
    }
    cout << "Employee with ID " << id << " not found!" << endl;
}

void showAllEmployees() {
    if (employeeCount == 0) {
        cout << "No employees to display." << endl;
        return;
    }
    cout << "Employee List:" << endl;
    for (int i = 0; i < employeeCount; i++) {
        cout << "ID: " << employees[i].id << ", Name: " << employees[i].name << ", Salary: " << employees[i].salary << endl;
    }
}

void searchHighestSalary() {
    if (employeeCount == 0) {
        cout << "No employees to search." << endl;
        return;
    }
    int highestIndex = 0;
    for (int i = 1; i < employeeCount; i++) {
        if (employees[i].salary > employees[highestIndex].salary) {
            highestIndex = i;
        }
    }
    cout << "Employee with highest salary: ID: " << employees[highestIndex].id
         << ", Name: " << employees[highestIndex].name
         << ", Salary: " << employees[highestIndex].salary << endl;
}

void searchEmployeeById() {
    int id;
    cout << "Enter Employee ID to search: ";
    cin >> id;

    for (int i = 0; i < employeeCount; i++) {
        if (employees[i].id == id) {
            cout << "Employee found: ID: " << employees[i].id
                 << ", Name: " << employees[i].name
                 << ", Salary: " << employees[i].salary << endl;
            return;
        }
    }
    cout << "Employee with ID " << id << " not found!" << endl;
}

int main() {
    int choice;

    do {
        cout << "\nEmployee Management System" << endl;
        cout << "1. Add Employee" << endl;
        cout << "2. Update Employee" << endl;
        cout << "3. Delete Employee" << endl;
        cout << "4. Show All Employees" << endl;
        cout << "5. Search Employee by Highest Salary" << endl;
        cout << "6. Search Employee by ID" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addEmployee();
                break;
            case 2:
                updateEmployee();
                break;
            case 3:
                deleteEmployee();
                break;
            case 4:
                showAllEmployees();
                break;
            case 5:
                searchHighestSalary();
                break;
            case 6:
                searchEmployeeById();
                break;
            case 7:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 7);

    return 0;
}
