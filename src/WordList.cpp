#include "include/WordList.h"
#include <fstream>
#include <sstream> 
#include <iostream>

WordList::WordList(){}

WordList::~WordList(){
    dictionary.clear();
    list.clear();
}

void WordList::LoadData(string fileName) {
    fstream file;
    file.open(fileName, ios::in);

    if (file.is_open()) {
        string line = "", id = "", word = "";

        while (getline(file, line)) {
            istringstream lineStream(line);
            lineStream >> id;
            lineStream >> word;
            
            dictionary.insert(pair<string, string>(id, word));

            list.push_back(word);
        }
    }
    else {
        cerr << "ERROR: Could not open file " + fileName + "." << '\n';
    }
}

string WordList::FindWordById(string id) {
    try
    {
        return dictionary.at(id);
    }
    catch(const std::exception& e)
    {
        cerr << e.what() << '\n';
        return NULL;
    }
}

string WordList::FindWordByIndex(int index) {
    try
    {
        return list.at(index);
    }
    catch(const std::exception& e)
    {
        cerr << e.what() << '\n';
        return NULL;
    }
}