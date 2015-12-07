class Solution {
public:
    bool check(string s1, string s2) {
        int count = 0;
        for (int i = 0; i < s1.size(); i ++) {
            if (s1[i] != s2[i])
                count ++;
        }
        if (count == 1)
            return true;
        else
            return false;
    }

    void search(string midWord, string &endWord, unordered_set<string>& wordList, 
                unordered_set<string>& usedList, int step, int &ret) 
    {
        if (check(midWord, endWord)) {
            if (step + 1 < ret)
                ret = step + 1;
            return;
        }
        unordered_set<string>::iterator it = wordList.begin();
        for (; it != wordList.end(); it ++) {
            if (usedList.find(*it) == usedList.end()) {
                string word = *it;
                if (check(word, midWord)) {
                    usedList.insert(word);
                    search(beginWord, endWord, wordList, usedList, step + 1, ret);
                    usedList.erase(word);
                }
            }
        }
    }

    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
        if (beginWord == endWord)
            return 1;
        int ret = INT_MAX;
        unordered_set<string> usedList;
        search(beginWord, endWord, wordList, usedList, 1, ret);
        if (ret == INT_MAX)
            return 0;
        return ret;
    }
};