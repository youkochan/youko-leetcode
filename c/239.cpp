#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>

/**
��һ��������ά��window�����汣����ܳ�Ϊ���ֵ��Ԫ�ص��±꣬
��nums[i]�Ĵ�С�������С�

������nums[window[0]]�����nums[i]ʱ��˵����ǰ�������������Ԫ�ض������Ϊ���ֵ
���ƣ�����nums[i]ʱ��ɾ����windows�е�nums[windows[j]]��nums[i]С��j���ɡ�

����window����k�����ʱ��ɾ��window[0]
*/

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        vector<int> window;
        if (nums.empty() || k > nums.size())
            return result;
        for (int i = 0; i <= nums.size() - 1; i ++) {
            if (window.empty())
                window.push_back(i);
            else {
                // new value bigger than the max in window
                vector<int>::iterator it = window.begin();
                vector<int> tmp;
                for (it; it != window.end(); it++) {
                    if (nums[*it] > nums[i])
                        tmp.push_back(*it);
                    else
                        break;
                }
                tmp.push_back(i);
                window = tmp;

                if (window.size() > k || i - window[0] >= k) {
                    window = vector<int>(window.begin() + 1, window.end());
                }
            }
            if (i >= k - 1)
                result.push_back(nums[window[0]]);

            /*
            for (vector<int>::iterator it = window.begin(); it != window.end(); it ++) {
                cout << nums[*it] << " ";
            }
            cout << endl;
            */
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<int> v;
    /*
    v.push_back(1);
    v.push_back(3);
    v.push_back(-1);
    v.push_back(-3);
    v.push_back(5);
    v.push_back(3);
    v.push_back(6);
    v.push_back(7);
    */

    v.push_back(7);
    v.push_back(2);
    v.push_back(4);

    vector<int> result = s.maxSlidingWindow(v, 2);
    for(int i = 0; i <= result.size() - 1; i++) {
        cout << result[i] << endl;
    }

    return 0;
}
