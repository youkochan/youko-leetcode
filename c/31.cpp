#include <iostream>
#include <vector>

/**
 * 生成下一个全排列
 */

using namespace std;

class Solution {
private:
    int swap(int &a, int &b) {
        int t = a;
        a = b;
        b = t;
        return a;
    }

public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() == 0 || nums.size() == 1)
            return;
        int i = nums.size() - 1;
        while (nums[i] <= nums[i-1]) {
            i --;
            if (i == 0)
                break;
        }
        // cout << "i:" << i << endl;
        if (i != 0) {
            int pos = nums.size() - 1;
            while (nums[pos] <= nums[i-1] && pos >= i)
                pos --;
            // cout << "pos:" << pos << endl; 
            swap(nums[pos], nums[i-1]);
            // cout << nums[0] << nums[1] << nums[2] << endl;
            int len = nums.size() - i;
            // cout << len << endl;
            for (int j = i; j <= i + len / 2 - 1; j ++) {
                int k = nums.size() - 1 - j + i;
                swap(nums[j], nums[k]);
            }
            
        }
        else {
            for (int j = 0; j <= nums.size() / 2 - 1; j ++) {
                int k = nums.size()-1-j;
                // cout << j << "--" << k << endl;
                swap(nums[j], nums[k]);
            }
        }
    }
};

int main() {
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);

	Solution s;

	s.nextPermutation(v);
    for (int i = 0; i < v.size(); i ++) {
        cout << v[i];
    }
    cout << endl;

    s.nextPermutation(v);
    for (int i = 0; i < v.size(); i ++) {
        cout << v[i];
    }
    cout << endl;

    s.nextPermutation(v);
    for (int i = 0; i < v.size(); i ++) {
        cout << v[i];
    }
    cout << endl;

    s.nextPermutation(v);
    for (int i = 0; i < v.size(); i ++) {
        cout << v[i];
    }
    cout << endl;

	return 0;
}