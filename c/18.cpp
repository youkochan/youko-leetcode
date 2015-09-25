#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int> > fourSum(vector<int>& nums, int target) {
        vector<vector<int> > ret;
        int idx1 = 0, idx2 = 0, idx3 = 0, idx4 = 0;
        
        sort(nums.begin(), nums.end());
        
        for(; idx1 < nums.size(); idx1 ++) {
            if(idx1 > 0 && nums[idx1] == nums[idx1-1])
                continue;
            for(idx2 = idx1 + 1; idx2 < nums.size(); idx2 ++) {
                if(idx2 > idx1 + 1 && nums[idx2] == nums[idx2-1])
                    continue;
                idx3 = idx2 + 1;
                idx4 = nums.size() - 1;
                
                while(idx3 < idx4) {
                    // cout << idx1 << " " \
                    //      << idx2 << " " \
                    //      << idx3 << " " \
                    //      << idx4 << endl;
                    if(idx3 > idx2 + 1 && nums[idx3] == nums[idx3-1]) {
                        idx3 ++;
                        continue;
                    }
                    int _sum = nums[idx1] + nums[idx2] + nums[idx3] + nums[idx4];
                    if(_sum == target) {
                        vector<int> tmp;
                        tmp.push_back(nums[idx1]);
                        tmp.push_back(nums[idx2]);
                        tmp.push_back(nums[idx3]);
                        tmp.push_back(nums[idx4]);
                        ret.push_back(tmp);
                        idx3 ++;
                    }
                    else if(_sum >target) {
                        idx4 --;
                    }
                    else {
                        idx3 ++;
                    }
                }
            }
        }
        
        return ret;
    }
};

int main() {
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(0);
    nums.push_back(-1);
    nums.push_back(0);
    nums.push_back(-2);
    nums.push_back(2);
    
    Solution s;
    vector<vector<int> > vv = s.fourSum(nums, 0);

    for(int i = 0; i < vv.size(); i ++) {
        for(int j = 0; j < vv[i].size(); j ++)
            cout << vv[i][j] << "\t";
        cout << endl;
    }

    return 0;
}