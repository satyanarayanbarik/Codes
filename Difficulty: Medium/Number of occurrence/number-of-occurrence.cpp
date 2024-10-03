//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C+
class Solution{
public:	
    int firstOccurrence(int arr[], int n, int k) {
        int low = 0, high = n - 1;
        int first = -1;
    
        while (low <= high) {
            int mid = (low + high) / 2;
            // maybe an answer
            if (arr[mid] == k) {
                first = mid;
                // look for smaller index on the left
                high = mid - 1;
            }
            else if (arr[mid] < k) {
                low = mid + 1; // look on the right
            }
            else {
                high = mid - 1; // look on the left
            }
        }
        return first;
    }
    
    int lastOccurrence(int arr[], int n, int k) {
        int low = 0, high = n - 1;
        int last = -1;
    
        while (low <= high) {
            int mid = (low + high) / 2;
            // maybe an answer
            if (arr[mid] == k) {
                last = mid;
                // look for larger index on the right
                low = mid + 1;
            }
            else if (arr[mid] < k) {
                low = mid + 1; // look on the right
            }
            else {
                high = mid - 1; // look on the left
            }
        }
        return last;
    }

    pair<int, int> firstAndLastPosition(int arr[], int n, int k) {
        int first = firstOccurrence(arr, n, k);
        if (first == -1) return { -1, -1 };
        int last = lastOccurrence(arr, n, k);
        return {first, last};
    }

	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int count(int arr[], int n, int x) {
	    // use the helper functions
	    pair<int, int> ans = firstAndLastPosition(arr, n, x);
	    if (ans.first == -1) return 0;
	    return ans.second - ans.first + 1;
	}
};




//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends