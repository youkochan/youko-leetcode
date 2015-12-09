/**
 * Additive Number
 * https://leetcode.com/problems/additive-number/
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isAdditiveNumber(string num) {
        vector<int> numbers;    // 已添加的数字，添加之前必须检查是否可以添加。
        int state = 0;          // 刚添加完数字state为0
        int sum = 0;            // 待添加的数字的累加和
        int pos = 0;            // 当前递归执行到的位置
        return f(num, pos, numbers, sum, state);
    }

    bool f(string num, int pos, vector<int> &numbers, int sum, int state) {
        // 终止条件
        int n = numbers.size();
        if (pos == num.size()) {
            if (state == 0 && n >= 3)
                return true;
            else
                return false;
        }

        if (state == 0 && num[pos] == '0') {
            if (n < 2 || sum == numbers[n-1] + numbers[n - 2]) {
                numbers.push_back(0);
                if (f(num, pos+1, numbers, 0, 0))
                    return true;
                numbers.pop_back();

            }
            return false;
        }

        sum = 10 * sum + num[pos] - '0';

        if (n < 2 || sum == numbers[n-1] + numbers[n - 2]) {
            numbers.push_back(sum);
            if (f(num, pos+1, numbers, 0, 0))
                return true;
            numbers.pop_back();
        }
        return f(num, pos+1, numbers, sum, 1);
    }
};

int main() {
    Solution s;
    if (s.isAdditiveNumber("101"))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}
