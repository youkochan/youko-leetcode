/**
 * 336. Palindrome Pairs
 * Given a list of unique words.
 * Find all pairs of distinct indices (i, j) in the given list,
 * so that the concatenation of the two words, i.e.
 * words[i] + words[j] is a palindrome.
 */


class Solution {
private:
    bool isPalindrome(string &s) {
        if (s.size() == 0)
            return true;
        int lidx = 0;
        int ridx = s.size() - 1;
        while (lidx < ridx) {
            if (s[lidx] != s[ridx])
                return false;
            lidx ++;
            ridx --;
        }
        return true;
    }

public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> results;
        map<string, int> idx_map;
        for (int i = 0; i < words.size(); i ++)
            idx_map[words[i]] = i;
        for (int i = 0; i < words.size(); i ++) {
            if (isPalindrome(words[i]) && idx_map.find("") != idx_map.end() && i != idx_map[""]) {
                vector<int> result;
                result.push_back(i);
                result.push_back(idx_map[""]);
                results.push_back(result);
                result[1] = i;
                result[0] = idx_map[""];
                results.push_back(result);
            }
            string rword = words[i];
            reverse(rword.begin(), rword.end());
            if (idx_map.find(rword) != idx_map.end() && i != idx_map[rword]) {
                vector<int> result;
                result.push_back(i);
                result.push_back(idx_map[rword]);
                results.push_back(result);
            }
            int wlen = words[i].size();
            for (int j = 1; j <= wlen - 1; j ++) {
                string lstr = words[i].substr(0, j);
                string rstr = words[i].substr(j);
                string lrstr = lstr;
                string rrstr = rstr;
                reverse(lrstr.begin(), lrstr.end());
                reverse(rrstr.begin(), rrstr.end());
                if (isPalindrome(lstr) && idx_map.find(rrstr) != idx_map.end()) {
                    vector<int> result;
                    result.push_back(idx_map[rrstr]);
                    result.push_back(i);
                    results.push_back(result);
                }
                if (isPalindrome(rstr) && idx_map.find(lrstr) != idx_map.end()) {
                    vector<int> result;
                    result.push_back(i);
                    result.push_back(idx_map[lrstr]);
                    results.push_back(result);
                }
            }
        }
        return results;
    }
};
