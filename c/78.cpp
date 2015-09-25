#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
private:
    void find(vector<vector<int> > &ret, vector<int> &nums, vector<int> tmp, int pos){
        if(pos == nums.size()) {
            ret.push_back(tmp);
            return;
        }
        find(ret, nums, tmp, pos+1);
        tmp.push_back(nums[pos]);
        find(ret, nums, tmp, pos+1);

        return;
    }

public:
    vector<vector<int> > subsets(vector<int>& nums) {
        vector<vector<int> > ret;
        vector<int> tmp;
        sort(nums.begin(), nums.end(), greater<int>());

        find(ret, nums, tmp, 0);

        return ret;
    }
};

int main() {
    vector<int> nums;
    nums.push_back(-1);
    nums.push_back(2);
    nums.push_back(1);
    nums.push_back(-4);
    Solution s;

    vector<vector<int> > ret = s.subsets(nums);

    for(int i = 0; i < ret.size(); i ++) {
        for(int j = 0; j < ret[i].size(); j ++) {
            cout << ret[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}
