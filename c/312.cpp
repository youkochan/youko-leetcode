/**
 * Burst Balloons
 * https://leetcode.com/problems/burst-balloons/
 */

#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        int **dp = new int*[nums.size()];
        for (int i = 0; i < nums.size(); i ++) {
            dp[i] = new int[nums.size()];
            for (int j = 0; j < nums.size(); j ++) {
                dp[i][j] = 0;
            }
        }
        for (int k = 0; k < nums.size(); k ++) {
            for (int i = 0; i + k < nums.size(); i ++) {
                int j = i + k;
                //cout << "dp[i][j]:" << i << ":" << j << endl;
                int result = INT_MIN;
                for (int m = i; m <= j; m ++) {
                    int left = i == 0 ? 1 : nums[i-1];
                    int right = j == nums.size() - 1 ? 1 : nums[j+1];
                    int left_dp = m == i ? 0 : dp[i][m-1];
                    int right_dp = m == j ? 0 : dp[m+1][j];
                    int temp = nums[m] * left * right + left_dp + right_dp;
                    result = max(result, temp);
                    //cout << left << ":" << right << ":" << left_dp << ":" << right_dp << endl;
                    //cout << "m:" << m << " temp:" << temp << endl;
                }
                dp[i][j] = result;
                //cout << "dp[i][j]:" << i << ":" << j << " is " << dp[i][j] << endl;
            }
        }
        return dp[0][nums.size()-1];
    }
};

int main() {
    vector<int> v;
    v.push_back(3);
    v.push_back(1);
    v.push_back(5);
    v.push_back(8);

    Solution s;
    cout << s.maxCoins(v) << endl;

}
