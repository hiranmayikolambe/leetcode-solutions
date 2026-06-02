class Solution {
public:
    int row[9] = {};
    int col[9] = {};
    int box[9] = {};
    bool solve(vector<vector<char>>& board) {
        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                if (board[r][c] != '.') continue;
                int boxId = (r / 3) * 3 + (c / 3);
                // Bits 1..9 that are still available
                int available =
                    ~(row[r] | col[c] | box[boxId]) & 0x3FE;
                while (available) {
                    // Extract lowest set bit
                    int bit = available & (-available);
                    // Remove it from available
                    available -= bit;
                    // Convert bit -> digit
                    int num = __builtin_ctz(bit);
                    board[r][c] = num + '0';
                    row[r] |= bit;
                    col[c] |= bit;
                    box[boxId] |= bit;
                    if (solve(board)) return true;
                    row[r] ^= bit;
                    col[c] ^= bit;
                    box[boxId] ^= bit;
                    board[r][c] = '.';
                }
                return false;
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                if (board[r][c] == '.') continue;
                int num = board[r][c] - '0';
                int bit = (1 << num);
                int boxId = (r / 3) * 3 + (c / 3);
                row[r] |= bit;
                col[c] |= bit;
                box[boxId] |= bit;
            }
        }
        solve(board);
    }
};