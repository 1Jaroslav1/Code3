#ifndef WORKER
#define WORKER

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Worker{
private:
    string name, surname, jobPosition;
    int id, salary;
    queue<string> queueList;
public:
    Worker (string Name, string Surname, string JobPosition, int Id, int Salary){
        name = Name;
        surname = Surname;
        jobPosition = JobPosition;
        id = Id;
        salary = Salary;
    }
    Worker (const Worker &w){
        name = w.name;
        surname = w.surname;
        jobPosition = w.jobPosition;
        id = w.id;
        salary = w.salary;
        queueList = w.queueList;
    }

    string get_name();
    void set_name(string newName);
    string get_surname();
    void set_surname(string newSurname);
    string get_jobPosition();
    void set_jobPosition(string newJobPosition);
    int get_id();
    void set_id(int newId);
    int get_salary();
    void set_salary(int newSalary);
    queue<string> get_queueList();
    
    void add_customer(string newCustomer);
    void pop_customer();

    bool operator==(const Worker &w);
    bool operator!=(const Worker &w);
    Worker &operator=(Worker w);

    friend
    ostream& operator<<(ostream &os, const Worker &w);
    // friend
    // istream& operator>>(istream &is, Worker &w);
};

#endif