/**
 * Author: Zachary Pranske
 * Assignment Title: directory.h
 * Assignment Description: 
 * Due Date: 11/17/2018
 * Date Created: 11/17/2018
 * Date Last Modified: 11/17/2018
 */

#include "Bucket.h"

class Directory {
    int treeDepth, bucketSize, numBuckets;
    vector<Bucket*> buckets;
    //int hx(string word);
    void grow();
    void shrink();
    void split(int bucket);
    void merge(int bucket);
    string bucketID(int bucket);
public:
    int hx(string word);    //Make private when done
    Directory();
    Directory (int numBuckets);
    void setNumBuckets(int n);
    void insert(int key, string word);
    void remove(int key, string word);
    int searchDirectory(string word);
    void display(ostream& out);
};

Directory::Directory() {
    this->treeDepth = 0;
    this->bucketSize = 0;
    this->numBuckets = 0;
}

Directory::Directory (int numBuckets) {
    this->numBuckets = numBuckets;
}

void Directory::setNumBuckets(int n) {
    this->numBuckets = n;
};

int Directory::hx(string word) {
    int intvalue = 0;
    for (int i=0; i<word.length(); i++) {
        intvalue += word[i] - 96;
    }
    cout << word << " hashes to " << intvalue % 64 << endl;
    return intvalue % 64;
}

void Directory::grow() {
    /*for (int i=0; i<treeDepth; i++) {
        buckets.push_back(buckets[i]);
    }
    treeDepth++;*/
}

void Directory::shrink() {
    /*int i;
    bool flag = true;
    for (i=0; i<numBuckets; i++) {
        if (buckets[i]->getDepth()== treeDepth) {
            flag = false;
            return;
        }
    }
    treeDepth--;
    for (i=0; i< treeDepth; i++) {
        buckets.pop_back();
    }*/
}

void Directory::insert(int key, string word) {
    if (key>numBuckets) {
        cout << "No bucket with that key exists!\n";
        return;
    }
    buckets[key]->insert(word);
}

void Directory::remove(int key, string word) {
    buckets[key]->remove(word);
}

int Directory::searchDirectory(string word) {
    for (int i = 0; i < numBuckets; i++) {
        if (buckets[i]->search(word))
            return i;
    }
    return -1;
}

void Directory::display(ostream& out) {
    for (int i = 0; i < numBuckets; i++) {
        cout << "Bucket " << i << " ";
        buckets[i]->display(out);
    }
}



#ifndef STRING_HASH_DIRECTORY_H
#define STRING_HASH_DIRECTORY_H

#endif //STRING_HASH_DIRECTORY_H
