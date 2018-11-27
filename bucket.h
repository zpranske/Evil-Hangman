/**
 * Author: Zachary Pranske
 * Assignment Title: bucket.h
 * Assignment Description: 
 * Due Date: 11/17/2018
 * Date Created: 11/17/2018
 * Date Last Modified: 11/17/2018
 */

#ifndef STRING_HASH_BUCKET_H
#define STRING_HASH_BUCKET_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include "bucket.h"

using namespace std;

class Bucket {
    int depth, size;
    vector<string> words;
public:
    Bucket();
    Bucket (int depth, int size);
    void insert (string word);
    void remove (string word);
    bool search(string word);
    bool isEmpty();
    int getDepth();
    //int increaseDepth();
    //int decreaseDepth();
    vector<string> copy();
    void display(ostream& out);
};

Bucket::Bucket() {
    this->depth = 0;
    this->size = 1;
}

Bucket::Bucket(int depth, int size) {
    this->depth = depth;
    this->size = size;
}

void Bucket::insert (string word) {
    words.push_back(word);
    this->size++;
}

void Bucket::remove(string word) {
    for (int i = 0; i < size; i++) {
        if (words[i] == word) {
            words.erase(words.begin()+i);
            this->size--;
        }
    }
}

bool Bucket::search(string word) {
    for (int i = 0; i < size; i++) {
        if (words[i] == word) {
            return true;
        }
    }
    return false;
}

bool Bucket::isEmpty() {
    return this->size == 0;
}

int Bucket::getDepth() {
    return this->depth;
}

vector<string> Bucket::copy() {
    vector<string> newString;
    for (int i = 0; i < size; i++) {
        newString.push_back(words[i]);
    }
    return newString;
}

void Bucket::display(ostream& out) {
    for (int i = 0; i < size; i++) {
        cout << "position " << i;
        out << words[i] << " ";
    }
    out << endl;
}








#endif //STRING_HASH_BUCKET_H
