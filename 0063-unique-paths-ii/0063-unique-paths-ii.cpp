class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<int> dp(cols, 0);
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (grid[row][col] == 1) {
                    dp[col] = 0;
                    continue;
                }
                if (row == 0 && col == 0) {
                    dp[col] = 1;
                    continue;
                } 
                int fromAbove = dp[col];
                int fromLeft = 0;
                if (col > 0) fromLeft = dp[col - 1];
                int current = fromAbove + fromLeft;
                dp[col] = current;
            }
        }
        return dp[cols - 1];
    }
};



