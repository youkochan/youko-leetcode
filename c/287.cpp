/**
Find the Duplicate Number

Given an array nums containing n + 1 integers
where each integer is between 1 and n (inclusive),
prove that at least one duplicate element must exist.
Assume that there is only one duplicate number,
find the duplicate one.

Note:
You must not modify the array (assume the array is read only).
You must use only constant extra space.
Your runtime complexity should be less than O(n2).

*/

/**
������Ԫ�ص�ֵ������һ��Ԫ���±�Ļ������±�Ϊ0�����ֿ�ʼ
�������һ���������������ظ�Ԫ�س��֣���������ڻ���
��˿���ʹ������ָ�룬һ��ÿ���ƶ�������һ��ÿ���ƶ�һ����
����ָ��׷����ָ��ʱ������ָ���ƶ����ʼ����ÿ���ƶ�һ����

����֤��������ָ����ٴ��ڻ���ʼ�ĵط�������

���ڻ���ʼ��λ����ζ�������������ڵ�ָ�򻷿�ʼ�Ľڵ㣬��ˣ�
����ʼ��λ�õ�ֵ��Ϊ�ظ�ֵ��

֤�����£�������ʼ������ʼ��λ����Ҫ�Ĳ���Ϊm��
�ӻ���ʼ��λ�õ���ָ��׷����ָ���λ����Ҫ�Ĳ���Ϊn��
����ָ��һ������m+n������ָ������2m+2n����
��˵����ָ���������������ǰ��m+n���Ļ��϶��ܻص������㣬
��˵����ָ���������������ǰ��m���Ļ��϶��ص��˻���ʼ��λ��
����Ϊ�ӿ�ʼλ������n���͵��������㣩
��������ͷ�ߵ�����ʼλ��Ҳ��Ҫm��������һ����ָ����ڻ���ʼ��������

*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0;
        int fast = 0;
        while (true) {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if (slow == fast)
                break;
        }
        fast = 0;
        while (true) {
            slow = nums[slow];
            fast = nums[fast];
            if (slow == fast)
                return slow;
        }
    }
};

int main() {
    Solution s;
    vector<int> v;

    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(4);

    cout << s.findDuplicate(v) << endl;

    return 0;
}
