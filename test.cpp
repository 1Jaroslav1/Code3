#include "test.h"


vector<int> Test::get_IDs(){
    return IDs;
}

void Test::printIDs(){
    for(long long unsigned int i = 0; i < IDs.size(); i++)
        cout << IDs[i] << endl;
}

vector<Worker> Test::get_workerList(){
    return workerList;
}

void Test::printWorkers(){
    for(long long unsigned int i = 0; i < workerList.size(); i++)
        cout << workerList[i] << "\n\n";
}

void Test::addWorker(Worker newWorker){
    workerList.push_back(newWorker);
}

int Test::testing(){
    enum staringAction{end=0, creatingWorker, deleteWorker, action_with_Worker, coutWorkers, coutIDs, getWorkersFromFile, pushWorkersToFile, workerOperators};
    string actionMessage =  " end the program - 0\n create new worker write - 1\n delete worker - 2\n do some actions with workers write - 3\n print all workers - 4\n print IDs - 5\n get workers from file - 6\n push workers to file - 7\n test operators ==, !=, =: - 8\n Write: ";
    string actionErrorMessage = "Invalid action input!";
    int action = inputActionVal(actionMessage, actionErrorMessage, -1, 9);

    cout << endl;

    switch (action)
    {
    case creatingWorker:{
        Worker w = createWorker();
        addWorker(w);
        break;
    }
    case deleteWorker:{
        printIDs();
        int id = inputIntVal("Write id of worker who you wanna delete: ", "Invalid input");
        popWorker(id);
        break;
    }
    case action_with_Worker:{
        workerActions();
        break;
    }
    case coutWorkers:{
        if(workerList.empty())
            cout << "NO workers";
        else
            printWorkers();
        break;
    }
    case coutIDs:{
        if(IDs.empty())
            cout << "NO workers";
        else
            printIDs();
        break;
    }
    case getWorkersFromFile:{
        readFile("workers.csv");
        break;
    }
    case pushWorkersToFile:{
        writeFile("workers.csv");
        break;
    }
    case workerOperators:{
        testingWorkerOperator();
        break;
    }
    case end:{
        return -1;
        break;
    }
    }
    cout << endl;
    return 1;
}

Worker Test::createWorker(){
    cout << "Creating new worker\n";
    string name, surname, jobPosition;
    int id, salary;
    cout << "Write name of new worker: ";
    cin >> name;
    cout << "Write surname of new worker: ";
    cin >> surname;
    cout << "Write jobPosition of new worker: ";
    cin >> jobPosition;
    salary = inputIntVal("Write salary of new worker: ", "Invalid input! The salary must be positive integer");
    id = inputIdVal(IDs);

    IDs.push_back(id);

    Worker new_w(name, surname, jobPosition, id, salary);
    return new_w;
}

void Test::popWorker(int id){
    if(workerList.empty())
        cout << "No workers" << endl;
    else{
        for(long long unsigned i = 0; i < workerList.size(); i++){
            if(workerList[i].get_id() == id){
                workerList.erase(workerList.begin() + i);
                for(long long unsigned j = 0; j < IDs.size(); j++){
                    if(IDs[j] == id){
                        IDs.erase(IDs.begin() + j);
                    }
                }
            }
        }
    }
}

pair<Worker, int> Test::chooseWorker(){
    cout << "In this shop work:\n";
    printWorkers();
    while(true){
        int id = inputIntVal("Choose worker by id: ", "Invalid input! Id must be positive integer!");

        for(long long unsigned int i = 0; i < workerList.size(); i++){
            if(workerList[i].get_id() == id){
                return make_pair(workerList[i], i);
            }
        }
        cout << "Not such worker with id:" << id << endl;
    }
}

