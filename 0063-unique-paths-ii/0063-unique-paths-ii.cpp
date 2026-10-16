class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> dp(rows, vector<int>(cols, 0));
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (grid[row][col] == 1) {
                    dp[row][col] = 0;
                    continue;
                }
                if (row == 0 && col == 0) {
                    dp[row][col] = 1;
                    continue;
                } 
                int fromAbove = 0;
                int fromLeft = 0;
                if (row > 0) fromAbove = dp[row - 1][col];
                if (col > 0) fromLeft = dp[row][col - 1];
                dp[row][col] = fromAbove + fromLeft;
            }
        }
        return dp[rows - 1][cols - 1];
    }
};

