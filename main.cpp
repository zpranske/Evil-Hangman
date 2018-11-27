#include "hashmap.h"

void hmInsert(string word);

int main() {

    ifstream in;
    in.open("dict.txt");
    Hashmap hm(in);

    //Open dictionary and read in number of words and longest word length
    cout << hm.getMaxLength() << " " << hm.getNumWords() << endl;

    //Create tier 1 vector, each position holding another vector (tier 2) of Directory pointers (tier 3)
    //Directory** lengthVect[maxLength];
    /*for (int i = 0; i < maxLength; i++) {
        lengthVect[i] = new Directory*[ALPHA_LENGTH]; //New wordVector of length 26, each of which holds a Directory
    }*/

    /*
    for (int i = 0; i < maxLength; i++) {
        for (int j = 0; j < ALPHA_LENGTH; j++) {
            lengthVect[i][j] = new Directory(1, i); //Where i is the word length and j is the character position
        }
    }
     */
    //Now each word length and letter has a Directory of length <wordLength>. Each Directory holds <wordLength>
    //buckets which hold an arbitrary number of words (however many happen to hash there). A Directory is a
    //tier 3 structure.

    /*
    int l = word.length();
    for (int i = 0; i < word.length(); i++) {
        int c = word[i]-97;
        length
    }*/

    hm.insert("hello");
    hm.print(cout);

    //cout << count;
    return 0;
}


void hmInsert(string word) {
    //
}