void Test::workerActions(){
    auto workerPair = chooseWorker();
    Worker worker = workerPair.first;

    enum actions{end=0, workerInfo, setName, setSurname, setJobPosition, setSalary, getName, getSurname, getJobPosition, getSalary, getId, getQueue, addCustomer, popCustomer};
    cout << "You in section with working with worker" << endl;
    bool endSection = false;

    while(!endSection){
        string actionMessage = "You can:\n end working with this worker - 0\n info about worker - 1\n\n set name - 2\n set surname - 3\n set jobPosition - 4\n set salary - 5\n\n get name - 6\n get surname - 7\n get jobPosition - 8\n get salary - 9\n get id - 10\n get queue - 11\n\n add customer - 12\n pop customer - 13\n Write: ";
        string actionErrorMessage = "Invalid action input!";
        int action = inputActionVal(actionMessage, actionErrorMessage, -1, 14);
        cout << endl;
        switch (action)
        {
        case workerInfo:{
            cout << worker;
            break;
        }
        case setName:{
            string newName = inputStrVal("Input new Name: ");
            worker.set_name(newName);
            break;
        }
        case setSurname:{
            string newSurname = inputStrVal("Input new Surname: ");
            worker.set_surname(newSurname);
            break;
        }
        case setJobPosition:{
            string newJobPosition = inputStrVal("Input new JobPosition: ");
            worker.set_jobPosition(newJobPosition);
            break;
        }
        case setSalary:{
            int newSalary = inputIntVal("Input new Salary: ", "Invalid salary input");
            worker.set_salary(newSalary);
            break;
        }
        case addCustomer:{
            string customerName = inputStrVal("Write name of customer: ");
            worker.add_customer(customerName);
            break;
        }
        case popCustomer:{
            worker.pop_customer();
            break;
        }
        case end:{
            endSection = true;
            break;
        }
        case getName:{
            cout << worker.get_name() << endl;
            break;
        }
        case getSurname:{
            cout << worker.get_surname() << endl;
            break;
        }
        case getJobPosition:{
            cout << worker.get_jobPosition() << endl;
            break;
        }
        case getSalary:{
            cout << worker.get_salary() << endl;
            break;
        }
        case getId:{
            cout << worker.get_id() << endl;
            break;
        }
        case getQueue:{
            queue<string> new_q = worker.get_queueList();
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

            cout << out << endl;
            break;
        }
        }
        cout << endl;
    }
    // Work operator =
    workerList[workerPair.second] = worker;

    cout << "End working with worker" << "\n\n";
}

void Test::testingWorkerOperator(){
    cout << "Firstly let's create clone of some worker(After ending testing worker operators clon die!!!)\n\n";

    auto workerPair = chooseWorker();
    Worker worker = workerPair.first;
    // Work copy constructor
    Worker clone = worker;

    enum operatorActions{end, equal, notEqual};
    string actionMessage = "You can:\n end working with this section - 0\n check that employee are equal to clone - 1\n check that employee are not equal to clone - 2\n Write: ";
    string actionErrorMessage = "Invalid action input!";
    bool endSection = false;

    while(!endSection){
        int action = inputActionVal(actionMessage, actionErrorMessage, -1, 3);
        cout << endl;
        switch (action)
        {
        case end:{
            endSection = true;
            break;
        }
        case equal:{
            Worker w = chooseWorker().first;
            if(w == clone){
                cout << "True. This worker is the same as a clone" << endl;
            }
            else{
                cout <<  "False. This worker is not the same as a clone" << endl;
            }
            break;
        }
        case notEqual:{
            Worker w = chooseWorker().first;
            if(w != clone){
                cout <<  "True. This worker is not the same as a clone" << endl;
            }
            else{
                cout << "False. This worker is the same as a clone" << endl;
            }
            break;
        }
        default:
            break;
        }
    }

    cout << "End working with section" << "\n\n";
}

void Test::readFile(string file){
    vector<vector<string>> workers = readFromFile(file);
    for(auto worker: workers){
        string name = worker[0];
        string surname = worker[1];
        string jobPosition = worker[2];
        int salary = convertToInt(worker[3]);
        int id = convertToInt(worker[4]);

        IDs.push_back(id);

        Worker w(name, surname, jobPosition, id, salary);
        addWorker(w);
    }
}

void Test::writeFile(string file){
    vector<vector<string>> workers;
    for(auto w: workerList){
        vector<string> worker;
        worker.push_back(w.get_name());
        worker.push_back(w.get_surname());
        worker.push_back(w.get_jobPosition());
        worker.push_back(to_string(w.get_salary()));
        worker.push_back(to_string(w.get_id()));

        workers.push_back(worker);
    }

    writeToFile(file, workers);
}