//Ricardo Hernandez - A00837337
//Last edited: 06/10/24

#ifndef PALINDROMO_HPP
#define PALINDORMO_HPP

#include <string>
#include <vector>

using namespace std;

//Time Complexity: O(n)
string preprocesarCadena(const string &s) {
    if (s.empty()) return "^$";
    string res = "^";
    for (int i = 0; i < s.size(); i++) {
        res += "#" + s.substr(i, 1);
    }
    res += "#$";
    return res;
}

//Time Complexity: O(n)
int* manacher(const string &s) {
    string T = preprocesarCadena(s);
    int n = T.size();
    vector<int> P(n, 0);
    int C = 0, R = 0;

    for (int i = 1; i < n - 1; i++) {
        int i_mirror = 2 * C - i;

        if (R > i) {
            P[i] = min(R - i, P[i_mirror]);
        }

        while (T[i + 1 + P[i]] == T[i - 1 - P[i]]) {  // Adjusted condition
            P[i]++;
        }

        if (i + P[i] > R) {
            C = i;
            R = i + P[i];
        }
    }

    int maxLen = 0;
    int centerIndex = 0;
    for (int i = 1; i < n - 1; i++) {
        if (P[i] > maxLen) {
            maxLen = P[i];
            centerIndex = i;
        }
    }

    int start = (centerIndex - 1 - maxLen) / 2;
    
    int* sol = new int[2];
    sol[0] = start;
    sol[1] = maxLen;

    return sol;
}

//Time Complexity: O(n)
void OutputPalindromo(const string t[3], stringstream &output) {
    int* palindromo;
    output << "==============" << endl;
    output << "Palíndromo más grande:" << endl;
    for (int i = 0; i < 3; i++) {
        palindromo = manacher(t[i]);
        output << "Transmission" << i + 1 << ".txt ==> " << "Posicion: " << palindromo[0] << endl;
        output << t[i].substr(palindromo[0], palindromo[1]) << endl;
        if(i != 2){
            output << "----" << endl;
        } 
    }
}

#endif