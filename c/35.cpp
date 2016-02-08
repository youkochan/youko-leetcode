#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int size = nums.size();
        if (size == 0)
            return 0;
        
        int l = 0, r = size, p;
        
        while (l < r) {
            p = (l + r) / 2;
            
            if (nums[p] < target) {
                l = p + 1;
            }
            else {
                r = p;
            }

        }

        return l;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1};
    int target = 2;
    cout << s.searchInsert(nums, target) << endl;
    return 0;
}