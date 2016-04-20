#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * @param s1 A string
     * @param s2 Another string
     * @return whether s2 is a scrambled string of s1
     */
    bool isScramble(string& s1, string& s2) {
        // Write your code here
        if (s1.size() != s2.size())
            return false;
        
        int n = s1.size();
        // dp[i][j][k] means 
        // the (k+1)-len substr in position i of string s1, denote by sub1
        // the (k+1)-len substr in position j of string s2, denote by sub2
        // and isScramble(sub1, sub2) == true
        vector<vector<vector<bool>>> dp(n, vector<vector<bool>>(n, vector<bool>(n, false)));
        
        for (int k = 0; k < n; k ++) {
            for (int i = 0; i + k < n; i ++) {
                for (int j = 0; j + k < n; j ++) {
                    if (k == 0) {
                        dp[i][j][k] = (s1[i] == s2[j]);
                    }
                    else {
                        bool tag = false;
                        for (int t = 0; t < k; t ++) {
                            int lposi = i;          // begin pos of s1's left part
                            int lposj = j;          // begin pos of s2's left part
                            int rposi = i + t + 1;  // begin pos of s1's right part
                            int rposj = j + k - t;  // begin pos of s2's right part
                            if (dp[lposi][rposj][t] && dp[rposi][lposj][k-t-1]) {
                                tag = true;
                                break;
                            }
                            if (dp[i][j][t] && dp[i+t+1][j+t+1][k-t-1]) {
                                tag = true;
                                break;
                            }
                        }
                        dp[i][j][k] = tag;
                    }
                    //cout << "i:j:k: " << i << " " << j << " " << k << " ";
                    //cout << (dp[i][j][k] ? "YES" : "NO") << endl;
                }
            }
        }
        
        return dp[0][0][n-1];
    }
};

int main(int argc, char const *argv[]) {
    /* code */
    string s1 = "abc", s2 = "cab";
    Solution s;
    if (s.isScramble(s1, s2))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}
