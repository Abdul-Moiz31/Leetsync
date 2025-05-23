class Solution {
public:
    int helper(int i, int amount, vector<int>& coins) {
        if (amount == 0)
            return 1;
        if (i == coins.size() || amount < 0)
            return 0;
        // Take the coin
        int take = helper(i, amount - coins[i], coins);

        // Don't take the coin
        int notTake = helper(i + 1, amount, coins);

        return take + notTake;
    }

    int change(int amount, vector<int>& coins) {
        return helper(0, amount, coins);
    }
};
