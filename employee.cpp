//
// Created by Marc Neisser on 11/28/16.
//

#include "employee.h"
#include "employeeDB.h"
#include <string>
#include <iostream>

using namespace std;
// TODO: add cancelation functionality that will allow user to type cancel at any time to end program
employee::employee() {
    int age1;
    string first;
    string last;
    string ssn1;
    float salary1;
    //TODO: make safety to pop error when improper data type is inputed. Serious error happens otherwise.
    //TODO: make character limit of 20 for first and last name
    cout<<"Enter employee's first name: ";
    cin>>first;
    setFirstName(first);
    cout<<"Enter employee's last name: ";
    cin>>last;
    setLastName(last);
    cout<<"Enter employee's age: ";
    cin>>age1;
    setAge(age1);
    cout<<"Enter employee's social security number in the form of XXX-XX-XXXX: ";
    //TODO: check other records to ensure ssn is unique
    setSSN(ssn1);
    // TODO: add functionality that will format this to XXX.XX for dollars and cents
    cout<<"Enter in employee's salary (do not use special characters besides . ): ";
    cin>>salary1;
    setSalary(salary1);

}
//function used for the automatic entry additions needed for project
employee::employee(string firstName, string lastName, string ssn, float salary, int age) {
    setFirstName(firstName);
    setLastName(lastName);
    setSSN(ssn);
    setSalary(salary);
    setAge(age);
}

employee::employee(bool indexing) {}

void employee::setID(int ID1) {id=ID1;}
void employee::setAge(int fAge) {age=fAge;}
void employee::setFirstName(string fName) {firstName=fName;}
void employee::setLastName(string lName) {lastName=lName;}
void employee::setSalary(float sal) {salary=sal;}
void employee::setSSN(string SSN1) {
    while (true) {
        cin>>SSN1;
        if(SSN1.size()==11) {
            if (SSN1.at(3) == '-' && SSN1.at(6) == '-') {
                ssn=SSN1;
                break;
            }
        }else{
            cerr<<"ERROR: the inputed ssn is too small or is not in the form of XXX-XX-XXXX. Please re-enter the SSN."<<endl;
        }
    }
    }

int employee::getID() {return id;}
int employee::getAge() { return age;}
string employee::getFirstName() { return firstName;}
string employee::getLastName() { return lastName;}
float employee::getSalary() { return salary;}
string employee::getSSN() { return ssn;}
