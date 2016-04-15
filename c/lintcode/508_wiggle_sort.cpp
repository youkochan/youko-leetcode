class Solution {
public:
    /**
     * @param nums a list of integer
     * @return void
     */
    void wiggleSort(vector<int>& nums) {
        // Write your code here
        if (nums.size() ==  0)
            return;
        vector<int> buff(nums);
        sort(buff.begin(), buff.end());
        int idx1 = 0;
        int idx2 = (nums.size() - 1) / 2 + 1;
        bool flag = true;
        for (int i = 0; i < nums.size(); i ++) {
            nums[i] = flag ? buff[idx1++] : buff[idx2++];
            flag = !flag;
        }
    }
};
