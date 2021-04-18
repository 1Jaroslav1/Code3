#ifndef TEST
#define TEST

#include "worker.h"
#include "validation.h"
#include "fileFunctions.h"
#include <utility>

class Test{
    vector<int> IDs = {1242453};
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
};

#endif