//Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

//You must do it in place.

//BRUTE FORCE

/*
#include <vector>
using namespace std;

class Solution {
public:
    
    void markRows(vector<vector<int>>& matrix, int n, int m, int i) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] != 0) {  // Only mark non-zero elements
                matrix[i][j] = -1;  // Mark the row with -1
            }
        }
    }

    void markColoumns(vector<vector<int>>& matrix, int n, int m, int j) {
        for (int i = 0; i < n; i++) {
            if (matrix[i][j] != 0) {  // Only mark non-zero elements
                matrix[i][j] = -1;  // Mark the column with -1
            }
        }
    }

    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if (n == 0) return;  // Check for empty matrix
        int m = matrix[0].size();

        // First pass: mark the rows and columns
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 0) {
                    markRows(matrix, n, m, i);  // Mark the row
                    markColoumns(matrix, n, m, j);  // Mark the column
                }
            }
        }

        // Second pass: set the marked positions to 0
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == -1) {
                    matrix[i][j] = 0;  // Set marked positions to 0
                }
            }
        }
    }
};
*/

//BETTER 

