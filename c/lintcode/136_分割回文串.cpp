class Solution {
public:
    void findResult(string &s,
                    int pos,
                    vector<string> &temp,
                    vector<vector<string>> &results) {
        if (pos == s.size()) {
            results.push_back(temp);
            return;
        }

        bool tag = true;
        // i is len;
        for (int i = 0; pos + i < s.size(); i ++) {
            tag = true;
            int l = pos;
            int r = pos + i;
            while (l <= r) {
                if (s[l] != s[r]) {
                    tag = false;
                    break;
                }
                l ++;
                r --;
            }
            if (tag) {
                temp.push_back(s.substr(pos, i+1));
                findResult(s, pos+i+1, temp, results);
                temp.pop_back();
            }
        }
        return;
    }

    /**
     * @param s: A string
     * @return: A list of lists of string
     */
    vector<vector<string>> partition(string s) {
        // write your code here
        vector<vector<string>> results;
        vector<string> temp;

        findResult(s, 0, temp, results);

        return results;
    }
};
