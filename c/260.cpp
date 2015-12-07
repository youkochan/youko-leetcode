#include <iostream>
#include <vector>
#include <cstdlib>

/**
 * Given an array of numbers nums, 
 * in which exactly two elements appear only once 
 * and all the other elements appear exactly twice. 
 * Find the two elements that appear only once.
 * 
 * For example:
 * Given nums = [1, 2, 1, 3, 2, 5], return [3, 5].
 */

using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> ret;
        if (nums.size() == 0)
        	return ret;
        int num = nums[0];
        int mask = 0x01;
        
        for (int i = 1; i < nums.size(); i ++)
        	num ^= nums[i];
        while (!(num & mask))
        	mask = mask << 1;
        int n1 = 0;
        int n2 = 0;
        for (int i = 0; i < nums.size(); i ++) 
        	nums[i] & mask ? n1 ^= nums[i] : n2 ^= nums[i];
        ret.push_back(n1);
        ret.push_back(n2);
        return ret;
    }
};

int main() {
	vector<int> v;
	v.push_back(1);
	v.push_back(1);
	v.push_back(12);
	v.push_back(12);

	v.push_back(3);
	v.push_back(4);

	Solution s;

	vector<int> ret = s.singleNumber(v);

	for (int i = 0; i < ret.size(); i ++) {
		cout << ret[i] << endl;
	}

	return 0;
}

