#include <iostream>
#include "Single_Linked_List.h"
#include "Employee.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
    // Test Single_Linked_List
    Single_Linked_List<int> myList;
    myList.push_back(1);
    myList.push_back(2);
    myList.push_back(3);

    cout << "List Size: " << myList.size() << endl;
    cout << "List: ";
    myList.print();
    cout << "Front: " << myList.front() << " Back: " << myList.back() << endl;
    cout << "Searching 2 in the List..." << endl;
    size_t foundIndex = myList.find(2);
    if (foundIndex < myList.size()) {
        cout << "Item found at index " << foundIndex << endl;
    }
    else {
        cout << "Item not found in the list" << endl;
    }

    cout << endl;


    myList.pop_front();
    myList.insert(1, 4);
    myList.remove(1);

    cout << "List Size: " << myList.size() << endl;

    cout << "List: ";
    myList.print();

    cout << "Front: " << myList.front() << " Back: " << myList.back() << endl;


    cout << "Searching 4 in the List..." << endl;
    foundIndex = myList.find(4);
    if (foundIndex < myList.size()) {
        cout << "Item found at index " << foundIndex << endl;
    }
    else {
        cout << "Item not found in the list" << endl;
    }
    cout << endl;
    Professional profEmployee("Alice Professional", 5500.0);
    Nonprofessional nonprofEmployee("Bob Nonprofessional", 14.5, 55);

    // Calculate and print information for professional employee
    cout << "Professional Employee Information:" << endl;
    cout << "Name: " << profEmployee.getName() << endl;
    cout << "Weekly Salary: $" << profEmployee.calculateWeeklySalary() << endl;
    cout << "Health Care Contributions: $" << profEmployee.calculateHealthCareContributions() << endl;
    cout << "Vacation Days: " << profEmployee.calculateVacationDays() << endl;

    // Calculate and print information for nonprofessional employee
    cout << "\nNonprofessional Employee Information:" << endl;
    cout << "Name: " << nonprofEmployee.getName() << endl;
    cout << "Weekly Salary: $" << nonprofEmployee.calculateWeeklySalary() << endl;
    cout << "Health Care Contributions: $" << nonprofEmployee.calculateHealthCareContributions() << endl;
    cout << "Vacation Days: " << nonprofEmployee.calculateVacationDays() << endl;
    string input;

    cout << "Welcome to the Employee Information Program!" << endl;

    do {
        cout << "\nEnter 'yes' to input data for an employee, or any other key to exit: ";
        cin >> input;

        if (input != "yes") {
            break;  // Exit the loop if the input is not "yes"
        }

        string empName;
        double empSalary, empRate = 0.0;
        int empHours;

        // Input data for the new employee
        cout << "\nEnter data for the Employee:" << endl;
        cout << "Enter the name: ";
        cin.ignore(); // Clear the newline character from the input buffer
        getline(cin, empName);
        cout << "Enter the monthly salary or hourly rate(if =<50$ an hour will be nonProfessional and >=5000$ a month will be Professional : $";
        cin >> empSalary;

        if (empSalary <= 0) {
            cout << "Invalid salary/rate. Please enter a positive value." << endl;
            continue;  // Restart the loop to re-enter data
        }

        // Check if the employee is professional or nonprofessional based on hourly rate
        if (empSalary >= 5000.0) {
            Professional newProfEmployee(empName, empSalary);
            cout << "\nProfessional Employee Information:" << endl;
            cout << "Name: " << newProfEmployee.getName() << endl;
            cout << "Weekly Salary: $" << newProfEmployee.calculateWeeklySalary() << endl;
            cout << "Health Care Contributions: $" << newProfEmployee.calculateHealthCareContributions() << endl;
            cout << "Vacation Days: " << newProfEmployee.calculateVacationDays() << endl;
        }
        else {
            // Check if the hourly rate is less than or equal to $50 to be considered nonprofessional
            if (empSalary <= 50.0) {
                cout << "Enter the number of hours worked for nonprofessional: ";
                cin >> empHours;

                if (empHours < 0) {
                    cout << "Invalid worked hours. Please enter a non-negative value." << endl;
                    continue;  // Restart the loop to re-enter data
                }

                Nonprofessional newNonprofEmployee(empName, empSalary, empHours);
                cout << "\nNonprofessional Employee Information:" << endl;
                cout << "Name: " << newNonprofEmployee.getName() << endl;
                cout << "Weekly Salary: $" << newNonprofEmployee.calculateWeeklySalary() << endl;
                cout << "Health Care Contributions: $" << newNonprofEmployee.calculateHealthCareContributions() << endl;
                cout << "Vacation Days: " << newNonprofEmployee.calculateVacationDays() << endl;
            }
            else {
                cout << "Invalid hourly rate. Please enter a rate less than or equal to $50 an hour to be nonprofessional >=5000% a month will be Professional." << endl;
                continue;  // Restart the loop to re-enter data
            }
        }

    } while (true);

    cout << "Thank you for using the Employee Information Program!" << endl;

    return 0;

}


