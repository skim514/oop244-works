#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Department.h"

using namespace std;

namespace sdds {

    //fully provided for students to display details of a project
    void display(const Project& project) {
        cout << "Project " << project.m_topic
            << " will cost a total of " << project.m_cost << " C$." << endl;
    }

    //fully provided for students to display details of a department
    void display(const Department& department) {
            Project* temp = department.fetchProjects();
            int projects = department.fetchNumProjects();
            cout << "Department " << department.fetchName() << " details:" << endl;
            cout << "Budget: " << department.fetchBudget()
                << " and the number of projects in progress is: " << projects << endl;
            cout << "Below are the details of the projects we are currently working on: " << endl;
            for (int i = 0; i < projects; i++) {
                display(temp[i]);
            }
    }
    void Department::updateName(const char* newname){
        if (newname != nullptr) {
            delete[] departmentName;//널이 아니니까 delete 해야지!!!
            departmentName = nullptr;
            departmentName = new char[strlen(newname)+1];
            strcpy(departmentName, newname);
        }
    }
    void Department::updateBudget(double change){
        if (change > 0) {
            budgetOfDept += change;
        }
        else {
            change = 0;
        }
    }
    bool Department::addProject(Project& newproject){
        Project* tmp = {0};
        int i = 0;
        bool result = false;
            if (remainingBudget() > newproject.m_cost && numOfProjects == 0) {
                numOfProjects++;//로직상 프로젝트가 적어도 하나는 더해져야 하는것.
                departmentProjects = nullptr;//타입은 프로젝트
                departmentProjects = new Project[numOfProjects];//자리를 이때 생성
                departmentProjects[0] = newproject;//새로생긴메모리에 저장..이게 저장한거라고!!
            }
            else{
                if (remainingBudget() > newproject.m_cost) {
                    numOfProjects++;
                    tmp = nullptr;
                    tmp = new Project[numOfProjects];
                    for (i = 0; i < numOfProjects - 1; i++) { //old
                        tmp[i] = departmentProjects[i];
                    }
                    tmp[numOfProjects-1] = newproject;
                    delete [] departmentProjects;
                    departmentProjects = nullptr;
                    departmentProjects = tmp;
                    result = true;
                }
            }
        return result;
    }
    void Department::createDepartment(const char* newname, Project& newproject, double change){
        updateName(newname);
        addProject(newproject);
        updateBudget(change);
    }
    Project* Department::fetchProjects() const{
        return departmentProjects;
    }
    int Department::fetchNumProjects() const{
        return numOfProjects;
    }
    double Department::fetchBudget() const{
        return budgetOfDept;
    }
    char* Department::fetchName() const{
        return departmentName;
    }
    double Department::totalexpenses(){
        double expenses = 0.0;
        int i = 0;
        
        for (i = 0; i < numOfProjects; i++) {
            expenses += departmentProjects[i].m_cost;
        }
        return expenses;
    }
    double Department::remainingBudget(){
        return budgetOfDept - totalexpenses();
    }
    void Department::clearDepartment(){
        delete [] departmentProjects;
        departmentProjects = nullptr;
        delete [] departmentName;
        departmentName = nullptr;
    }

}
