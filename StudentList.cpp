/*
 * This program functions to create a system that can keep track of inputted student's first and last name as well as ID
 * and GPA. I had help from cplusplus.com, stackoverflow.com, and Ethan Wang
 * Author: Pujan Patel
 * Date: 3/14/2021
 */
//libraries
#include <iostream>
#include <vector>
#include <cstring>
#include <sstream>
#include <cstdlib>
#include <iomanip>
using namespace std;

struct studentInfo {//sturct for student info
    char firstName[80];
    char lastName[80];
    int studentID;
    float studentGPA;
};
//declare functions(delete, print, and add)
void deleteStudent(vector<studentInfo*>* studentVector);
void printStudent(vector<studentInfo*> studentVector);

studentInfo* addStudent() {
studentInfo* createStudent = new studentInfo();
    cout << "Enter Student's first name" << endl;
    cin >> createStudent -> firstName;
    cout << "Enter Student's last name" << endl;
    cin >> createStudent -> lastName;
    cout << "Enter Student's ID" << endl;
    cin >> createStudent -> studentID;
    cout << "Enter Student's GPA" << endl;
    cin >> createStudent -> studentGPA;
    return createStudent;
}

int main() {//main method
    //initialize variables
    char input[80];
    bool running = true;
    vector<studentInfo*> studentVector;
    
    while(running) {//while not quit, request command and call function to do it
        cout << "Please input ADD, PRINT, DELETE, or QUIT" << endl;
        cin >> input;
        if(strcmp(input, "ADD") == 0) {
            studentVector.push_back(addStudent());
            cout << "Student Added" << endl;
        }
        else if(strcmp(input, "PRINT") == 0) {
            printStudent(studentVector);
        }
        else if(strcmp(input, "DELETE") == 0) {
            deleteStudent(&studentVector);
            cout << "Student Deleted" << endl;
        }
        else if(strcmp(input, "QUIT") == 0) {
            running = false;
        }
        else {
            cout << "Please enter above options (Case-Sensitive)" << endl;
        }
    }
    return 0;
}

void printStudent(vector<studentInfo*> studentVector) {//print vector contents (student info)
    if (studentVector.empty() == true) {
        cout << "List is empty" << endl;
    }
    else {
        for (vector<studentInfo*> :: iterator printAll = studentVector.begin(); printAll != studentVector.end(); ++printAll) {
            cout << "First Name: " << (*printAll) -> firstName << endl;
            cout << "Last Name: " << (*printAll) -> lastName << endl;
            cout << "Student ID: " << (*printAll) -> studentID << endl;
            cout << "Student GPA: " << setprecision(2) << fixed << (*printAll) -> studentGPA << endl;
        }
    }
}
void deleteStudent(vector<studentInfo*>* studentVector) {//delete vector content of specifc ID
    int studentIDSearch;
    cout << "Please input ID of student you want to delete" << endl;
    cin >> studentIDSearch;
    if (studentVector -> empty() == true) {
        cout << "List is empty" << endl;
    }
    else {
        for (vector<studentInfo*>:: iterator find = studentVector -> begin(); find != studentVector -> end(); ++find) {
            if ((*find) -> studentID == studentIDSearch) {
	            delete *find;
	            studentVector -> erase(find);
	            return;
            }
            else {
                cout << "Student does not exist" << endl;
            }
        }
    }     
}

