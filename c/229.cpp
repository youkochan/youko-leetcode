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

// 思路就是最多只可能返回两个数字，于是先找出出现最多次数的两个数字
// 再遍历一次，就可以找出出现次数大于 n/3 次的元素。

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> result;
        if (nums.size() == 0)
            return result;
        if (nums.size() == 1)
            return nums;

        int count1 = 1;
        int count2 = 0;
        int num1 = nums[0];
        int num2 = 0;
        for (int i = 1; i <= nums.size() - 1; i ++) {
            if (count1 && nums[i] == num1)
                count1 ++;
            else if (count2 && nums[i] == num2)
                count2 ++;
            else if (!count1) {
                count1 = 1;
                num1 = nums[i];
            }
            else if(!count2){
                count2 = 1;
                num2 = nums[i];
            }
            else {
                count1 --;
                count2 --;
            }
        }

        int total1 = 0;
        int total2 = 0;
        for (int i = 0; i <= nums.size() - 1; i ++) {
            if (count1 && nums[i] == num1)
                total1 ++;
            if (count2 && nums[i] == num2)
                total2 ++;
        }

        if (total1 > nums.size() / 3)
            result.push_back(num1);
        if (total2 > nums.size() / 3)
            result.push_back(num2);
        return result;
    }
};
