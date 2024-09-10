#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Function to check if the current mapping leads to a valid solution
    bool isValidSolution(string &s1, string &s2, string &s3, unordered_map<char, int> &map) {
        int num1 = 0, num2 = 0, num3 = 0;

        for (char ch : s1) num1 = num1 * 10 + map[ch];
        for (char ch : s2) num2 = num2 * 10 + map[ch];
        for (char ch : s3) num3 = num3 * 10 + map[ch];

        return num1 + num2 == num3;
    }

    // Backtracking function to assign digits to letters
    bool backtrack(vector<char> &letters, unordered_map<char, int> &map, set<int> &usedDigits, string &s1, string &s2, string &s3, int index) {
        if (index == letters.size()) {
            return isValidSolution(s1, s2, s3, map);
        }

        for (int digit = 0; digit <= 9; digit++) {
            if (usedDigits.find(digit) == usedDigits.end()) {
                map[letters[index]] = digit;
                usedDigits.insert(digit);

                if (backtrack(letters, map, usedDigits, s1, s2, s3, index + 1)) {
                    return true;
                }

                // Backtrack
                usedDigits.erase(digit);
            }
        }

        return false;
    }

    // Main function to solve cryptarithmetic puzzles
    bool solveCryptarithmeticPuzzle(string s1, string s2, string s3) {
        unordered_map<char, int> map;
        set<int> usedDigits;
        set<char> uniqueLetters;

        // Extract unique letters
        for (char ch : s1) uniqueLetters.insert(ch);
        for (char ch : s2) uniqueLetters.insert(ch);
        for (char ch : s3) uniqueLetters.insert(ch);

        vector<char> letters(uniqueLetters.begin(), uniqueLetters.end());

        // Start backtracking to assign digits
        return backtrack(letters, map, usedDigits, s1, s2, s3, 0);
    }
};

int main() {
    Solution sol;
    string s1 = "SEND", s2 = "MORE", s3 = "MONEY";

    if (sol.solveCryptarithmeticPuzzle(s1, s2, s3)) {
        cout << "Solution exists!" << endl;
    } else {
        cout << "No solution!" << endl;
    }

    return 0;
}
