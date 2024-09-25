//Subarray Sum Equals K


//Brute Force

/* class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        int n = nums.size();
        
        // Iterate over all possible starting points for the subarrays
        for(int i = 0; i < n; i++) {
            int sum = 0; // Initialize sum for each new subarray starting at 'i'
            
            // For each starting point, extend the subarray and check the sum
            for(int j = i; j < n; j++) {
                sum += nums[j]; // Add the current element to the sum
                
                // If the sum equals k, increment the count
                if(sum == k) {
                    count++;
                }
            }
        }
        
        return count;
    }
};  */

// BETTER APPROACH
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int> mpp ;
        mpp[0] = 1;
        int prefixSum = 0, count = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            prefixSum += nums[i];
            int remove = prefixSum - k;
            count += mpp[remove];
            mpp[prefixSum]+=1;
        }
        return count;

    }
};
