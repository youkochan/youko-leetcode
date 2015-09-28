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
将数组元素的值看作下一个元素下标的话，从下标为0的数字开始
可以组成一个链表，而由于有重复元素出现，则链表存在环。
因此可以使用两个指针，一个每次移动两步，一个每次移动一步，
当快指针追上慢指针时，将快指针移动到最开始，再每次移动一步。

可以证明，两个指针会再次在环开始的地方相遇。

由于环开始的位置意味着至少有两个节点指向环开始的节点，因此，
环开始的位置的值即为重复值。

证明如下，假如从最开始到环开始的位置需要的步数为m，
从环开始的位置到快指针追上慢指针的位置需要的步数为n，
则：慢指针一共走了m+n步，快指针走了2m+2n步，
则说明快指针在相遇点继续往前走m+n步的话肯定能回到相遇点，
则说明快指针在相遇点继续往前走m步的话肯定回到了环开始的位置
（因为从开始位置再走n步就到了相遇点）
而从链表头走到环开始位置也需要m步，即下一次两指针会在环开始处相遇。

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
