#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;

class Solution {
public:
    /**
     * @param buildings: A list of lists of integers
     * @return: Find the outline of those buildings
     */
    
    // loc 所有出现过的位置的集合
    set<int> loc;
    // st 对应某一个位置开始的所有大楼的高度
    // en 对用某一个位置结束的所有大楼的高度
    map<int,vector<int>> st, en;
    // 当前存在的所有大楼的高度
    multiset<int> H;
    
    vector<vector<int>> buildingOutline(vector<vector<int>> &buildings) {
        // write your code here
        vector<vector<int>> ret;
        for (auto x : buildings) {
            loc.insert(x[0]);
            loc.insert(x[1]);
            st[x[0]].push_back(x[2]);
            en[x[1]].push_back(x[2]);
        }
        
        int H0 = 0;
        int X0 = 0;
        H.insert(0);
        for (auto X1 : loc) {
            auto H1 = *H.rbegin();
            // 最大高度不为零
            if (H1) {
                if (ret.empty() || H1 != ret[ret.size() - 1][2])
                    ret.push_back(vector<int>{X0,X1,H1});
                else ret[ret.size() - 1][1] = X1;
            }
            for (auto x : st[X1]) H.insert(x);          // 添加在该点开始的大楼
            for (auto x : en[X1]) H.erase(H.find(x));   // 移除在该点结束的大楼
            X0 = X1;
        }
        
        return ret;
    }
};

int main() {
    Solution s;
    vector<vector<int>> buildings = {{1,3,3}, {3,5,3}};
    vector<vector<int>> results = s.buildingOutline(buildings);
    for (auto &result : results) {
        for (auto num : result) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}
