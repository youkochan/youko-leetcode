class Solution {
public:
    bool _search(vector<vector<char>> &board, string &word, int pos, int i, int j, int r, int c) {
        if (pos == word.size())
            return true;
        
        if (i < 0 || j < 0 || i >= r || j >= c) {
            return false;
        }
        
        bool tag = false;
        if (board[i][j] == word[pos]) {
            
            board[i][j] = '*';
            
            if (_search(board, word, pos+1, i-1, j, r, c))
                tag = true;
            else if (_search(board, word, pos+1, i+1, j, r, c))
                tag = true;
            else if (_search(board, word, pos+1, i, j+1, r, c))
                tag = true;
            else if (_search(board, word, pos+1, i, j-1, r, c))
                tag = true;
            
            board[i][j] = word[pos];
        }
        
        return tag;
    }

    bool exist(vector<vector<char>>& board, string word) {
        if (word.size() == 0)
            return false;
        int r = board.size();
        if (!r)
            return false;
        int c = board[0].size();
        if (!c)
            return false;
        
        for (int i = 0; i < r; i ++) {
            for (int j = 0; j < c; j ++) {
                if (_search(board, word, 0, i, j, r, c)) {
                    return true;
                }
            }
        }
        
        return false;
    }
};