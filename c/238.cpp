/**
Given an array of n integers where n > 1,
nums, return an array output such that output[i]
is equal to the product of all the elements of
nums except nums[i].

Solve it without division and in O(n).

For example, given [1,2,3,4], return [24,12,8,6].
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> tmp;
        int product = 1;
        tmp.push_back(1);
        for (int i = 1; i < nums.size(); i ++) {
            product *= nums[i-1];
            tmp.push_back(product);
        }
        product = 1;
        for (int i = nums.size() - 1; i >= 0; i --) {
            tmp[i] *= product;
            product *= nums[i];
        }

        return tmp;
    }
};

int main() {
    Solution s;
    vector<int> v;

    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);

    vector<int> result = s.productExceptSelf(v);
    for(int i = 0; i <= result.size() - 1; i++) {
        cout << result[i] << endl;
    }

    return 0;
}
