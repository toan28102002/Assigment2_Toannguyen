#include "Employee.h"

// Employee class
Employee::Employee(const string& name) : name(name) {}

Employee::~Employee() {}

string Employee::getName() const {
    return name;
}

// Professional class
Professional::Professional(const string& name, double salary) : Employee(name), monthlySalary(salary) {}

double Professional::calculateWeeklySalary() const {
    return monthlySalary / 4.0; // Assuming 4 weeks in a month
}

double Professional::calculateHealthCareContributions() const {
    return monthlySalary * 0.1; // 10% of monthly salary
}

int Professional::calculateVacationDays() const {
    return 15; // Assuming 15 days of vacation per year
}

// Nonprofessional class
Nonprofessional::Nonprofessional(const string& name, double rate, int hours) : Employee(name), hourlyRate(rate), hoursWorked(hours) {}

double Nonprofessional::calculateWeeklySalary() const {
    return hourlyRate * hoursWorked;
}

double Nonprofessional::calculateHealthCareContributions() const {
    return hourlyRate * hoursWorked * 0.05; // 5% of earnings
}

int Nonprofessional::calculateVacationDays() const {
    return hoursWorked / 40; // Assuming 40 hours per week
}
