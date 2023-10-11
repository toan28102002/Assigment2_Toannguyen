#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
using namespace std;

class Employee {
protected:
    string name;

public:
    Employee(const string& name);
    virtual ~Employee();

    virtual double calculateWeeklySalary() const = 0;
    virtual double calculateHealthCareContributions() const = 0;
    virtual int calculateVacationDays() const = 0;
    string getName() const; // Member function to get the employee's name
};

class Professional : public Employee {
private:
    double monthlySalary;

public:
    Professional(const string& name, double salary);
    double calculateWeeklySalary() const override;
    double calculateHealthCareContributions() const override;
    int calculateVacationDays() const override;
};

class Nonprofessional : public Employee {
private:
    double hourlyRate;
    int hoursWorked;

public:
    Nonprofessional(const string& name, double rate, int hours);
    double calculateWeeklySalary() const override;
    double calculateHealthCareContributions() const override;
    int calculateVacationDays() const override;
};

#endif
