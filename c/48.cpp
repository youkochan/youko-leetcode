/**
 * 48. Rotate Image
 */

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        if (matrix.size() == 0)
            return;
        int n = matrix.size();
        int n1 = n % 2 ? n / 2 + 1 : n / 2;
        int n2 = n / 2; 
        
        for (int i = 0; i < n2; i ++ ) {
            for (int j = 0; j < n1; j ++) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[n-1-j][i];
                matrix[n-1-j][i] = matrix[n-1-i][n-1-j];
                matrix[n-1-i][n-1-j] = matrix[j][n-1-i];
                matrix[j][n-1-i] = temp;
            }
        }
        return;
    }
};