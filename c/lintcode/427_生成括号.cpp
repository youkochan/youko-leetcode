class Solution {
public:
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
        mset.insert("()");
        
        while (-- n) {
            set<string> _mset;
            set<string>::iterator it = mset.begin();
            while (it != mset.end()) {
                string _s = *it;
                _mset.insert(_s + "()");
                _mset.insert("()" + _s);
                _mset.insert("(" + _s + ")");
                it ++;
            }
            mset = _mset;
        }
        
        set<string>::iterator it = mset.begin();
        while (it != mset.end()) {
            result.push_back(*it);
            it ++;
        }
        
        return result;
    }
};
