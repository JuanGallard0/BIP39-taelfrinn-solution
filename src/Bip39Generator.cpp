#include "include/Bip39Generator.h"
#include <iostream>
#include <sstream>

BIP39Generator::BIP39Generator(string fileName){
    wordList.LoadData(fileName);
    totalWords = 24;
    checksum = 8;
    initialEntropy = totalWords * 11 - checksum;
    finalEntropy = totalWords * 11;
    mnemonic = "";
    hash = "";
}

BIP39Generator::~BIP39Generator(){
    mnemonicArr.clear();
}
    
void BIP39Generator::Run() {
    string id = "", word = "";

    cout << "INPUT:" << endl;
    for (int i = 0; i < totalWords - 1; i++) {
        cin >> id;
        word = wordList.FindWordById(id);
        mnemonicArr.push_back(word);
        mnemonic += word;
    }

    hash = HashSHA256(mnemonic);

    cout << "MNEMONIC: " << mnemonic << endl;
    cout << "HASH: " << hash << endl;
}


string BIP39Generator::HashSHA256(string input) {
    return "hello";
}