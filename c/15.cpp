#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int>& nums) {
        vector<vector<int> > ret;
        if(nums.size() < 3)
            
            return ret;

        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < nums.size(); i ++)
            cout << nums[i] << "\t";
        cout << endl;

        for(int pos = 0; pos <= nums.size() - 3; pos ++) {
            if(pos > 0 && nums[pos] == nums[pos-1])
                continue;
            
            int l = pos + 1, r = nums.size() - 1;
            while(l < r-1) {
                if(l > pos+1 && nums[l] == nums[l-1]) {
                    l ++;
                    continue;
                }
                if(r < nums.size() && nums[r] == nums[r+1]) {
                    r --;
                    continue;
                }
                
                int _sum = nums[l] + nums[r] + nums[pos];
                if(_sum == 0) {
                    vector<int> tmp;
                    tmp.push_back(nums[pos]);
                    tmp.push_back(nums[l]);
                    tmp.push_back(nums[r]);
                    ret.push_back(tmp);
                }
                else if(_sum > 0) {
                    r --;
                }
                else {
                    l ++;
                }
            }
        }
        
        return ret;
    }
};

int main() {
    vector<int> nums;
    nums.push_back(-1);
    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    Solution s;
    vector<vector<int> > vv = s.threeSum(nums);

    for(int i = 0; i < vv.size(); i ++) {
        for(int j = 0; j < vv[i].size(); j ++)
            cout << vv[i][j] << "\t";
        cout << endl;
    }

    return 0;
}