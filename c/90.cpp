/**
 * 90. Subsets II
 */

class Solution {
public:
    void dfs(vector<vector<int>> &res, vector<int>& pre, vector<int>&nums, int k) {
        if (k>=nums.size()) return;
        for (int i=k;i<nums.size();i++) {
            if (nums[i]!=nums[i-1] || i==k) {
                pre.push_back(nums[i]);
                res.push_back(pre);
                dfs(res,pre,nums,i+1);
                pre.pop_back();
            }
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        vector<int> pre;
        res.push_back(pre);
        dfs(res,pre,nums,0);
        return res;
    }
};