#ifndef TEST
#define TEST

#include "worker.h"
#include "validation.h"
#include "fileFunctions.h"
#include <utility>

class Test{
    vector<int> IDs;
    vector<Worker> workerList;
public:
    vector<int> get_IDs();
    vector<Worker> get_workerList();
    void printIDs();
    void printWorkers();

    int testing();

    Worker createWorker();
    void addWorker(Worker newWorker);
    void popWorker(int id);
    pair<Worker, int> chooseWorker();

    void workerActions();
    void testingWorkerOperator();
    void readFile(string file);
    void writeFile(string file);
};

#endif