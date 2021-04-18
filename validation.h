#ifndef VALIDATION
#define VALIDATION

#include <sstream>
#include <iostream>
#include <vector>
using namespace std;

double convertToDouble(string str);
int convertToInt(string str);
bool check_input(const string str, bool isInt);
bool validationActionInput(string action, int lowerNum, int upperNum);
int inputIntVal(string message, string errorMessage);
int inputActionVal(string message, string errorMessage, int lowerNum, int upperNum);
string inputStrVal(string message);
int inputIdVal(vector<int> IDs);

#endif