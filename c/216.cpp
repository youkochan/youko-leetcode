#include <iostream>
#include <map>
#include <vector>
#include <utility>

using namespace std;

/**
 * Find all possible combinations of k numbers that add up to a number n, 
 * given that only numbers from 1 to 9 can be used 
 * and each combination should be a unique set of numbers.
 * Ensure that numbers within the set are sorted in ascending order.
 *
 * 按深度遍历，需要记录当前数组，当前选择的数字，当前目标剩余多少，当前剩余数字数目。
 */

class Solution {
public:
    void search(int target, int i, int k, vector<vector<int> >&vv, vector<int> &temp){
        if (target < 0)
            return;
        if (k == 0 && target == 0) {
            vv.push_back(temp);
            return;
        }
        if (k == 0) {
            return;
        }

        for (; i <= 9; i ++) {
            temp.push_back(i);
            search(target - i, i + 1, k - 1, vv, temp);
            temp.pop_back();
        }

    }

    vector<vector<int> > combinationSum3(int k, int n) {
        vector<vector<int> > vv;
        vector<int> temp;

        search(n, 1, k, vv, temp);

        return vv;
    }
};

int main() {
    int k = 3;
    int n = 7;
    Solution s;
    vector<vector<int> > ret = s.combinationSum3(k, n);
    for (int i = 0; i < ret.size(); i ++) {
        for (int j = 0; j < ret[i].size(); j ++) {
            cout << ret[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}