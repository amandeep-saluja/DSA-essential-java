class Solution {

    bool isValid(int row, int col, vector<string>& board, int n) {
        //horizontally

        for(int c=col; c>=0; c--)
            if(board[row][c]=='Q') return false;

        //diagonally - left top

        for(int r=row, c=col; r>=0 && c>=0 ; c--, r--)
            if(board[r][c]=='Q') return false;

        //diagonally - left bottom
        for(int r=row, c=col; r<n && c>=0; c--, r++)
            if(board[r][c]=='Q') return false;

        return true;
    }

    void helper(int col, vector<vector<string>>& res, vector<string>& board, int n) {
        if(col==n) {
            res.push_back(board);
            return;
        }

        for(int row=0; row<n; row++) {
            if(isValid(row, col, board, n)) {
                board[row][col] = 'Q';
                helper(col+1, res, board, n);
                board[row][col] = '.';
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n);
        string s(n, '.');
        for(int i=0; i<n; i++) {
            board[i] = s;
        }

        vector<vector<string>> res;
        helper(0, res, board, n);
        return res;
    }
};