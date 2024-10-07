//Ricardo Hernandez - A00837337
//Last edited: 06/10/24

#ifndef SUBSTRING_HPP
#define SUBSEQUENCE_HPP

#include <string>
#include <vector>

using namespace std;

//Time Complexity: O(len1 * len2)
string LCS(const string &S1, const string &S2) {
    int len1 = S1.length();
    int len2 = S2.length();
    string substring = "";
    vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
    int maxLength = 0;

    for (int i = 1; i <= len1; ++i) {
        for (int j = 1; j <= len2; ++j) {
            if (S1[i - 1] == S2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                maxLength = max(maxLength, dp[i][j]);
                substring = S1.substr(i - maxLength, maxLength);
            }
        }
    }

    return substring;
}

//Time Complexity: O(len1 * len2)
void OutputSubstrings(string t[3], stringstream &output) {
    output << "==============" << endl;
    output << "Los Substring más largos son:" << endl;
    output << "T1-T2 ==> " << LCS(t[0], t[1]) << endl;
    output << "T1-T3 ==> " << LCS(t[0], t[2]) << endl;
    output << "T2-T3 ==> " << LCS(t[1], t[2]) << endl;
}

#endif // SUBSEQUENCE_HPP