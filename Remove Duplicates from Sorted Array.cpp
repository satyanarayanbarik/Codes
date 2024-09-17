class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        int count = 0;
        vector<int> temp;

        int n = nums.size();
        for(int j=1;j<n;j++){
            if(nums[i]!=nums[j]){
                nums[i+1] = nums[j];
                count++;
                i++;
                
            }
            
        }
        
        return i+1;
        //return j;
        return count;
        
    }
};