//
// Created by Marc Neisser on 11/28/16.
//

#include "employeeDB.h"
#include "employee.h"
#include <iostream>

using namespace std;

employeeDB::employeeDB() {
    nextID=0;
}

void employeeDB::addEmployee() {
    employee employee1;
    if(nextID==0){
        employee1.setID(0);
        nextID=1;

    } else{
        employee1.setID(nextID);
        nextID++;
    }
    dbVector.push_back(employee1);

}

void employeeDB::addEmployee(employee employee1) {
    if(nextID==0){
        employee1.setID(0);
        nextID=1;

    } else{
        employee1.setID(nextID);
        nextID++;
    }
    dbVector.push_back(employee1);
}

void employeeDB::deleteEmployee(int location) {
    dbVector.erase(dbVector.begin()+location);
}

//TODO: make this formating look better
void employeeDB::printDB() {
    if(dbVector.empty()){
        cout<<"List is empty."<<endl;
    }if(lastIndexUsed==ID && lastIndexOrder==ASCENDING) {
        for (int i = 0; i < dbVector.size(); ++i) {
            printEmployee(i);
        }
    }if(lastIndexUsed!=ID && lastIndexOrder!=ASCENDING){
        for (int i = 0; i < dbIndex.size(); ++i) {
            for (int j = 0; j < dbVector.size(); ++j) {
                if(dbIndex[i].getID()==dbVector[j].getID()){
                    printEmployee(j);
                    break;
                }
            }
        }
    }
}
//TODO: make sure the initial switch works
void employeeDB::employeeIndex(int fieldToIndex, int orderToIndex) {
    int dbSize=dbVector.size();
    lastIndexUsed=fieldToIndex;
    lastIndexOrder=orderToIndex;
    switch (fieldToIndex){
        default:
        case ID:
            for (int i = 0; i < dbSize; ++i) {
                employee temp1=employee(true);
                temp1.setID(dbVector[i].getID());
                dbIndex.push_back(temp1);
            }
            break;
        case FIRST_NAME:
            for (int j = 0; j < dbSize; ++j) {
                employee temp2=employee(true);
                temp2.setID(dbVector[j].getID());
                temp2.setFirstName(dbVector[j].getFirstName());
                dbIndex.push_back(temp2);
            }
            break;
        case LAST_NAME:
            for (int k = 0; k < dbSize; ++k) {
                employee temp3=employee(true);
                temp3.setID(dbVector[k].getID());
                temp3.setLastName(dbVector[k].getLastName());
                dbIndex.push_back(temp3);
            }
            break;
        case SSN:
            for (int l = 0; l < dbSize; ++l) {
                employee temp4=employee(true);
                temp4.setID(dbVector[l].getID());
                temp4.setSSN(dbVector[l].getSSN());
                dbIndex.push_back(temp4);
            }
            break;
        case SALARY:
            for (int m = 0; m < dbSize; ++m) {
                employee temp5=employee(true);
                temp5.setID(dbVector[m].getID());
                temp5.setSalary(dbVector[m].getSalary());
                dbIndex.push_back(temp5);
            }
            break;
        case AGE:
            for (int n = 0; n < dbSize; ++n) {
                employee temp6=employee(true);
                temp6.setID(dbVector[n].getID());
                temp6.setAge(dbVector[n].getAge());
                dbIndex.push_back(temp6);
            }
            break;
    }

    quickSort(fieldToIndex);

    switch (orderToIndex){
        default:
        case ASCENDING:
            break;
        case DESCENDING:
            //TODO: test if i>=0 will cause an error
            vector<employee> tempIndexVector;
            for (int i = dbIndex.size(); i >= 0; --i) {
                tempIndexVector.push_back(dbIndex[i]);
            }
            dbIndex=tempIndexVector;
    }
    lastIndexUsed=fieldToIndex;
    lastIndexOrder=orderToIndex;
}
//TODO: need to test quick sort function
void employeeDB::quickSort(int sortType) {
    recQuickSort(0,dbIndex.size()-1,sortType);
}

void employeeDB::recQuickSort(int first, int last, int sortType) {
    int pivotLocation;

    if(first<last){
        pivotLocation=partition(first,last,sortType);
        recQuickSort(first,pivotLocation-1,sortType);
        recQuickSort(pivotLocation+1,last,sortType);
    }
}

void employeeDB::swap(int first, int second) {
    employee temp;

    temp=dbIndex[first];
    dbIndex[first]=dbIndex[second];
    dbIndex[second]=temp;
}

int employeeDB::partition(int first, int last, int sortType) {
    int pivot;

    int index, smallIndex;

    swap(first, (first+last)/2);

    pivot=dataTypeSwitch(first,sortType);
    smallIndex=first;

    for (index = first+1; index <= last; index++) {
        if(dataTypeSwitch(index,sortType) < pivot){
            smallIndex++;
            swap(smallIndex,index);
        }
    }
    swap(first,smallIndex);

    return smallIndex;
}
//this switch is used to take the data from the data base and transform it into an integer to be read by the partition function for sorting
int employeeDB::dataTypeSwitch(int position, int sortType) {
    char tempChar;
    string tempString;
    int tempInt;

    //this switch manages handling the different data types of the potential index list so the sorting can be
    //done using basic integer quick sorting. This is a pain but itll work wonderfully.
    switch (sortType){
        case FIRST_NAME:
            tempChar=dbIndex[position].getFirstName().at(0);
            putchar(tolower(tempChar));
            tempInt= static_cast<int>(tempChar);
        case LAST_NAME:
            tempChar=dbIndex[position].getLastName().at(0);
            putchar(tolower(tempChar));
            tempInt= static_cast<int>(tempChar);
        case SSN: //TODO: NEEDS SERIOUS TESTING TO ENSURE THIS WORKS PROPERLY. This heavily relies on there being no error in the ssn entry
            tempString=dbIndex[position].getSSN();
            tempString.erase(3);
            tempString.erase(6);
            tempInt=stoi(tempString);
        case AGE:
            tempInt=dbIndex[position].getAge();
        case SALARY:
            tempInt=dbIndex[position].getSalary();
    }

    return tempInt;

}

int employeeDB::searchEmployeeSSN(string ssn) {
    int loc;
    bool found = false;

    for (int loc = 0; loc < dbVector.size(); ++loc) {
        if(dbVector[loc].getSSN()==ssn){
            found=true;
            break;
        }
    }
    if(found){
        return loc;
    }else{
        return -1;
    }
}

void employeeDB::printEmployee(int location) {
    employee temp = dbVector[location];
    cout<<temp.getID()<<" | "
                      <<temp.getFirstName()<<" | "
                                           <<temp.getLastName()<<" | "
                                                               <<temp.getAge()<<" | "
                                                                              <<temp.getSalary()<<" | "
                                                                                                <<temp.getSSN()<<endl;
}