#ifndef WORDLIST_H
#define WORDLIST_H

#include <unordered_map>
#include <vector>

using namespace std;

class WordList {
private:
    unordered_map<string, string> dictionary;

    vector<string> list;

public:
    WordList();
    
    ~WordList();

    void LoadData(string fileName);

    string FindWordById(string id);

    string FindWordByIndex(int index);
};

#endif