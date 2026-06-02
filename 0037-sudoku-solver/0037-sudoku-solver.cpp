class Solution {
public:
    bool row[9][10] = {};
    bool col[9][10] = {};
    bool box[9][10] = {};
    void solveSudoku(vector<vector<char>>& board) {
        for (int r = 0; r < 9; r++){
            for (int c = 0; c < 9; c++){
                if (board[r][c] != '.'){
                    int num = board[r][c] - '0';
                    int boxid = (r / 3) * 3 + (c / 3);
                    row[r][num] = true;
                    col[c][num] = true;
                    box[boxid][num] = true;
                }
            }
        }
        solve(board);
    }
    bool solve(vector<vector<char>>& board){
        for(int r = 0; r < 9; r++){
            for (int c = 0; c < 9; c++){
                if (board[r][c] == '.'){
                    int boxid = (r / 3) * 3 + (c / 3);
                    for (int num = 1; num <= 9; num++){
                        if (!row[r][num] && !col[c][num] && !box[boxid][num]){
                            board[r][c] = num + '0';
                            row[r][num] = true;
                            col[c][num] = true;
                            box[boxid][num] = true;

                            if(solve(board)) return true;
                            board[r][c] = '.';
                            row[r][num] = false;
                            col[c][num] = false;
                            box[boxid][num] = false;
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
};