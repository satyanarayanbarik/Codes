#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    // This function is no longer necessary as we can use an unordered_set for
    // fast lookup
    /*
    bool linearSearch(vector<int>& nums, int x) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == x) {
                return true;
            }
        }
        return false;
    }
    */

    int longestConsecutive(vector<int>& nums) {
        if (nums.empty())
            return 0;

        unordered_set<int> numSet(nums.begin(), nums.end());
        int longest = 0;

        for (int num : numSet) {
            // Check if it is the start of a sequence
            if (numSet.find(num - 1) == numSet.end()) {
                int currentNum = num;
                int currentStreak = 1;

                // Look for the next consecutive numbers
                while (numSet.find(currentNum + 1) != numSet.end()) {
                    currentNum++;
                    currentStreak++;
                }

                longest = max(longest, currentStreak);
            }
        }

        return longest;
    }
};
