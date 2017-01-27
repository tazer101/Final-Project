//Marc Neisser
//Final project
#include <iostream>
#include <cstdlib>
#include "employee.h"
#include "employeeDB.h"
#include <queue>

employee createEmployee();

using namespace std;

int main() {

    queue<int> actionQueue;
    employeeDB someDB;
    employee employee1("john","doe","000-00-0000",10000,35);
    employee employee2("mary","jane","111-11-1111",30000,30);
    employee employee3("may","jeffers","222-22-2222",30000,43);
    employee employee4("john","ceferic","333-33-3333",40000,60);
    employee employee5("jorn","bjorn","444-44-4444",30000,36);
    employee employee6("yorn","corn","555-55-5555",30000,49);
    employee employee7("mark","emarc","666-66-6666",70000,97);
    employee employee8("will","ferrel","777-77-7777",90000,67);
    employee employee9("some","guy","888-88-8888",50000,56);
    employee employee10("good","employee","999-99-9999",10000,23);

    someDB.addEmployee(employee1);
    someDB.addEmployee(employee2);
    someDB.addEmployee(employee3);
    someDB.addEmployee(employee4);
    someDB.addEmployee(employee5);
    someDB.addEmployee(employee6);
    someDB.addEmployee(employee7);
    someDB.addEmployee(employee8);
    someDB.addEmployee(employee9);
    someDB.addEmployee(employee10);

    cout<<"Welcome to the employee database!"<<endl;
    cout<<"Please enter one of the following options followed by enter to build your queue."<<endl;
    cout<<"\n1 : Display database."<<endl;
    cout<<"2 : Search database for an SSN in the form of xxx-xx-xxxx."<<endl;
    cout<<"3 : Add a record to the database"<<endl;
    cout<<"4 : delete a record from the database."<<endl;
    cout<<"5 : The database based on a chosen field."<<endl;
    cout<<"\nTo begin executing your commands enter 6."<<endl;

    while(true){
        int action;
        cin>>action;
        if(action==6){
            break;
        }if(action>6 || action<1){
            cerr<<"That is not a valid menu option."<<endl;
        }else{
            actionQueue.push(action);
        }
    }

    while(actionQueue.size()>0) {
        switch (actionQueue.front()){
            case 1:
                someDB.printDB();
                break;
            case 2:
                string tempSSN;
                int location;
                cout<<"please enter in the SSN to be searched in the form of xxx-xx-xxxx: ";
                cin>>tempSSN;
                location=someDB.searchEmployeeSSN(tempSSN);
                someDB.printEmployee(location);
                break;
            case 3:
                someDB.addEmployee();
                break;
            case 4:
                int tempID;
                cout<<"Enter the ID of the employee to be erased from the databse: ";
                cin>>tempID;
                someDB.deleteEmployee(tempID);
                break;
            case 5:
                int fieldIndex;
                int orderIndex;
                cout<<"enter 1 to index by ID."<<endl;
                cout<<"enter 2 to index by first name."<<endl;
                cout<<"enter 3 to index by last name."<<endl;
                cout<<"enter 4 to index by SSN."<<endl;
                cout<<"enter 5 to index by salary."<<endl;
                cout<<"enter 6 to index by age."<<endl;
                cin>>fieldIndex;
                cout<<"enter 9 to index in ascending order."<<endl;
                cout<<"enter 10 to index in descending order."<<endl;
                cin>>orderIndex;
                someDB.employeeIndex(fieldIndex,orderIndex);
                break;

        }
        actionQueue.pop();
    }

    cout<<"All actions finished. Thank you for using the employee database!";

    return 0;
}

employee createEmployee(){
    employee tempEmployee=employee();
    return tempEmployee;
}