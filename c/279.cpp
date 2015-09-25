/**
 * Given a positive integer n, find the least number of perfect square numbers 
 * (for example, 1, 4, 9, 16, ...) which sum to n.

For example, 
given n = 12, return 3 because 12 = 4 + 4 + 4; 
given n = 13, return 2 because 13 = 4 + 9.

Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.
 */

/**
 * f(i) = min( f(i - j*j) for all j*j < i )
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <limits>

using namespace std;

class Solution {
public:
    int numSquares(int n) {
    	vector<unsigned int> buf(n+1, 0);
    	for (int i = 1; i <= n; i ++) {
    		buf[i] = INT_MAX;
    		for (int j = 0; j * j <= i; j ++) {
    			buf[i] = min(buf[i], 1 + buf[i - j*j]);
    		}
    	}
    	cout << endl;
    	return buf[n];
    }
};

int main() {
	Solution s;
	cout << s.numSquares(0) << endl;

	return 0;
}