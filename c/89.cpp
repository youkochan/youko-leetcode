#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result;
        result.push_back(0);
        if (n <= 0) {
            return result;
        }

        for (int i = 0; i < n; i ++) {
            int flag = 0x01 << i;
            int size = result.size();
            for (int j = size - 1; j >= 0; j --) {
                result.push_back(flag + result[j]);
            }
        }

        return result;
    }
};

int main() {
    Solution s;

    vector<int> v = s.grayCode(3);

    for (int i : v) {
        cout << i << " " << endl;
    }

    return 0;
}
