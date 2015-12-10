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

/*�ⷨһ��������ȵݹ飬�����ʱ*/
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

/*�ⷨ����lens[j]��¼j��ǰ��nums[j]С����Ŀ����*/
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

/*�ⷨ������ȡ Greedy ���ԣ��� Binary Search ���٣��_�� O(NlogL) �� N �ǽo�����е��L�ȣ� L �� LIS ���L�ȡ�
 *����Ҫ��ȷ result ����ĳ�����ֻ�������ģ�
 *���滻�������п����ҵ��Ľ������һ��LIS
 *���ǽ���ĳ���һ����������еĳ���*/
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
