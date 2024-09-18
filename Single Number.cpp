//Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xOR = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            xOR = xOR^nums[i];
        }
        return xOR;
    }
};