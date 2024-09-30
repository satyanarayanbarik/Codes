//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User code template

class Solution {
  public:
    vector<int> getFloorAndCeil(int x, vector<int> &arr) {
        // code here
        // Your code here
            int floor = -1;
        int ceil = -1;
        
        // Traverse through the entire array
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] <= x) {
                // Update floor if it's greater than the current floor
                if (floor == -1 || arr[i] > floor) {
                    floor = arr[i];
                }
            }
            if (arr[i] >= x) {
                // Update ceil if it's smaller than the current ceil
                if (ceil == -1 || arr[i] < ceil) {
                    ceil = arr[i];
                }
            }
        }
        return {floor, ceil};
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore the newline character after t
    while (t--) {
        vector<int> arr;
        int x;
        string input;
        cin >> x;
        cin.ignore();

        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        auto ans = ob.getFloorAndCeil(x, arr);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends