#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void find(vector<vector<int>> &result, vector<int> &temp, int n, int k, int i) {
        // cout << i << endl;
        // cout << temp.size() << endl;
        // cout << k << endl;
        // cout << "---" << endl;
        if (temp.size() == k) {
            result.push_back(temp);
            return;
        }
            
        if (i > n)
            return;
        
        temp.push_back(i);
        find(result, temp, n, k, i+1);
        temp.pop_back();
        find(result, temp, n, k, i+1);
        
        return;
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> temp;
        find(result, temp, n, k, 1);
        return result;
    }
};

int main() {
	Solution s;
	// cout << s.combine(1, 1) << endl;
	for (auto l : s.combine(1, 1)) {
		for (auto n : l) {
			cout << n << " ";
		}
		cout << endl;
	}


	return 0;

}