class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int rows = obstacleGrid.size();
        int cols = obstacleGrid[0].size();
        vector<vector<int>> dp(rows, vector<int>(cols, -1));
        return solve(rows - 1, cols - 1, obstacleGrid, dp);
    }
private:
    int solve(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        if (row < 0 || col < 0) return 0;
        if (grid[row][col] == 1) return 0;
        if (row == 0 && col == 0) return 1;
        if (dp[row][col] != -1) return dp[row][col];
        int fromAbove = solve(row - 1, col, grid, dp);
        int fromLeft = solve(row, col - 1, grid, dp);
        dp[row][col] = fromAbove + fromLeft;
        return dp[row][col];
    }
};

