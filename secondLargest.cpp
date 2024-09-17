//Given an array arr, return the second largest distinct element from an array. If the second largest element doesn't exist then return -1.
class Solution {
    public:
            // Function returns the second
            // largest elements
        int print2largest(vector<int> &arr) {
                // Code Here
        int largest = arr[0];
        int secondLargest = -1;
        int n = arr.size();
        for(int i=1;i<n;i++){
            if(arr[i]>largest){
                secondLargest = largest;
                largest = arr[i];
            } 
            if(arr[i]<largest && arr[i]>secondLargest){
                        secondLargest = arr[i];
            }
        }
        return secondLargest;
    }
};