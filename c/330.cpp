/**
 * 330. Patching Array
 * https://leetcode.com/problems/patching-array/
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minPatches(vector<int>& nums, int n) {

	    int len = nums.size();
	    int sum = 0;
	    int patch = 0;
	    int count = 0;

	    while (sum < n) {
	        if (count != len && nums[count] <= sum + 1) {
	            sum += nums[count];
	            count ++;
	        }
	        else {
	            patch ++;
	            if (sum > (INT_MAX - 1) / 2) {
	                sum = INT_MAX;
	            }
	            else {
	                sum = sum * 2 + 1;
	            }
	        }
	    }

	    return patch;
	}
};

int main() {
	Solution s;
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(31);
	nums.push_back(33);
	int n = 2147483647;
	cout << s.minPatches(nums, n) << endl;

	return 0;
}