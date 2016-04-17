class Solution {
public:
    void find(int left, int right, string str, set<string> &mset) {
        if (left == 0 && right == 0)
            mset.insert(str);
        if (left != 0)
            find(left-1, right+1, str+'(', mset);
        if (right != 0)
            find(left, right-1, str+')', mset);
    }

    /**
     * @param n n pairs
     * @return All combinations of well-formed parentheses
     */
    vector<string> generateParenthesis(int n) {
        // Write your code here
        
        vector<string> result;
        if (n <= 0)
            return result;
        
        set<string> mset;
        find(n, 0, "", mset);
        
        auto it = mset.begin();
        while (it != mset.end()) {
            result.push_back(*it);
            it ++;
        }
        
        return result;
    }
};
