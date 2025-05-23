class Solution {
public:
    int helper(int i, int amount, vector<int>& coins, vector<vector<int>>& dp) {
        if (i == 0) {
            if (amount % coins[0] == 0)
                return amount / coins[0];
            else
                return 1e9;
        }
        if (dp[i][amount] != -1)
            return dp[i][amount];

        int notTake = helper(i - 1, amount, coins, dp);
        int take = 1e9;
        if (coins[i] <= amount)
            take = 1 + helper(i, amount - coins[i], coins, dp);

        return dp[i][amount] = min(take, notTake);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        int ans = helper(n - 1, amount, coins, dp);
        return (ans >= 1e9) ? -1 : ans;
    }
};
