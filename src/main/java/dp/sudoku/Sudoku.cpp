class Solution {

    bool isValid(vector<vector<char>>& board, int row, int col, char c) {
        for(int i=0; i<9; i++) {
            //horizontally
            if(board[row][i]==c) return false;

            //vertically
            if(board[i][col]==c) return false;

            //box
            if(board[3*(row/3) + (i/3)][3*(col/3) + (i%3)]==c) return false;
        }
        return true;
    }

    bool helper(vector<vector<char>>& board) {
        for(int i=0; i<9; i++) {
            for(int j=0; j<9; j++) {
                if(board[i][j]=='.') {
                    for(char c='1'; c<='9'; c++) {
                        if(isValid(board, i, j, c)) {
                            board[i][j] = c;
                            //if solution found
                            //return true
                            //no need to backtrack
                            if(helper(board)) return true;
                            board[i][j] = '.';
                        }
                    }
                    //can't place any of the 9 digits at i, j
                    return false;
                }
            }
        }
        //have gone through all the places
        return true;
    }

public:
    void solveSudoku(vector<vector<char>>& board) {
        helper(board);
    }
};