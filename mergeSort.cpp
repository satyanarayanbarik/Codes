
/*class Solution
{
    public:
    void merge(int arr[], int l, int m, int r)
    {
         // Your code here
         vector<int> temp;
         int low = l;
         int high = m+1;
         //int mid = m ;
         while(low<=m && high <= r){
             if(arr[low]<=arr[high]){
                 temp.push_back(arr[low]);
                 low++;
             }
             else{
                 temp.push_back(arr[high]);
                 high++;
             }
         }
         while(low<=m){
             temp.push_back(arr[low]);
             low++;
         }
         while(high<=r){
             temp.push_back(arr[high]);
             low++;
         }
         for(int i=low;i<=high;i++){
             arr[i]=temp[i-low];
         }
         
         
         
    }
    public:
    void mergeSort(int arr[], int l, int r)
    {
        //code here
        int m = (l+r)/2;
        if(l>=r) return;
        mergeSort( arr,l,m);
        mergeSort( arr,m+1,r);
        mergeSort( arr,l,m,r);
    }
}; */
#include <vector>
using namespace std;

class Solution
{
    public:
    void merge(int arr[], int l, int m, int r)
    {
        vector<int> temp;
        int low = l;
        int high = m + 1;
        
        // Merge two sorted subarrays into temp
        while (low <= m && high <= r) {
            if (arr[low] <= arr[high]) {
                temp.push_back(arr[low]);
                low++;
            } else {
                temp.push_back(arr[high]);
                high++;
            }
        }
        
        // Copy remaining elements of the left subarray
        while (low <= m) {
            temp.push_back(arr[low]);
            low++;
        }
        
        // Copy remaining elements of the right subarray
        while (high <= r) {
            temp.push_back(arr[high]);
            high++;
        }
        
        // Copy the merged elements back to the original array
        for (int i = l; i <= r; i++) {
            arr[i] = temp[i - l];
        }
    }

    public:
    void mergeSort(int arr[], int l, int r)
    {
        if (l >= r) return;
        
        int m = l + (r - l) / 2;  // Calculate the middle index

        // Recursively sort both halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        
        // Merge the sorted halves
        merge(arr, l, m, r);
    }
};