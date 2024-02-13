#include <iostream>
#include <string>

using namespace std;

struct Employee
{
    int employeeNumber;
    int employeeID;
    string employeeName;
    string qualification;
    float experience;
    long long contactNumber;
};

int main()
{
    const int maxEmployees = 1000;
    Employee employees[maxEmployees];

    int numEmployees = 0;

    char addAnotherEmployee = 'y';

    while (addAnotherEmployee == 'y')
        {
        cout << "\nEnter details for Employee #" << numEmployees + 1 << ":" << endl;

        cout << "Employee Number: ";
        cin >> employees[numEmployees].employeeNumber;

        cout << "Employee ID (4 digits): ";
        cin >> employees[numEmployees].employeeID;

        cout << "Employee Name: ";
        cin >> employees[numEmployees].employeeName;

        cout << "Qualification: ";
        cin >> employees[numEmployees].qualification;

        cout << "Experience: ";
        cin >> employees[numEmployees].experience;

        cout << "Contact Number (10 digits): ";
        cin >> employees[numEmployees].contactNumber;

        numEmployees++;

        cout << "\nDo you want to enter details for another employee? (y/n): ";
        cin >> addAnotherEmployee;
    }

    cout << "\nEmployee details entered:\n";
    for (int i = 0; i < numEmployees; ++i)
        {
        cout << "\nEmployee #" << i + 1 << ":\n";
        cout << "Employee Number: " << employees[i].employeeNumber << endl;
        cout << "Employee ID: " << employees[i].employeeID << endl;
        cout << "Employee Name: " << employees[i].employeeName << endl;
        cout << "Qualification: " << employees[i].qualification << endl;
        cout << "Experience: " << employees[i].experience << endl;
        cout << "Contact Number: " << employees[i].contactNumber << endl;
    }

    return 0;
}
