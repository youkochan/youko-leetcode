/**
 * 53. Maximum Subarray
 * https://leetcode.com/problems/maximum-subarray/
 */

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int size = nums.size();
        if (size == 0)
            return 0;
        int sum = 0;
        int max = INT_MIN;
        for (int i = 0; i < size; i ++) {
            sum += nums[i];
            if (sum > max)
                max = sum;
            
            if (sum < 0) {
                sum = 0;
            }
        }
        return max;
    }
};