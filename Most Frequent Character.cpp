//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    //Function to find the maximum occurring character in a string.
    char getMaxOccuringChar(string str)
    {
        // Your code here
        char arr1[26] = {0};
        int n = str.length();
        
        for(int i=0;i<n;i++){
            char ch = str[i];
            int number = 0;
            if(ch >= 'a' && ch<='z'){
                number = ch - 'a';
            }
            arr1[number]++;
        }
        
        int maxi = -1;
        int ans = 0;
        for(int i=0;i<26;i++){
            if(maxi < arr1[i]){
                ans = i;
                maxi = arr1[i];
            }
        }
        
        return 'a'+ ans;
    }
};

//{ Driver Code Starts.

int main()
{
   
    int t;
    cin >> t;
    while(t--)
    {
        string str;
        cin >> str;
    	Solution obj;
        cout<< obj.getMaxOccuringChar(str)<<endl;
    
cout << "~" << "\n";
}
}
// } Driver Code Ends