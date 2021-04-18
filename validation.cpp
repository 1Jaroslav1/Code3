#include "validation.h"

double convertToDouble(string str){
    double x;
    istringstream ss(str);
    ss >> x;
    return x;
}

int convertToInt(string str){
    int x;
    istringstream ss(str);
    ss >> x;
    return x;
}

bool check_input(const string str, bool isInt){
    if(str[0] != '+' && !isdigit(str[0])){
        return false;
    }
    bool is_dot = isInt;
    for(long long unsigned int i = 1; i < str.size(); i++){
        if(str[i] == '.' && !is_dot && isdigit(str[i-1])){
            is_dot = true;
        }
        else if(!isdigit(str[i]))
            return false;
    }
    return true;
}

bool validationActionInput(string action, int lowerNum, int upperNum){
    if(check_input(action, true) && (convertToInt(action) > lowerNum) && (convertToInt(action) < upperNum)){
        return true;
    }
    return false;
}

int inputIntVal(string message, string errorMessage){
    string checkingVal = "";
    int val;
    while(true){
        cout << message;
        cin >> checkingVal;
        if(check_input(checkingVal, true)){
            val = convertToInt(checkingVal);
            return val;
        }
        else{
            cout << errorMessage << endl;
        }
    }
}

int inputActionVal(string message, string errorMessage, int lowerNum, int upperNum){
    string actionStr;
    int action;
    while(true){
        cout << message;
        cin >> actionStr;
        if(validationActionInput(actionStr, lowerNum, upperNum)){
            action = convertToInt(actionStr);
            return action;
        }
        else{
            cout << errorMessage << endl;
        }
    }
}

string inputStrVal(string message){
    string val = "";
    cout << message;
    cin >> val;
    cout << endl;
    return val;
}

int inputIdVal(vector<int> IDs){
    int id;
    bool exit = false;
    while(!exit){
        id = inputIntVal("Write id of new worker: ", "Invalid input! The id must be positive integer");
        exit = true;
        for(long long unsigned i = 0; i < IDs.size(); i++){
            if(id == IDs[i]){
                cout << "ID: " << id << " already exist. Try another one" << endl;
                exit = false;
            }
        }
    }
    return id;
}