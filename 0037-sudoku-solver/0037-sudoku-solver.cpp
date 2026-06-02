class Solution {
public:
    int row[9] = {};
    int col[9] = {};
    int box[9] = {};
    void solveSudoku(vector<vector<char>>& board) {
        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                if (board[r][c] == '.') continue;
                int num = board[r][c] - '0';
                int mask = (1 << num);
                int boxId = (r / 3) * 3 + c / 3;
                row[r] |= mask;
                col[c] |= mask;
                box[boxId] |= mask;
            }
        }
        solve(board);
    }
    bool solve(vector<vector<char>>& board) {
        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                if (board[r][c] != '.') continue;
                int boxId = (r / 3) * 3 + c / 3;
                for (int num = 1; num <= 9; num++) {
                    int mask = (1 << num);
                    if ((row[r] & mask) || (col[c] & mask) || (box[boxId] & mask)) continue;
                    board[r][c] = num + '0';
                    row[r] |= mask;
                    col[c] |= mask;
                    box[boxId] |= mask;
                    if (solve(board)) return true;
                    board[r][c] = '.';
                    row[r] ^= mask;
                    col[c] ^= mask;
                    box[boxId] ^= mask;
                }
                return false;
            }
        }
        return true;
    }
};