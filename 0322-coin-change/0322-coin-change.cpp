class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for (int c : coins){
            for (int a = c; a <= amount; a++){
                dp[a] = min(dp[a], dp[a-c]+1);
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }
};