//Given an array nums of size n, return the majority element.
//The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        //to keep track count of the element e.g key is set to an element e.g. 3
        int key ;
        for(int i=0;i<n;i++){
            if(count == 0){
                count = 1;
                key = nums[i];
            }
            else if(nums[i]==key){
                count++;
            }
            else{
                count--;
            }
        }
        int count1 = 0;
        for(int i=0;i<n;i++){
            if(nums[i]==key) count1++;
        }
        if(count1 > n/2){
            return key;
        }
        return -1;
    }
};
