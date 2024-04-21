class Solution {
    bool isValid(vector<string>& board, int row, int col, int n) {
        // left row
        for(int i = col; i>=0; i--){
            if(board[row][i] == 'Q')
                return false;
        }

        // left top diagonal
        for(int i=row, j=col; i>=0 && j>=0; i--, j--) {
            if(board[i][j] == 'Q')
                return false;
        }

        // right top diagonal
        for(int i=row, j=col; i<n && j>=0; i++, j--) {
            if(board[i][j] == 'Q')
                return false;
        }

        return true;
    }

    void solver(vector<vector<string>>& res, vector<string>& board, int n, int col) {
        if(col == n) {
            res.push_back(board);
            return;
        }

        for(int row = 0; row < n; row++) {
            if(isValid(board, row, col, n)) {
                board[row][col] = 'Q';
                solver(res, board, n, col + 1);
                board[row][col] = '.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n);
        string s(n, '.');
        for(int i=0; i<n; i++)
            board[i] = s;
        solver(res, board, n, 0);
        return res;
    }
};