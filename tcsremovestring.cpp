#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

// Function to find the maximum removable substrings using memoization
int maxRemovals(string s, vector<string>& st, unordered_map<string, int>& memo) {
    if (s.empty()) return 0; // Base case: empty string

    // If the result for this string is already computed, return it
    if (memo.find(s) != memo.end()) return memo[s];

    int maxCount = 0;

    // Try to remove each substring in st
    for (const string& word : st) {
        size_t pos = s.find(word);
        if (pos != string::npos) {
            string modifiedString = s;
            modifiedString.erase(pos, word.length()); // Remove the substring
            maxCount = max(maxCount, 1 + maxRemovals(modifiedString, st, memo));
        }
    }

    // Store the result in the map and return it
    memo[s] = maxCount;
    return maxCount;
}

int main() {
    string s = "helloworlds";
    vector<string> temp = {"hd", "el", "llo", "wor", "ell", "lds"};
    unordered_map<string, int> memo;

    int result = maxRemovals(s, temp, memo);
    cout << "Maximum removable substrings: " << result << endl;

    return 0;
}
