//Ricardo Hernandez - A00837337
//Last edited: 06/10/24

#ifndef SUBSEQUENCES_HPP
#define SUBSEQUENCES_HPP

#include <vector>
#include <string>
#include <algorithm>
#include <tuple>
#include <array>
#include <sstream>
#include <iostream>
#include <unordered_set>

using namespace std;

enum class TransmissionFile {
    Transmission1,
    Transmission2,
    Transmission3
};

// Time Complexity: O(1)
string FileName(TransmissionFile file) {
    switch (file) {
        case TransmissionFile::Transmission1:
            return "Transmission1.txt";
        case TransmissionFile::Transmission2:
            return "Transmission2.txt";
        case TransmissionFile::Transmission3:
            return "Transmission3.txt";
        default:
            return "";
    }
}

//Time Complexity: O(len1 * len2)
vector<int> FindSubstring(const string &LS, const string &SS) {
    int len1 = LS.length();
    int len2 = SS.length();
    vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
    vector<int> indexes;
    int maxLength = 0;

    for (int i = 1; i <= len1; ++i) {
        for (int j = 1; j <= len2; ++j) {
            if (LS[i - 1] == SS[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                maxLength = max(maxLength, dp[i][j]);
                if (maxLength == len2) {
                    indexes.push_back(i - maxLength);
                    maxLength = 0;
                }
            }
        }
    }

    return indexes;
}

//Time Complexity: O(n)
vector<string> Subsequences(const string& code) {
    vector<string> subseq;
    unordered_set<string> uniqueSubseq;
    int n = code.size();

    for (int i = 0; i < n; i++) {
        string temp = code;
        temp.erase(i, 1);
        if (uniqueSubseq.find(temp) == uniqueSubseq.end()) {
            subseq.push_back(temp);
            uniqueSubseq.insert(temp);
        }
    }
    
    return subseq;
}

//Time Complexity: O(length1^2 * length2)
pair<string, int> findAllNonContiguousSubsequences(const string& LS, const string& SS) {
    int length1 = LS.length();
    int length2 = SS.length();
    int indexes = 0;

    for (int start = 0; start < length1; ++start) {
        vector<vector<int>> dp(length1 - start + 1, vector<int>(length2 + 1, 0));

        for (int i = 1; i <= length1 - start; ++i) {
            for (int j = 1; j <= length2; ++j) {

                if (LS[start + i - 1] == SS[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }

                if (dp[i][j] == length2) {
                    int row = i;
                    int col = j;
                    while (col > 0) {
                        if (LS[start + row - 1] == SS[col - 1]) {
                            col--;
                        }
                        row--;
                    }
                    indexes++;
                    
                    start += row;
                    i = length1 - start;
                    break;
                }
            }
        }
    }
    return make_pair(SS, indexes);
}

//Time Complexity: O(t * s * findAllNonContiguousSubsequences)
tuple<string, int, TransmissionFile> MostFoundSubs(string t[3], vector<string> subs){
    pair<string, int> aux;
    tuple<string, int, TransmissionFile> result = make_tuple("", 0, TransmissionFile::Transmission1);

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < subs.size(); j++){
            aux = findAllNonContiguousSubsequences(t[i], subs[j]);
            if(aux.second > get<1>(result)){
                result = make_tuple(aux.first, aux.second, static_cast<TransmissionFile>(i));
            }
        }
    }
    return result;
}


//Time Complexity: O(mcode.size() * (3 * FindSubstring + MostFoundSubs + Subsequences))
void OutputSubsequences(string t[3], stringstream& output, vector<string>& mcode){
    tuple<string, int, TransmissionFile> MFS;
    vector<int> indexes;
    string v;

    for(int i = 0; i < mcode.size(); i++){
        output << "Código: " << mcode[i] << endl;
        for(int j = 0; j < 3; j++){
            indexes = FindSubstring(t[j], mcode[i]);
            output << "Transmission" << j + 1 << ".txt" << " ==> " << indexes.size() <<  " veces" << endl;
            for(int k = 0; k < indexes.size(); k++){
                output << indexes[k];
                if(k != indexes.size() - 1){
                    output << ", ";
                }
            }
            if(indexes.size() > 0){
                output << endl;
            }
        }

        MFS = MostFoundSubs(t, Subsequences(mcode[i]));
        output << "La subsecuencia más encontrada es: " << get<0>(MFS) << " con " << get<1>(MFS) << " veces en el archivo " << FileName(get<2>(MFS)) << endl;
        if (i != mcode.size() - 1) {
            output << "--------------" << endl;
        }
    }
}

#endif // SUBSEQUENCES_HPP