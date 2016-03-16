#include <iostream>
#include <vector>
#include <algorithm>

/**
 * 4. Median of Two Sorted Arrays
 */

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size(), n2=nums2.size();
        int count=n1+n2;
        /** odd-length **/
        if(count&0x1) 
            return help(nums1, 0, n1, nums2, 0, n2, count/2+1);
        /** even-length **/
        else
            return (help(nums1, 0, n1, nums2, 0, n2, count/2+1)+help(nums1, 0, n1, nums2, 0, n2, count/2)) / 2.0;

    }

    int help(vector<int>& nums1, int s1, int e1, vector<int>& nums2, int s2, int e2, int k){
        int m=e1-s1, n=e2-s2;
        if(m>n)  return help(nums2, s2, e2, nums1, s1, e1, k);
        if(m==0)  return nums2[s2+k-1];
        if(k==1)  return min(nums1[s1], nums2[s2]);

        int t1 = min(k/2, m), t2 = k - t1;
        if (nums1[s1 + t1 - 1] > nums2[s2 + t2 - 1]) {
            return help(nums1, s1, e1, nums2, s2 + t2, e2, k - t2);
        }
        else if (nums1[s1 + t1 - 1] < nums2[s2 + t2 - 1]) {
            return help(nums1, s1 + t1, e1, nums2, s2, e2, k - t1);
        }
        else {
            return nums1[s1 + t1 - 1];
        }
    }
};

int main() {
    Solution s;
    vector<int> num1 = {1, 2};
    vector<int> num2 = {1, 2};
    cout << s.findMedianSortedArrays(num1, num2) << endl;
    return 0;
}