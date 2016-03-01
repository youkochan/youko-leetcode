/**
 * 96. Unique Binary Search Trees
 * 给定一个整数 n 返回 1..n 组成的不同的 BST 树的个数
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int f(int n, vector<int> &buff) {
        if (buff[n] != -1) {
            return buff[n];
        }
        if (n == 0) {
            buff[n] = 0;
            return 0;
        }
        if (n == 1) {
            buff[n] = 1;
            return 1;
        }
        int result = 0;
        for (int i = 1; i <= n; i ++) {
            int lc = f(i-1, buff);
            int rc = f(n-i, buff);
            lc = lc ? lc : 1;
            rc = rc ? rc : 1;
            result += lc * rc;
        }
        buff[n] = result;
        return result;
    }

    int numTrees(int n) {
        vector<int> buff(n+1, -1);
        f(n, buff);

        /*
        for (auto i : buff) {
            cout << i << ":";
        }
        cout << endl;*/

        return buff[n];
    }
};

int main() {
    Solution s;
    cout << s.numTrees(2) << endl;


}
