class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[m - 1][n - 1] = 1;
        for (int row = m - 1; row >= 0; row--) {
            for (int column = n - 1; column >= 0; column--) {
                if (row == m - 1 && column == n - 1) continue;
                int downPaths = row + 1 < m ? dp[row + 1][column] : 0;
                int rightPaths = column + 1 < n ? dp[row][column + 1] : 0;
                dp[row][column] = downPaths + rightPaths;
            }
        }
        return dp[0][0];
    }
};

