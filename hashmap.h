/**
 * Author: Zachary Pranske
 * Assignment Title: hashmap.h
 * Assignment Description: 
 * Due Date: 11/26/2018
 * Date Created: 11/26/2018
 * Date Last Modified: 11/26/2018
 */

#ifndef STRING_HASH_HASHMAP_H
#define STRING_HASH_HASHMAP_H

#include "directory.h"

const int ALPHA_LENGTH = 26;

class Hashmap {
    int maxLength = 0, numWords = 0;
    Directory** lengthVect;
public:
    Hashmap(ifstream&);
    void getListInfo(ifstream&);
    int getMaxLength() {return maxLength;}
    int getNumWords() {return numWords;}
    void insert(string word);
    void load(ifstream& dict);
    void print(ostream&);
};

Hashmap::Hashmap(ifstream& dict) {
    getListInfo(dict);
    lengthVect = new Directory*[maxLength];
    for (int i = 0; i < maxLength; i++) {
        lengthVect[i] = new Directory[ALPHA_LENGTH]; //New wordVector of length 26, each of which holds a Directory
    }
    //Now each word length and letter has a Directory of length <wordLength>. Each Directory holds <wordLength>
    //buckets which hold an arbitrary number of words (however many happen to hash there). A Directory is a
    //tier 3 structure. See Directory.h
}

void Hashmap::getListInfo(ifstream& dict) {
    if (!dict) {
        cout << "No dictionary found\n";
        return;
    }
    if (!dict.is_open()) {
        dict.open("dict.txt");
    }
    string word;
    while (dict >> word) {
        numWords++;
        if (word.length() > maxLength)
            maxLength = word.length();
    }
    dict.close();
}

void Hashmap::insert(string word) {
    int l = word.length();
    for (int i = 0; i < l; i++) {
        int c = word[i]-97;
        cout << "Inserting at " << l << char(c+97) << endl;
        lengthVect[l][c].insert(i, word);
    }
}

void Hashmap::load(ifstream& dict) {
    if (!dict) {
        cout << "No dictionary found\n";
        return;
    }
    if (!dict.is_open()) {
        dict.open("dict.txt");
    }
    string w;
    while (dict >> w) {
        insert(w);
    }
    dict.close();
}

void Hashmap::print(ostream& out) {
    for (int i = 0; i < maxLength; i++) {
        out << i << " ";
        for (int j = 0; j < ALPHA_LENGTH; j++) {
            out << char(j+97) << " ";
            lengthVect[i][j].display(out);
        }
        out << endl << endl;
    }
    out << endl << endl;
}
#endif //STRING_HASH_HASHMAP_H
