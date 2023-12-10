class Solution {

    bool isValid(int row, int col, vector<string>& board, int n) {
        //  vertically
        for(int r=row; r>=0; r--)
            if(board[r][col]=='Q') return false;

        //diagonally - left top

        for(int r=row, c=col; r>=0 && c>=0 ; c--, r--)
            if(board[r][c]=='Q') return false;

        //diagonally - right top
        for(int r=row, c=col; r>=0 && c<n; c++, r--)
            if(board[r][c]=='Q') return false;

        return true;
    }

    void helper(int row, vector<vector<string>>& res, vector<string>& board, int n) {
        if(row==n) {
            res.push_back(board);
            return;
        }

        for(int col=0; col<n; col++) {
            if(isValid(row, col, board, n)) {
                board[row][col] = 'Q';
                helper(row + 1, res, board, n);
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