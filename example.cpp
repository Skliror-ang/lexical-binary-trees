#include <iostream>
#include <fstream>
#include "lexicaltree.h"
using namespace std;

// paste your lexicon class here

int main() {
    lexicon l;

    ifstream file("inputs.txt");

    if (!file) {
        cout << "Error: could not open inputs.txt" << endl;
        return 1;
    }

    string word;

    while (file >> word) {
        l.insert(word);
    }

    file.close();

   
    cout << endl;
    cout << "The word 'problem' appears " << l.lookup("problem") << " time(s)" << endl;
    cout << "The word 'path' is at depth " << l.depth("path") << endl;

    cout << endl;
    cout << "Replacing 'shortest' with 'longest'..." << endl;
    l.replace("shortest", "longest");

    cout << "Lexicon after replacement:" << endl;
    cout << l.depth("longest") << endl;

    return 0;
}