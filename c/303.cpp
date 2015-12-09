 /**
  * Range Sum Query - Immutable
  * https://leetcode.com/problems/range-sum-query-immutable/
  * easy
  */

#include <iostream>
#include <vector>

using namespace std;

class NumArray {
private:
    vector<int> result;

public:
    NumArray(vector<int> &nums) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i ++) {
            sum += nums[i];
            result.push_back(sum);
        }
    }

    int sumRange(int i, int j) {
        if (i == 0)
            return result[j];
        return result[j] - result[i - 1];
    }
};

int main() {
    vector<int> nums;
    nums.push_back(-2);
    nums.push_back(0);
    nums.push_back(3);
    nums.push_back(-5);
    nums.push_back(2);
    nums.push_back(-1);

    NumArray s(nums);

    cout << s.sumRange(0, 2) << endl;
    cout << s.sumRange(2, 5) << endl;
    cout << s.sumRange(0, 5) << endl;

    return 0;
}
