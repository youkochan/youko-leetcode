class Solution {
public:
    void markBoard(vector<vector<char>>& board,
                    int m,
                    int n,
                    int i,
                    int j,
                    char c) {
        if (i < 0 || i >= m || j < 0 || j >= n)
            return;
        if (board[i][j] != 'O')
            return;
        board[i][j] = c;
        markBoard(board, m, n, i+1, j, c);
        markBoard(board, m, n, i-1, j, c);
        markBoard(board, m, n, i, j+1, c);
        markBoard(board, m, n, i, j-1, c);
        return;
    }

    /**
     * @param board a 2D board containing 'X' and 'O'
     * @return void
     */
    void surroundedRegions(vector<vector<char>>& board) {
        // Write your code here
        int m = board.size();
        if (!m)
            return;
        int n = board[0].size();
        if (!n)
            return;
        
        for (int i = 0; i < m; i ++)
            for (int j = 0; j < n; j ++)
                if (i == 0 || i == m - 1 || j == 0 || j == n - 1)
                    markBoard(board, m, n, i, j, 'Q');
        
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                char c = board[i][j];
                if (c == 'O')
                    board[i][j] = 'X';
                else if (c == 'Q')
                    board[i][j] = 'O';
            }
        }
        
        return;
    }
};
