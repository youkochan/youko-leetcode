#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        if (citations.size() == 0) {
            return 0;
        }
        int i = citations.size() - 1;
        for (; i >= 0; i --) {
            if (citations[i] < citations.size() - i)
                return citations.size() - i - 1;
        }
        return citations.size();
    }
};

int main() {
    Solution s;
    vector<int> v;

    v.push_back(0);
    v.push_back(1);
    v.push_back(3);
    v.push_back(5);
    v.push_back(6);

    cout << s.hIndex(v) << endl;

    return 0;
}
