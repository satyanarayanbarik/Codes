//Given an integer array nums, find the 
/*subarray
 with the largest sum, and return its sum. */
 /*class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int max_i = INT_MIN;
        int start = 0;
        int ansStart = -1;
        int ansEnd = -1;
        int sum = 0;
        for(int i = 0;i<n;i++){
            if(sum==0) start = i;
            sum = sum + nums[i];
            if(sum > max_i){
                max_i = sum;
                ansStart = start,ansEnd = i;
            }
            if(sum < 0){
                sum = 0;
            }
        }
    }
}; */
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int max_i = INT_MIN;  // Variable to store the maximum sum
        int start = 0;        // Variable to store the start index of current subarray
        int ansStart = -1;    // Variable to store the start index of max subarray
        int ansEnd = -1;      // Variable to store the end index of max subarray
        int sum = 0;          // Variable to store the current sum

        for(int i = 0; i < n; i++) {
            if(sum == 0) start = i;  // Update start if the sum is 0
            sum = sum + nums[i];     // Add the current element to sum

            if(sum > max_i) {        // Update max sum and answer indices if current sum is larger
                max_i = sum;
                ansStart = start;
                ansEnd = i;
            }
            
            if(sum < 0) {            // Reset sum if it's negative
                sum = 0;
            }
        }

        return max_i;  // Return the maximum sum of the subarray
    }
};


