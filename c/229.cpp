/**
Given an integer array of size n,
find all elements that appear more than n/3 times.
The algorithm should run in linear time and in O(1)
space.
*/

#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> result;
        if (nums == nullptr)
            return result;
        if (nums.size() == 1)
            return nums;
        int count1 = 1;
        int count2 = 0;
        int num1 = nums[0];
        int num2 = 0;
        for (int i = 1; i <= nums.size() - 1; i ++) {

        }
    }
};

int main() {

    return 0;
}
