#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string removeOccurrences(string s, string part) {
        // Continuously remove all occurrences of "part" in "s"
        while (s.length() != 0 && s.find(part) < s.length()) {
            s.erase(s.find(part), part.length());
        }
        return s;
    }
};

int main() {
    Solution solution;

    // Test Cases
    string s1 = "daabcbaabcbc";
    string part1 = "abc";

    string s2 = "axxxxyyyyb";
    string part2 = "xy";

    string s3 = "aaaa";
    string part3 = "aa";

    // Test outputs
    cout << "Test Case 1: \"" << solution.removeOccurrences(s1, part1) << "\"" << endl; // Expected: "dab"
    cout << "Test Case 2: \"" << solution.removeOccurrences(s2, part2) << "\"" << endl; // Expected: "ab"
    cout << "Test Case 3: \"" << solution.removeOccurrences(s3, part3) << "\"" << endl; // Expected: ""

    return 0;
}
