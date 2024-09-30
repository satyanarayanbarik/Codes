class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        int ans = n;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target)
                return mid;
            if (nums[mid] >= target ) {
                ans = mid;
                high = mid - 1;
                
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};
/*class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n=nums.size();
        int s=0,e=n-1,mid=0;
        while(s<=e)
        {
             mid=(s+e)/2;
            if(nums[mid]==target)
            return mid;

            else if(nums[mid]>target)
            e=mid-1;

            else if(nums[mid]<target)
            s=mid+1;
        }
        
  return s;  }
};*/