//Given an m x n matrix, return all elements of the matrix in spiral order.
/*class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int n =  matrix.size();
        int m = matrix[0].size();
        int top = 0,right = m-1;
        int left = 0,bottom = n-1;

        while(top <= bottom || left <= right){
            for(int i=left;i<=right;i++){
            ans.push_back( matrix[top][i]);
            
            }
            top++;
            for(int i=top;i<=bottom;i++){
                ans.push_back( matrix[i][right]);
                
            }
            right--;
            if(top<=bottom){
                    for(int i=right;i>=left;i--){
                    ans.push_back( matrix[bottom][i]);
                }
                bottom--;
            }
            if(left <= right){
                    for(int i=bottom;i>=top;i--){
                    ans.push_back( matrix[i][left]);
                }
                left++ ;
            }
        }
        return ans;
    }
}; */
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int n = matrix.size();         // Number of rows
        int m = matrix[0].size();      // Number of columns
        int top = 0, bottom = n - 1;
        int left = 0, right = m - 1;

        // Loop until the boundaries overlap
        while (top <= bottom && left <= right) {
            // Traverse from left to right on the top row
            for (int i = left; i <= right; i++) {
                ans.push_back(matrix[top][i]);
            }
            top++;  // Move the top boundary down

            // Traverse from top to bottom on the right column
            for (int i = top; i <= bottom; i++) {
                ans.push_back(matrix[i][right]);
            }
            right--;  // Move the right boundary left

            // Traverse from right to left on the bottom row (if still within bounds)
            if (top <= bottom) {
                for (int i = right; i >= left; i--) {
                    ans.push_back(matrix[bottom][i]);
                }
                bottom--;  // Move the bottom boundary up
            }

            // Traverse from bottom to top on the left column (if still within bounds)
            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    ans.push_back(matrix[i][left]);
                }
                left++;  // Move the left boundary right
            }
        }

        return ans;
    }
};