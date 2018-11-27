/**
 * File: disjointSet.h
 * Author: Zachary Pranske
 * Course: CSI 1440
 * Assignment: 
 * Due date: 11/27/18
 * Date modified: 11/27/18
 *  - file created
 * 
 * Description
 */



#ifndef DISJOINT_SET_DISJOINTSET_H
#define DISJOINT_SET_DISJOINTSET_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

const int MAX = 7;

using namespace std;

class disjointSet{
private:
    vector<int> pset;
public:
    disjointSet() {
        pset.assign(MAX, 0);
    }
    void initSet(int N) {
        for (int i = 0; i < N; i++) {
            pset[i] = i;
        }
    }
    int findSet (int i) {
        if (pset[i] == i) {
            return i;
        }
        else
            return pset[i] = findSet(pset[i]);
    }
    bool isSameSet (int i, int j) {
        return findSet(i) == findSet(j);
    }
    void unionSet (int i, int j) {
        pset[findSet(i)] = findSet(j);
    }
    void printSet (ostream& out) {
        for (int i:pset) {
            out << pset[i] << " ";
        }
        out << endl;
    }
};

#endif //DISJOINT_SET_DISJOINTSET_H
