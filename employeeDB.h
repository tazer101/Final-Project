//
// Created by Marc Neisser on 11/28/16.
//

#ifndef FINAL_PROJECT_EMPLOYEEDB_H
#define FINAL_PROJECT_EMPLOYEEDB_H

#define ID 1
#define FIRST_NAME 2
#define LAST_NAME 3
#define SSN 4
#define SALARY 5
#define AGE 6

#define ASCENDING 9
#define DESCENDING 10

#include "employee.h"
#include <vector>

//this class is the database that holds the employee data
class employeeDB {
public:
    //initialize database
    employeeDB();
    //adds an employee to the database
    void addEmployee();
    //uses the ssn search function to find an employee and delete them from the database
    void addEmployee(employee employee1);
    void deleteEmployee(int location);

    void employeeIndex(int fieldToIndex, int orderToIndex);

    int partition(int first, int last, int sortType);

    void swap(int first, int second);

    void recQuickSort(int first, int last, int sortType);

    void quickSort(int sortType);

    void printDB();
    //this switch is used to take the data from the data base and transform it into an integer to be read by the partition function for sorting
    int dataTypeSwitch(int position, int sortType);

    int searchEmployeeSSN(string ssn);

    void printEmployee(int location);

private:
    //the list using the STL
    vector<employee> dbVector;
    //stores the last ID that was generated for an employee. default is null
    int nextID;
    //vector that holds the indexed data seperate from the main db
    vector<employee> dbIndex;
    //stores an id for the last method used for index. Default is ID
    int lastIndexUsed=ID;
    //stores whether the last index was in ascending or descending order. Default is ascending.
    int lastIndexOrder=ASCENDING;
};


#endif //FINAL_PROJECT_EMPLOYEEDB_H
