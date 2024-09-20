//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

#include <unordered_map>
using namespace std;

class Solution {
public:
    int lenOfLongSubarr(int A[], int N, int K) {
        unordered_map<int, int> prefixSumMap;
        int sum = 0;
        int maxLen = 0;

        // Initialize the prefix sum map with 0 sum at index -1
        prefixSumMap[0] = -1;

        for (int i = 0; i < N; i++) {
            // Calculate the cumulative sum
            sum += A[i];

            // Check if there is a prefix sum such that sum - prefix_sum = K
            if (prefixSumMap.find(sum - K) != prefixSumMap.end()) {
                maxLen = max(maxLen, i - prefixSumMap[sum - K]);
            }

            // Only store the first occurrence of a prefix sum
            if (prefixSumMap.find(sum) == prefixSumMap.end()) {
                prefixSumMap[sum] = i;
            }
        }

        return maxLen;
    }
};



//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends