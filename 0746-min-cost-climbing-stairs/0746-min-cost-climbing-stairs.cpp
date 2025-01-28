class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        // if(n==1) return 1;
        // if(n==0) return 0;
        // vector<int> dp(n+1 , 0);
        // dp[0] =cost[0];
        // dp[1] = cost[1];
        for(int i = 2 ; i<n ;i++){
            cost[i] = min(cost[i-1] , cost[i-2]) + 
            cost[i]++;
        }
        return min(cost[n-1] , cost[n-2]);
    }
};