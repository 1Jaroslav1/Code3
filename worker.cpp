#include "worker.h"

// GETTERS and SETTERS
//========================================================

string Worker::get_name(){
    return name;
}

void Worker::set_name(string newName){
    name = newName;
}

string Worker::get_surname(){
    return surname;
}

void Worker::set_surname(string newSurname){
    surname = newSurname;
}

string Worker::get_jobPosition(){
    return jobPosition;
}

void Worker::set_jobPosition(string newJobPosition){
    jobPosition = newJobPosition;
}

int Worker::get_id(){
    return id;
}

void Worker::set_id(int newId){
    id = newId;
}

int Worker::get_salary(){
    return salary;
}

void Worker::set_salary(int newSalary){
    salary = newSalary;
}

queue<string> Worker::get_queueList(){
    return queueList;
}

void Worker::add_customer(string newCustomer){
    queueList.push(newCustomer);
}
void Worker::pop_customer(){
    if(!queueList.empty())
        queueList.pop();
    else{
        cout << "No customer" << endl;
    }
}

//======================================================================

bool Worker::operator==(const Worker &w){
    if(w.name == name && w.surname == surname && w.jobPosition == jobPosition && w.id == id && w.salary == salary)
        return true;
    return false;
}
bool Worker::operator!=(const Worker &w){
    if(w.id != id || w.name != name || w.surname != surname || w.jobPosition != jobPosition || w.salary != salary)
        return true;
    return false;
}

Worker &Worker::operator=(Worker other){
    swap(name, other.name);
    swap(surname, other.surname);
    swap(jobPosition, other.jobPosition);
    swap(id, other.id);
    swap(salary, other.salary);
    swap(queueList, other.queueList);
    return *this;
}

ostream& operator<<(ostream &os, const queue<string> &q){
    queue<string> new_q = q;
    string out = "";
    while(new_q.size() > 1){
        out += new_q.front() + ", ";
        new_q.pop();
    }
    if(!new_q.empty())
    {
        out += new_q.front();
        new_q.pop();
    }
    os << out;
    return os;
}

ostream& operator<<(ostream &os, const Worker &w){
    os << "Name: " << w.name << endl;
    os << "Surname: " << w.surname << endl;
    os << "Id: " << w.id << endl;
    os << "jobPosition: " << w.jobPosition << endl;
    os << "Salary: " << w.salary << endl;
    os << "List of customers: " << w.queueList << endl;

    return os;
}

// istream& operator>>(istream &is, Worker &w){
//     cout << "Creating new worker\n";
//     string name, surname, jobPosition;
//     int salary;
//     cout << "Write name of new worker: ";
//     is >> name;
//     cout << "Write surname of new worker: ";
//     is >> surname;
//     cout << "Write jobPosition of new worker: ";
//     is >> jobPosition;
//     salary = inputIntVal("Write salary of new worker: ", "Invalid input! The salary must be positive integer");

//     Worker new_w(name, surname, jobPosition, id, salary);
//     return new_w;
// }