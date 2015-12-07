#include <iostream>
#include <vector>

using namespace std;

/**
 * [[1,0,0,0,0,1],
 *  [0,0,0,1,1,0],
 *  [1,0,1,0,1,0],
 *  [1,0,0,0,1,0],
 *  [1,1,1,1,0,1],
 *  [0,1,1,0,1,0],
 *  [1,0,1,0,1,1],
 *  [1,0,0,1,1,1],
 *  [1,1,0,0,0,0]]
 */


class Solution {
public:
    void gameOfLife(vector<vector<int> >& board) {
        if (board.size() == 0 || board[0].size() == 0)
            return;
        int m = board.size();
        int n = board[0].size();
        int dx[8] = { -1,  0,  1, -1,  1, -1,  0,  1};
        int dy[8] = { -1, -1, -1,  0,  0,  1,  1,  1};
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                int c = 0;
                // cout << "---" << endl;
                for (int k = 0; k < 8; k ++) {
                    int x = i + dx[k];
                    int y = j + dy[k];
                    
                    if ((x >= 0 && x < m) && (y >= 0 && y < n)) {
                        // cout << "xy:" << x << " " << y << endl;
                        if (board[x][y] > 0) {
                            c ++;
                        }
                    }
                }
                // cout << "c:" << c << endl;
                if (c != 0)
                    board[i][j] == 0 ? board[i][j] = -1 * c : board[i][j] = c;
                else {
                    if (board[i][j] == 1)
                        board[i][j] = 9;
                }
            }
        }

        // for (int i = 0; i < board.size(); i ++) {
        //     for (int j = 0; j < board[0].size(); j ++) {
        //         cout << board[i][j] << " ";
        //     }
        //     cout << endl;
        // }


        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (board[i][j] == 9) {
                    board[i][j] = 0;
                }
                else if (board[i][j] > 0 && board[i][j] < 2) {
                    board[i][j] = 0;
                }
                else if (board[i][j] > 3) {
                    board[i][j] = 0;
                }
                else if (board[i][j] == 2 || board[i][j] == 3) {
                    board[i][j] = 1;
                }
                else if (board[i][j] == -3) {
                    board[i][j] = 1;
                }
                else
                    board[i][j] = 0;
            }
        }
    }
};


int main() {
    vector<vector<int> > vv;
    Solution s;

    vector<int> v1;
    vector<int> v2;
    vector<int> v3;

    v1.push_back(1);
    v1.push_back(0);
    v1.push_back(0);

    v2.push_back(0);
    v2.push_back(0);
    v2.push_back(0);

    v3.push_back(1);
    v3.push_back(0);
    v3.push_back(1);

    vv.push_back(v1);
    vv.push_back(v2);
    vv.push_back(v3);

    for (int i = 0; i < vv.size(); i ++) {
        for (int j = 0; j < vv[0].size(); j ++) {
            cout << vv[i][j] << " ";
        }
        cout << endl;
    }

    s.gameOfLife(vv);

    for (int i = 0; i < vv.size(); i ++) {
        for (int j = 0; j < vv[0].size(); j ++) {
            cout << vv[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

