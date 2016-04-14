#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    /**
     * @param n a positive integer
     * @param primes the given prime list
     * @return the nth super ugly number
     */
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        // Write your code here
        vector<int> result(n);
        vector<int> position(primes.size(), 0);
        int idx = 0;
        result[idx++] = 1;

        while (idx < n) {
            int minNum = INT_MAX;
            for (int i = 0; i < primes.size(); i ++) {
                //cout << "result[position[i]]:" << result[position[i]] << endl;
                minNum = min(primes[i] * result[position[i]], minNum);
            }
            for (int i = 0; i < primes.size(); i ++) {
                if (primes[i] * result[position[i]] == minNum)
                    position[i]++;
            }
            //cout << minNum << endl;
            result[idx++] = minNum;
        }

        return result[n-1];
    }
};

int main() {
    Solution s;
    vector<int> primes = {2, 7, 13, 19};
    cout << s.nthSuperUglyNumber(6, primes) << endl;
    return 0;
}
