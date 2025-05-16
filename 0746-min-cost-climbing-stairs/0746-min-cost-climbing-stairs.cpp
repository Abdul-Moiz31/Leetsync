class Solution {
public:
    int solve(int i, vector<int>& cost) {
        if (i == 0)
            return cost[0];
        if (i == 1)
            return cost[1];

        return cost[i] + min(solve(i - 1, cost), solve(i - 2, cost));
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        return min(solve(n - 1, cost), solve(n - 2, cost));
    }
};