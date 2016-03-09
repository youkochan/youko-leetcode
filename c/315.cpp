/**
 * 315. Count of Smaller Numbers After Self
 * https://leetcode.com/problems/count-of-smaller-numbers-after-self/
 */

/*
 * You are given an integer array nums and you have to return a new counts array. 
 * The counts array has the property where counts[i] is the number of smaller elements to the right of nums[i].
 * Example:
 * Given nums = [5, 2, 6, 1]
 * To the right of 5 there are 2 smaller elements (2 and 1).
 * To the right of 2 there is only 1 smaller element (1).
 * To the right of 6 there is 1 smaller element (1).
 * To the right of 1 there is 0 smaller element.
 */

#include <iostream>
#include <vector>

using namespace std;

class MyData {
public:
    MyData(int num, int idx) {
        this->num = num;
        this->cnt = 0;
        this->idx = idx;
    }

    int num;
    int cnt;
    int idx;
};

class Solution {
public:
    void f(vector<MyData>& data, int s, int e) {
        if (s < 0 || e >= data.size())
            return;
        if (s == e)
            return;

        // cout << "s,e: " << s << " " << e << endl;

        vector<MyData> temp;
        int m = (s + e) >> 1;
        int ls = s, le = m;
        int rs = m+1, re = e;

        f(data, ls, le);
        f(data, rs, re);

        // 指针分别指向两个数组的末尾
        int lp = ls, rp = rs;
        // 插入的数字的个数
        int count = e - s + 1;
        while (true) {
            if (data[lp].num <= data[rp].num) {
                temp.push_back(data[lp]);
                lp ++;
                if (lp > le) {
                    while (rp <= re)
                        temp.push_back(data[rp++]);
                    break;
                }
            }
            if (data[lp].num > data[rp].num) {
                // 把lp到le的mydata的 cnt 字段加一
                int pos = lp;
                while (pos <= le) data[pos++].cnt ++;
                temp.push_back(data[rp]);
                rp ++;
                if (rp > re) {
                    while (lp <= le)
                        temp.push_back(data[lp++]);
                    break;
                }
            }
        }

        // cout << "=======" << endl;
        // for (int i = 0; i < temp.size(); i ++){
        //     cout << temp[i].num << " " << temp[i].cnt << " " << temp[i].idx << " " << endl;
        // }
        // cout << "=======" << endl;

        int temp_pos = 0;
        for (int pos = s; pos <= e; pos ++) {
            data[pos] = temp[temp_pos++];
        }

        return;
    }

    vector<int> countSmaller(vector<int>& nums) {
        vector<int> results(nums.size());
        if (nums.size() == 0)
            return results;

        vector<MyData> data;
        for (int i = 0; i < nums.size(); i ++) {
            data.push_back(MyData(nums[i], i));
        }

        f(data, 0, nums.size() - 1);

        for (int i = 0; i < nums.size(); i ++) {
            results[data[i].idx] = data[i].cnt;
        }
        return results;
    }
};

int main() {
    Solution s;
    vector<int> nums = {5, 2, 6, 1};
    vector<int> results = s.countSmaller(nums);
    for (int i : results) {
        cout << i << " ";
    }
    cout << endl;
}
