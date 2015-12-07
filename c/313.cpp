/**
 * Write a program to find the nth super ugly number.
 * Super ugly numbers are positive numbers 
 * whose all prime factors are in the given prime list primes of size k. 
 * For example, [1, 2, 4, 7, 8, 13, 14, 16, 19, 26, 28, 32] is the 
 * sequence of the first 12 super ugly numbers given 
 * primes = [2, 7, 13, 19] of size 4.
 * Note:
 * (1) 1 is a super ugly number for any given primes.
 * (2) The given numbers in primes are in ascending order.
 * (3) 0 < k ≤ 100, 0 < n ≤ 106, 0 < primes[i] < 1000.
 */

#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> ugly(1, 1);
        vector<int> index(primes.size(), 0);
        for (int i = 1; i < n; i ++) {
            int min_element = INT_MAX;
            for (int j = 0; j < primes.size(); j ++) {
                min_element = min(min_element, ugly[index[j]] * primes[j]);
            }
            ugly.push_back(min_element);
            for (int j = 0; j < primes.size(); j ++) {
                while (ugly[index[j]] * primes[j] <= ugly[i])
                    index[j] ++;
            }
        }
        return ugly[n-1];
    }
};

int main(int argc, char* argv[])
{
    Solution s;
    vector<int> primes;
    primes.push_back(2);
    primes.push_back(7);
    primes.push_back(13);
    primes.push_back(19);
    cout << s.nthSuperUglyNumber(5, primes) << endl;
    return 0;
}