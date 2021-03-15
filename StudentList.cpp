#include <iostream>
#include <vector>
#include <cstring>
#include <sstream>
#include <cstdlib>
#include <iomanip>
using namespace std;

struct studentInfo {
    char firstName[80];
    char lastName[80];
    int studentID;
    float studentGPA;
};

void deleteStudent(vector<studentInfo*>* studentVector);
void printStudent(vector<studentInfo*> studentVector);

studentInfo* addStudent() {
studentInfo* createStudent = new studentInfo();
cin >> createStudent -> firstName;
cin >> createStudent -> lastName;
cin >> createStudent -> studentID;
cin >> createStudent -> studentGPA;
return createStudent;
}

int main() {
    char input[80];
    bool running = true;
    vector<studentInfo*> studentVector;
    
    while(running) {
        cin >> input;
        if(strcmp(input, "ADD") == 0) {
            studentVector.push_back(addStudent());
            cout << "Student Added" << endl;
        }
        else if(strcmp(input, "PRINT") == 0) {
            cout << "PRINT" << endl;
            printStudent(studentVector);
        }
        else if(strcmp(input, "DELETE") == 0) {
            cout << "Student Deleted" << endl;
        }
        else if(strcmp(input, "QUIT") == 0) {
            cout << "QUIT" << endl;
            running = false;
        }
    }
    return 0;
}

void printStudent(vector<studentInfo*> studentVector) {
    for (vector<studentInfo*> :: iterator printAll = studentVector.begin(); printAll != studentVector.end(); ++printAll) {
        cout << (*printAll) -> firstName << endl;
        cout << (*printAll) -> lastName << endl;
        cout << (*printAll) -> studentID << endl;
        cout << setprecision(2) << fixed << (*printAll) -> studentGPA << endl;
    }
}
void deletestudent(vector<studentInfo*>* studentVector) {
    int studentIDSearch;
    cin >> studentIDSearch;
    for (vector<studentInfo*> :: iterator findStudent = studentVector -> begin(); findStudent != studentVector -> end(); ++findStudent) {
        if((*findStudent) -> studentID == studentIDSearch) {
            delete *findStudent;
            studentVector -> erase(findStudent);
            return;
        }     
    }
}
