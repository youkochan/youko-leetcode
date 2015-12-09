/**
 * Range Sum Query 2D - Immutable
 * https://leetcode.com/problems/range-sum-query-2d-immutable/
 */

/**
 * 解题思路：使用二维数组记录 [0, 0] 到位置 [i, j] 的和。
 */

#include <iostream>
#include <vector>

using namespace std;

class NumMatrix {
private:
    vector<vector<int> > result;

public:
    NumMatrix(vector<vector<int> > &matrix) {
        int r = matrix.size();
        if (!r)
            return;
        int c = matrix[0].size();

        result = vector<vector<int> >(r + 1, vector<int>(c + 1));
        for (int i = 0; i < r; i ++) {
            for (int j = 0; j < c; j ++) {
                if (j == 0)
                    result[i+1][j+1] = result[i][j+1] + matrix[i][j];
                else {
                    result[i+1][j+1] = result[i+1][j] + result[i][j+1] - result[i][j] + matrix[i][j];
                }
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        if (row1 > row2 || col1 > col2)
            return 0;
        return  result[row2+1][col2+1]
                - result[row1][col2+1]
                - result[row2+1][col1]
                + result[row1][col1];
    }
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.sumRegion(1, 2, 3, 4);

int main() {
    int m1[5][5] = {
        {3, 0, 1, 4, 2},
        {5, 6, 3, 2, 1},
        {1, 2, 0, 1, 5},
        {4, 1, 0, 1, 7},
        {1, 0, 3, 0, 5},
    };

    vector<vector<int> > m2(5, vector<int>());
    for (int i = 0; i < 5; i ++)
        for (int j = 0; j < 5; j ++)
            m2[i].push_back(m1[i][j]);

    NumMatrix matrix(m2);
    //cout << matrix.sumRegion(0, 0, 2, 0) << endl;
    cout << matrix.sumRegion(1, 1, 2, 2) << endl;
    cout << matrix.sumRegion(1, 2, 2, 4) << endl;

    return 0;
}
