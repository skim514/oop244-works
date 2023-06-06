#ifndef SDDS_DEPARTMENT_H_
#define SDDS_DEPARTMENT_H_
namespace sdds {

    const int MAX_TOPIC_LENGTH = 25;

    struct Project {//old
        char m_topic[MAX_TOPIC_LENGTH+1];
        double m_cost;
    };

    //class Department does here
    class Department{
        char* departmentName;
        Project* departmentProjects;
        int numOfProjects;
        double budgetOfDept = 15345.99;
        
        public:
        void updateName(const char* newname);
        void updateBudget(double change);
        bool addProject(Project& newproject);
        void createDepartment(const char* newname, Project& newproject, double change);
        Project* fetchProjects() const;
        int fetchNumProjects() const;
        double fetchBudget() const;
        char* fetchName() const;
        double totalexpenses();
        double remainingBudget();
        void clearDepartment();
    };
    
    //helper functions - do not belong inside the class
    void display(const Project& project);
    void display(const Department& department);
}
#endif // !SDDS_DEPARTMENT_H_
