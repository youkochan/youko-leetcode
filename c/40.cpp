/**
 * 40. Combination Sum II
 *
 */

class Solution {
public:
    void f(vector<int> &candidates, vector<vector<int>> &result, vector<int> &temp, int target, int sum, int pos) {
        if (sum > target)
            return;
        if (sum == target) {
            result.push_back(temp);
            return;
        }
        if (pos >= candidates.size()) {
            return;
        }

        temp.push_back(candidates[pos]);
        f(candidates, result, temp, target, sum + candidates[pos], pos + 1);
        temp.pop_back();

        pos += 1;
        while (pos < candidates.size() && candidates[pos] == candidates[pos-1]) {
            pos ++;
        }
        f(candidates, result, temp, target, sum, pos);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        f(candidates, result, temp, target, 0, 0);
        return result;
    }
};
