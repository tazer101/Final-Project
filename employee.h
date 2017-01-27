//
// Created by Marc Neisser on 11/28/16.
//

#ifndef FINAL_PROJECT_CUSTOMER_H
#define FINAL_PROJECT_CUSTOMER_H

#include <string>

using namespace std;
//this class is designed to hold all the data of a specific employee
class employee {
public:
    //default constructor should not take any parameters. all parameters should be set using the set functions
    //within the default constructors definitions.
    employee();
    //constructor used when indexing an already existing db
    employee(bool indexing);

    employee(string firstName,string lastName, string ssn, float salary, int age);
    //TODO: make constructor that allows me to add in employees without prompting user input.
    //setter function
    void setID(int ID1);
    void setLastName(string lName);
    void setFirstName(string fName);
    void setSSN(string SSN1);
    void setSalary(float sal);
    void setAge(int fAge);
    //getter functions
    int getID();
    string getLastName();
    string getFirstName();
    string getSSN();
    float getSalary();
    int getAge();

private:
    int id;
    string lastName;
    string firstName;
    string ssn;
    float salary;
    int age;

};


#endif //FINAL_PROJECT_CUSTOMER_H
