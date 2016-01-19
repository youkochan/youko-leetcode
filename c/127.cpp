/**
 * 127. Word Ladder
 * https://leetcode.com/problems/word-ladder/
 */

#include<iostream>
#include<unordered_set>
#include<vector>

using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
        if (checkDiff(beginWord, endWord))
            return 2;
        int len = 2;
        vector<string> temp1;
        temp1.push_back(endWord);
        vector<string> temp2;

        while (true) {
            /*
            cout << "Temp1: ";
            for (int i = 0; i < temp1.size(); i ++)
                cout << temp1[i] << " ";
            cout << endl;
            */

            unordered_set<string>::iterator it = wordList.begin();
            for (it; it != wordList.end(); it ++) {
                string s1 = *it;
                for (int i = 0; i <= temp1.size() - 1; i ++) {
                    string s2 = temp1[i];
                    if (checkDiff(s1, s2)) {
                        temp2.push_back(s1);
                        break;
                    }
                }
            }

            /*
            cout << "Temp2: ";
            for (int i = 0; i < temp2.size(); i ++)
                cout << temp2[i] << " ";
            cout << "\n==========" << endl;
            */

            for (int i = 0; i < temp2.size(); i ++) {
                if (checkDiff(temp2[i], beginWord))
                    return len + 1;
            }

            if (temp2.size() == 0) {
                return 0;
            }

            for (int i = 0; i <= temp2.size() - 1; i ++) {
                wordList.erase(temp2[i]);
            }
            temp1 = temp2;
            temp2.clear();
            len ++;
        }

        return 0;
    }

    bool checkDiff(string &s1, string &s2) {
        int diff = 0;
        for (int i = 0; i < s1.size(); i ++) {
            if (s1[i] != s2[i])
                diff ++;
            if (diff > 1)
                return false;
        }
        if (diff == 1)
            return true;
        else
            return false;
    }
};

int main() {
    Solution s;

    string beginWord = "a";
    string endWord = "c";
    unordered_set<string> wordList = {"a","b","c"};

    cout << s.ladderLength(beginWord, endWord, wordList);

    return 0;
}
