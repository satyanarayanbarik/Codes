//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}


// } Driver Code Ends

#include <bits/stdc++.h>
using namespace std;

// Use the standard library swap
#include <algorithm>

class Solution
{
public:
    // Function to select the minimum element from the unsorted subarray
    int select(int arr[], int i, int n)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        return minIndex;
    }
     
    // Function to perform selection sort
    void selectionSort(int arr[], int n)
    {
        for (int i = 0; i < n - 1; i++) {
            // Get the index of the minimum element
            int minIndex = select(arr, i, n);
            // Swap the minimum element with the element at the current index
            if (minIndex != i) {
                swap(arr[minIndex], arr[i]);
            }
        }
    }
};

// Function to print an array
void printArray(int arr[], int size) 
{ 
    for (int i = 0; i < size; i++) 
        cout << arr[i] << " "; 
    cout << endl; 
}

// Driver program to test the above functions
int main() 
{ 
    Solution solution;
    
    int arr[] = {64, 25, 12, 22, 11}; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    
    solution.selectionSort(arr, n); 
    
    cout << "Sorted array: \n"; 
    printArray(arr, n); 
    
    return 0; 
}





//{ Driver Code Starts.
 
/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
 
// Driver program to test above functions
int main()
{
    int arr[1000],n,T,i;
  
    scanf("%d",&T);
    
    while(T--){
        
    scanf("%d",&n);
    
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
      
    Solution ob;  
    ob.selectionSort(arr, n);
    printArray(arr, n);
    }
    return 0;
}

// } Driver Code Ends