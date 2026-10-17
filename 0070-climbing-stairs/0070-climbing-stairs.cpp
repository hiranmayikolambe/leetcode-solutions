class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        return solve(n, dp);
    }
    int solve(int step, vector<int>& dp){
        if (step == 0) return 1;
        if (step < 0) return 0;
        if (dp[step] != -1) return dp[step];
        int onestepjump = solve(step - 1, dp);
        int twostepjump = solve(step - 2, dp);
        dp[step] = onestepjump + twostepjump;
        return dp[step];
    }
};