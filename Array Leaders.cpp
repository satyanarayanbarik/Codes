/*Given an array arr of n positive integers, your task is to find all the leaders in the array. 
An element of the array is considered a leader if it is greater than all the elements on its right side or if
 it is equal to the maximum element on its right side. 
The rightmost element is always a leader.*/

//{ Driver Code Starts
// C++ program to remove recurring digits from
// a given number
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    vector<int> leaders(int n, int arr[]) {
        vector<int> ans;
        int leader = INT_MIN;

        // Traverse the array from the end to find leaders
        for(int i = n - 1; i >= 0; i--) {
            if(arr[i] >= leader) {
                ans.push_back(arr[i]);
                leader = arr[i];
            }
        }

        // Since we are traversing from right to left, reverse the answer to get the leaders in original order
        reverse(ans.begin(), ans.end());
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    long long t;
    cin >> t; // testcases
    while (t--) {
        long long n;
        cin >> n; // total size of array

        int arr[n];

        // inserting elements in the array
        for (long long i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution obj;
        // calling leaders() function
        vector<int> v = obj.leaders(n, arr);

        // printing elements of the vector
        for (auto it = v.begin(); it != v.end(); it++) {
            cout << *it << " ";
        }

        cout << endl;
    }
}

// } Driver Code Ends