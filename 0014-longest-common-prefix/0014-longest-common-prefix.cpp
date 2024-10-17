class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        //strs[0].size() represents the length of the first string in a vector (or array) of strings (strs). This is commonly used to iterate over the characters of the first string.
        //int n = strs.size();
        string res = "";
        for(int i = 0 ; i < strs[0].size(); i++ ){
            for(auto s:strs){
                if(s[i]!=strs[0][i]){
                    return res ;
                }
            }
            res += strs[0][i];
        }
        return res;
    }
};