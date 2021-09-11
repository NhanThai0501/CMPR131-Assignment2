// optionOne.h

#ifndef OPTION_ONE_LOCK
#define OPTION_ONE_LOCK

#include "Employee.h"
#include "input.h"

#include<sstream>
#include <iostream>
#include <fstream>
#include <vector>
#include <cctype>

void displayAllRecords(std::vector<Employee> obj);

//void listOfEmployees();
//void displayOptionOneMenu(void);
/*
void readData(std::vector<Employee> obj)
{
    system("CLS");

    obj.clear();

    std::ifstream source;
    while (true)
    {
        string s;
        source.open(inputString("Enter the file name: ", true));
        if (!source.fail()) break;
        std::cout << "open failed, try again" << std::endl;
        source.clear();
    }

    while (true)
    {
        std::string line;
        std::getline(source, line);
        if (source.fail()) break; // not "failure", just end of file

        std::stringstream line1(line);
        std::string segment;
        std::vector<std::string> employeeInformation;

        while (std::getline(line1, segment, '_'))
        {
            employeeInformation.push_back(segment);
        }

        obj.push_back(Employee(employeeInformation.at(0), employeeInformation.at(1),
            employeeInformation.at(2), employeeInformation.at(3),
            employeeInformation.at(4), employeeInformation.at(5)));


    }
}*/

void readData(std::vector<Employee>& obj)
{
    obj.clear();

    std::vector<string> fileData;

    std::ifstream source;
    while (true)
    {
        string s;
        source.open(inputString("\n\t\tEnter the file name: ", true));
        if (!source.fail()) break;
        std::cout << "open failed, try again" << std::endl;
        source.clear();
    }

    while (true)
    {
        std::string line;
        std::getline(source, line);
        if (source.fail()) break; // not "failure", just end of file

        std::stringstream stream(line);
        while (stream.good()) {
            string substr;
            getline(stream, substr, ',');
            fileData.push_back(substr);
        }

    }

    // This could possibly be done in the above while loop.
    // will clean this up later
    if (fileData.size() % 6 != 0) std::cout << "mismatch data" << std::endl;
    else
    {
        for (int i = 0; i < fileData.size(); i++)
        {
            if (i % 6 == 0 && fileData.size() != i + 1 || i == 0)
            {
                Employee employee;
                employee.setStatus(fileData.at(i));
                employee.setEmployeeNumber(fileData.at(i + 1));
                employee.setLastName(fileData.at(i + 2));
                employee.setFirstName(fileData.at(i + 3));
                employee.setStartDate(fileData.at(i + 4));
                employee.setEndDate(fileData.at(i + 5));

                obj.push_back(employee);
            }
        }
        std::cout << "\n\t\tCompleted transfering data from file to list." << std::endl;
    }

    
}

//void insertEmployee(std::vector<Employee> obj);
//void updateRecord(std::vector<Employee> obj);

void displayAllRecords(std::vector<Employee> obj)
{
    if (obj.size() == 0)
    {
        std::cout << "\n\t\tNo record found." << std::endl;
        return;
    }

    for (int i = 0; i < obj.size(); i++)
    {
        std::cout << "\n\t\tEmployee ID   : " << obj[i].getEmployeeNumber() << std::endl;
        std::cout << "\t\tName          : " << obj[i].getLastName() + ", " + obj[i].getFirstName() << std::endl;
        std::cout << "\t\tStatus        : " << obj[i].getStatus() << std::endl;
        std::cout << "\t\tStart Date    : " << obj[i].getStartDate() << std::endl;
        std::cout << "\t\tEnd Date      : " << obj[i].getEndDate();
        std::cout << std::endl;
    }


}

void displayAllActiveRecords(std::vector<Employee> obj)
{
    std::vector<Employee> temp;
    for (int i = 0; i < obj.size(); i++)
    {
        if (obj[i].getStatus() == 'A') temp.push_back(obj[i]);
    }

    if (temp.size() == 0)
    {
        std::cout << "\n\t\tNo record found." << std::endl;
        return;
    }
    for (int i = 0; i < temp.size(); i++)
    {
        std::cout << "\n\t\tEmployee ID   : " << temp[i].getEmployeeNumber() << std::endl;
        std::cout << "\t\tName          : " << temp[i].getLastName() + ", " + temp[i].getFirstName() << std::endl;
        std::cout << "\t\tStatus        : " << temp[i].getStatus() << std::endl;
        std::cout << "\t\tStart Date    : " << temp[i].getStartDate() << std::endl;
        std::cout << "\t\tEnd Date      : " << temp[i].getEndDate();
        std::cout << std::endl;
    }


}

void displayAllInactiveRecords(std::vector<Employee> obj)
{
    std::vector<Employee> temp;
    for (int i = 0; i < obj.size(); i++)
    {
        if (obj[i].getStatus() == 'I') temp.push_back(obj[i]);
    }

    if (temp.size() == 0)
    {
        std::cout << "\n\t\tNo record found." << std::endl;
        return;
    }
    for (int i = 0; i < temp.size(); i++)
    {
        std::cout << "\n\t\tEmployee ID   : " << temp[i].getEmployeeNumber() << std::endl;
        std::cout << "\t\tName          : " << temp[i].getLastName() + ", " + temp[i].getFirstName() << std::endl;
        std::cout << "\t\tStatus        : " << temp[i].getStatus() << std::endl;
        std::cout << "\t\tStart Date    : " << temp[i].getStartDate() << std::endl;
        std::cout << "\t\tEnd Date      : " << temp[i].getEndDate();
        std::cout << std::endl;
    }


}

//void writeToFile(std::vector<Employee> obj);


#endif