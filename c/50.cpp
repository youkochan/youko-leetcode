/**
 * Pow(x, n)
 * https://leetcode.com/problems/powx-n/
 */


#include <iostream>

using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        double ret = 1;
        if (x == 0)
            return 0;
        if (n == 0)
            return 1.0;
        if (n < 0) {
            x = 1 / x;
            n = - n;
        }
        while (n > 0) {
            if (n & 1) {
                ret *= x;
            }
            x *= x;
            n >>= 1;
        }
        return ret;
    }
};

int main () {
    Solution s;
    cout << s.myPow(8.84372, -5) << endl;
    return 0;
}