#include <iostream>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int r = matrix.size ();
        if (r == 0)
            return 0;
        int c = matrix[0].size();
        if (c == 0)
            return 0;

        vector<vector<int> > di = vector<vector<int> >(r, vector<int>(c));

        for (int i = 0; i < r; i ++) {
            for (int j = 0; j < c; j ++) {
                int num = matrix[i][j];
                if (i - 1 >= 0 && matrix[i-1][j] < num) di[i][j] ++;
                if (i + 1 <  r && matrix[i+1][j] < num) di[i][j] ++;
                if (j - 1 >= 0 && matrix[i][j-1] < num) di[i][j] ++;
                if (j + 1 <  c && matrix[i][j+1] < num) di[i][j] ++;
            }
        }

        int count = 0;
        int sum = c * r;
        int max_len = 0;
        vector<pair<int, int>> temp;
        while (count < sum) {
            temp.clear();
            for (int i = 0; i < r; i ++) {
                for (int j = 0; j < c; j ++) {
                    if (!di[i][j])
                        temp.push_back(pair<int, int>(i,j));
                }
            }

            max_len ++;

            for (int l = 0; l < temp.size(); l ++) {
                int i = temp[l].first;
                int j = temp[l].second;
                //cout << 'i' << i << " j" << j << endl;
                di[i][j] = -1;
                int num = matrix[i][j];
                if (i - 1 >= 0 && matrix[i-1][j] > num) di[i-1][j] --;
                if (i + 1 <  r && matrix[i+1][j] > num) di[i+1][j] --;
                if (j - 1 >= 0 && matrix[i][j-1] > num) di[i][j-1] --;
                if (j + 1 <  c && matrix[i][j+1] > num) di[i][j+1] --;
            }
            count += temp.size();
        }

        return max_len;
    }
};

int main() {
    Solution s;

    vector<vector<int> > m = {
        {3,4,5},
        {3,2,6},
        {2,2,1}
    };

    cout << s.longestIncreasingPath(m) << endl;

    return 0;
}
