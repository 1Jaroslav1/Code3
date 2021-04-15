#include "fileFunctions.h"

void writeToFile(string file, vector<vector<string>> data){
    ofstream my_file(file);

    for(auto i: data){
        for(auto elem: i){
            my_file << elem << ' ';
        }
        my_file << '\n';
    }
}

vector<vector<string>> readFromFile(string file){
    ifstream my_file(file);
    string line;
    vector<vector<string>> values;
    while(getline(my_file, line)){
        string line_value;
        vector<string> line_values;
        stringstream ss(line);
        while(getline(ss, line_value, ' ')){
            line_values.push_back(line_value);
        }
        values.push_back(line_values);
    }
    return values;
}