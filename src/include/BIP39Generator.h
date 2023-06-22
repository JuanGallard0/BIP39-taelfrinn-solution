#ifndef BIP39GENERATOR_H
#define BIP39GENERATOR_H

#include "WordList.h"
#include <vector>

using namespace std;

class BIP39Generator {
private:
    WordList wordList;

    int totalWords, checksum, initialEntropy, finalEntropy;

    string mnemonic;

    string hash;

    vector<string> mnemonicArr;

public:
    BIP39Generator(string fileName);

    ~BIP39Generator();

    void Run();

    string HashSHA256(string input);
};

#endif