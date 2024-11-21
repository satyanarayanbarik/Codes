#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool valid(char ch){
        if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')){
            return 1;
        }else{
            return 0;
        }
    }
    char lowerCase(char ch){
        if(ch >= 'a' && ch <= 'z' || ch >= '0' && ch <= '9'){
            return ch;
        }else{
            char temp = ch - 'A' + 'a' ;
            return temp;
        }
    } 
    bool checkPalindrome(string& s) {
        int n = s.size();
        int start = 0;
        int end = n - 1;
        while(start < end){
            if(s[start] != s[end]){
                return false;
            }else{
                start++;
                end--;
            }   
        }
        return true;
    }
    bool isPalindrome(string s) {
      string temp =  "";
      
      // removing non-alphanumeric characters
      for(int j = 0;j < s.size() ; j++ ){
        if(valid(s[j])){
            temp.push_back(s[j]);
        }
      }  
      // converting to lower-case

      for(int j = 0; j<temp.size();j++){
        temp[j] = lowerCase(temp[j]);
      }

     // checking for palindrome 
      return checkPalindrome(temp);
    }
};

#include <iostream>
#include <string>
using namespace std;

int main() {
    Solution sol;

    // Test cases
    string test1 = "race a car";
    string test2 = "A man, a plan, a canal: Panama";
    string test3 = " ";
    string test4 = "abba";
    string test5 = "No 'x' in Nixon";

    // Test and display results
    cout << "Test Case 1: \"" << test1 << "\" -> " << (sol.isPalindrome(test1) ? "true" : "false") << endl;
    cout << "Test Case 2: \"" << test2 << "\" -> " << (sol.isPalindrome(test2) ? "true" : "false") << endl;
    cout << "Test Case 3: \"" << test3 << "\" -> " << (sol.isPalindrome(test3) ? "true" : "false") << endl;
    cout << "Test Case 4: \"" << test4 << "\" -> " << (sol.isPalindrome(test4) ? "true" : "false") << endl;
    cout << "Test Case 5: \"" << test5 << "\" -> " << (sol.isPalindrome(test5) ? "true" : "false") << endl;

    return 0;
}
