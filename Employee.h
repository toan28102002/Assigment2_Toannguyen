#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
using namespace std;

// Define a base class "Employee."
class Employee {
protected:
    string name; // A protected attribute to store the employee's name.

public:
    // Constructor for the Employee class.
    Employee(const string& name);
    
    // Virtual destructor to ensure proper cleanup in derived classes.
    virtual ~Employee();

    // Virtual functions, marked as pure (abstract), that must be implemented in derived classes.
    virtual double calculateWeeklySalary() const = 0;
    virtual double calculateHealthCareContributions() const = 0;
    virtual int calculateVacationDays() const = 0;

    // Member function to get the employee's name.
    string getName() const;
};

// Define a derived class "Professional" that inherits from the Employee class.
class Professional : public Employee {
private:
    double monthlySalary; // Additional attribute specific to professionals.

public:
    // Constructor for creating a Professional employee.
    Professional(const string& name, double salary);

    // Implementations of the virtual functions for Professional employees.
    double calculateWeeklySalary() const override;
    double calculateHealthCareContributions() const override;
    int calculateVacationDays() const override;
};

// Define another derived class "Nonprofessional" that also inherits from Employee.
class Nonprofessional : public Employee {
private:
    double hourlyRate; // Additional attribute specific to nonprofessionals.
    int hoursWorked; // Another attribute to track the hours worked.

public:
    // Constructor for creating a Nonprofessional employee.
    Nonprofessional(const string& name, double rate, int hours);

    // Implementations of the virtual functions for Nonprofessional employees.
    double calculateWeeklySalary() const override;
    double calculateHealthCareContributions() const override;
    int calculateVacationDays() const override;
};

#endif
