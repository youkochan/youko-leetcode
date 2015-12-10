/**
 * Longest Increasing Subsequence
 * https://leetcode.com/problems/longest-increasing-subsequence/
 * http://www.csie.ntnu.edu.tw/~u91029/LongestIncreasingSubsequence.html
 */

#include <iostream>
#include <vector>
#include <cstdlib>
#include <climits>

using namespace std;

/*解法一，深度优先递归，结果超时*/
/*class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        return f(nums, 0, INT_MIN, 0);
    }

    int f(vector<int> &nums, int pos, int max_num, int len) {
        if (pos == nums.size())
            return len;
        int result1 = 0, result2 = 0;
        if (nums[pos] > max_num) {
            result1 = f(nums, pos+1, nums[pos], len+1);
        }
        result2 = f(nums, pos+1, max_num, len);
        return max(result1, result2);
    }
};*/

/*解法二，lens[j]记录j以前比nums[j]小的数目个数*/
/*class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (!n)
            return 0;
        vector<int> lens(n);
        for (int &len : lens)
            len = 1;
        for (int i = 0; i < n; i ++)
            for (int j = i + 1; j < n; j ++)
                if (nums[j] > nums[i])
                    lens[j] = max(lens[j], lens[i]+1);
        int result = 0;
        for (int len : lens)
            result = max(result, len);
        return result;
    }
};*/

/*解法三，採取 Greedy 策略，以 Binary Search 加速，達到 O(NlogL) ， N 是給定序列的長度， L 是 LIS 的長度。
 *首先要明确 result 数组的长度是只增不减的，
 *在替换过程中有可能找到的结果不是一个LIS
 *但是结果的长度一定是最长子序列的长度*/
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (!n)
            return 0;
        vector<int> result;
        for (int num : nums) {
            if (result.size() == 0)
                result.push_back(num);
            else {
                if (num > result.back()) {
                    result.push_back(num);
                }
                else {
                    *lower_bound(result.begin(), result.end(), num) = num;
                }
            }
            /*for (int r : result) {
                cout << r << " ";
            }
            cout << endl;*/
        }
        return result.size();
    }
};

int main() {
    vector<int> nums = {-7, 10, -9, 2, 3, 8, 8, 1};
    Solution s;
    cout << s.lengthOfLIS(nums) << endl;

    return 0;
}
