/*class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int xor1 = 0,xor2 = 0 ; 
        int sizeofArray = nums.size();
        int n = sizeofArray - 1;
        for(int i=0;i<n;i++){
            xor2 = xor2 ^ nums[i];
            xor1 = xor1 ^ (i+1) ;
        }
        xor1 = xor1 ^ sizeofArray;

        return xor1 ^ xor2;



        

    }
}; */
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int xor1 = 0, xor2 = 0; 
        int n = nums.size();
        
        // XOR all elements in the array
        for (int i = 0; i < n; i++) {
            xor2 ^= nums[i];  // XOR of array elements
            xor1 ^= i;        // XOR of numbers from 0 to n-1
        }

        xor1 ^= n; // Include the number 'n' in xor1
        
        // The missing number is the XOR of xor1 and xor2
        return xor1 ^ xor2;
    }
};