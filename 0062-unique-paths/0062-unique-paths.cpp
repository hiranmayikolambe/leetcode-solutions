class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(0, 0, m, n, dp);
    }
private:
    int solve(int row, int column,int m, int n, vector<vector<int>>& dp) {
        if (row == m - 1 && column == n - 1) return 1;
        if (row >= m || column >= n) return 0;
        if (dp[row][column] != -1) return dp[row][column];
        int downPaths = solve(row + 1, column, m, n, dp);
        int rightPaths = solve(row, column + 1, m, n, dp);
        dp[row][column] = downPaths + rightPaths;
        return dp[row][column];
    }
};

