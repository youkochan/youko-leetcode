/**
 * 334. Increasing Triplet Subsequence
 * https://leetcode.com/problems/increasing-triplet-subsequence/
 */

class Solution {
public:
    bool find(vector<int>& nums, int pos, vector<int>& temp) {
        if (temp.size() == 3) {
            return true;
        }
        
        if (pos == nums.size()) {
            return false;
        }
        
        int size = temp.size();
        bool tag = false;
        if (size == 0) {
            temp.push_back(nums[pos]);
            tag |= find(nums, pos+1, temp);
            temp.pop_back();
            if (tag)
                return true;
            else
                return find(nums, pos+1, temp);
        }
        else {
            if (nums[pos] > temp[size-1]) {
                temp.push_back(nums[pos]);
                tag |= find(nums, pos+1, temp);
                temp.pop_back();
                if (tag)
                    return true;
            }
            return find(nums, pos+1, temp);
        }
        
    }

    bool increasingTriplet(vector<int>& nums) {
        vector<int> temp;
        return find(nums, 0, temp);
    }
};