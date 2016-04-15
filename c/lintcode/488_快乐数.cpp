class Solution {
public:
    /**
     * @param n an integer
     * @return true if this is a happy number or false
     */
    bool isHappy(int n) {
        // Write your code here
        set<int> nums;
        bool flag = true;
        while (n != 1) {
            string s = to_string(n);
            int sum = 0;
            for (char c : s)
                sum += (c - '0') * (c - '0');
            if (nums.find(sum) != nums.end()) {
                flag = false;
                break;
            }
            n = sum;
            nums.insert(n);
        }
        
        return flag;
    }
};
