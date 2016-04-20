class Solution {
public:
    /**    
     * @param nums: a vector of integers
     * @return: an integer
     */
    int findMissing(vector<int> &nums) {
        // write your code here
        int result = 0;
        for (int i = 0; i < nums.size(); i ++) {
            result ^= i;
            result ^= nums[i];
        }
        
        // the last index
        result ^= nums.size();
        
        return result;
    }
};
