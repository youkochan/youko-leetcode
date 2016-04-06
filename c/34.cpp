/**
 * 34. Search for a Range
 */

class Solution {
private:
    int searchLRange(vector<int> &nums, int s, int e, int target) {
        if (s > e)
            return -1;
        int mid = (s + e) / 2;
        if (nums[mid] == target) {
            if (mid == s || nums[mid-1] != target)
                return mid;
            else
                return searchLRange(nums, s, mid-1, target);
        }
        else if (nums[mid] > target)
            return searchLRange(nums, s, mid-1, target);
        else
            return searchLRange(nums, mid+1, e, target);
    }

    int searchRRange(vector<int> &nums, int s, int e, int target) {
        if (s > e)
            return -1;
        int mid = (s + e) / 2;
        if (nums[mid] == target) {
            if (mid == e || nums[mid+1] != target)
                return mid;
            else
                return searchRRange(nums, mid+1, e, target);
        }
        else if (nums[mid] > target)
            return searchRRange(nums, s, mid-1, target);
        else
            return searchRRange(nums, mid+1, e, target);
    }

public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result;
        int n = nums.size();
        int left  = searchLRange(nums, 0, n-1, target);
        int right = searchRRange(nums, 0, n-1, target);
        if (left == -1) {
            result.push_back(-1);
            result.push_back(-1);
            return result;
        }
        result.push_back(left);
        result.push_back(right);

        return result;
    }
};
