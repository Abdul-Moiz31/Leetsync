class Solution {
public:
    int helper(int index ,vector<int>& nums  , vector<int>& dp){
        if(index == 0) return nums[index];
        if(index < 0) return 0;
        if(dp[index] != -1) return dp[index];
        int pick = nums[index] + helper(index-2 , nums , dp);
        int notpick = 0 + helper(index-1 , nums , dp);

        return dp[index]= max(pick , notpick);
    }

    int rob(vector<int>& nums) {
       int n = nums.size();
       vector<int> dp(n , -1);
       return helper(n -1 , nums , dp);

    }
};