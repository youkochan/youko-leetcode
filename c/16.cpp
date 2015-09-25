/**
Given an array S of n integers,
find three integers in S
such that the sum is closest to a given number, target.
Return the sum of the three integers.
You may assume that each input would have exactly one solution.
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int bestDif = INT_MAX;
        int bestSum = 0;

        sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size(); i ++) {
            int l = i + 1;
            int r = nums.size() - 1;
            while(l < r){
                int _sum = nums[i] + nums[l] + nums[r];
                int dif = abs(target - _sum);
                if(dif == 0)
                    return _sum;
                if(dif < bestDif) {
                    bestDif = dif;
                    bestSum = _sum;
                }
                if(_sum > target)
                    r --;
                else
                    l ++;
            }
        }
        return bestSum;
    }
};

int main() {
    vector<int> nums;
    nums.push_back(-1);
    nums.push_back(2);
    nums.push_back(1);
    nums.push_back(-4);
    Solution s;

    cout << s.threeSumClosest(nums, 1) << endl;
    return 0;
}
