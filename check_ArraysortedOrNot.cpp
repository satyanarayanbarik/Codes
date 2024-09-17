//Check if Array Is Sorted and Rotated
//#include <iostream>
//#include <vector>
//#include <algorithm>


#include <vector>
using namespace std;

class Solution {
public:
    bool check(vector<int>& nums) {
        int count = 0;
        int n = nums.size();

        // Count the number of "descending" points
        for(int i = 1; i < n; i++) {
            if(nums[i-1] > nums[i]) {
                count++;
            }       
        }

        // Check the case where the last element is greater than the first
        if(nums[n-1] > nums[0]) 
            count++;

        // The array is rotated sorted if there's at most one "descending" point
        return count <= 1;
    }
};