//BRUTE FORCE
/*
#include <vector>
using namespace std;

class Solution {
public:
    // Linear search function to check if 'x' exists in the array
    bool linearSearch(vector<int>& nums, int x) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == x) {
                return true;
            }
        }
        return false;
    }

    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return 0; // If the array is empty, return 0

        int longest = 1;

        for (int i = 0; i < n; i++) {
            int x = nums[i]; // Start with the current number
            int count = 1;

            // Keep checking for the next consecutive numbers using linear
            // search
            while (linearSearch(nums, x + 1)) {
                x = x + 1;
                count++; // Increment the count for each consecutive number
            }

            longest = max(longest, count); // Update the longest sequence length
        }

        return longest;
    }
};
*/
//BRUTE FORCE - 2
/*
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
    /*
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
*/

//BETTER 
/*
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int currentCount = 0;
        int lastSmallest = INT_MIN;
        int longest = 0; // Initialize longest as 0
        int n = nums.size();
        
        if (n == 0)
            return 0;  // Return 0 for an empty array

        // Sort the array correctly using vector iterators
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++) {
            if (nums[i] - 1 == lastSmallest) {
                // If current number is consecutive to the previous
                currentCount += 1;
                lastSmallest = nums[i];
            } else if (nums[i] != lastSmallest) {
                // If not consecutive and not a duplicate, reset count
                currentCount = 1;
                lastSmallest = nums[i];
            }
            // Update the longest sequence length
            longest = max(longest, currentCount);
        }

        return longest;
    }
};

*/

//OPTIMAL
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st;
        int ans = 1;

        if(n == 0){
            return 0;
        }

        for(int i=0; i<n; i++){
            st.insert(nums[i]);
        }
        
        for(auto i: st){
            if(st.find(i-1) == st.end()){
                int count = 1;
                int x = i;
                while(st.find(x+1) != st.end()){
                    x++;
                    count++;
                }
                ans = max(ans, count);
            }
        }
        return ans;  
    }
};