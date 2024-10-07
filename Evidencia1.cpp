//Ricardo Hernandez - A00837337
//Last edited: 06/10/24

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "Code.h"
#include "Palindromo.h"
#include "Substring.h"

using namespace std;

//Time Complexity: O(n)
void readData(string &t1, string &t2, string &t3, vector<string> &mcode) {
    vector<pair<string, string*>> files = {{"transmission1.txt", &t1}, {"transmission2.txt", &t2}, {"transmission3.txt", &t3}};

    for (const auto &file : files) {
        ifstream infile(file.first);
        string line;
        while (getline(infile, line)) {
            *(file.second) += line;
        }
    }

    ifstream infile("mcode.txt");
    string line;
    while (getline(infile, line)) {
        mcode.push_back(line);
    }
}

int main(){
    stringstream output;
    vector<string> mcode;
    string t[3];

    readData(t[0], t[1], t[2], mcode);

    OutputSubsequences(t, output, mcode);
    OutputPalindromo(t, output);
    OutputSubstrings(t, output);

    ofstream outfile("checking1.txt");
    outfile << output.str();
    outfile.close();

    return 0;
}