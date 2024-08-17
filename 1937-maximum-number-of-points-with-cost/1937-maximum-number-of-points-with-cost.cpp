class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int m = points.size(); 
        int n = points[0].size();
        
        vector<long long> dp(n);
        
        for (int j = 0; j < n; j++) {
            dp[j] = points[0][j];
        }
        
        for (int i = 1; i < m; i++) {
            vector<long long> new_dp(n);
            vector<long long> left_max(n), right_max(n);
            

            left_max[0] = dp[0];
            for (int j = 1; j < n; j++) {
                left_max[j] = max(left_max[j-1] - 1, dp[j]);
            }
            
    
            right_max[n-1] = dp[n-1];
            for (int j = n-2; j >= 0; j--) {
                right_max[j] = max(right_max[j+1] - 1, dp[j]);
            }

            for (int j = 0; j < n; j++) {
                new_dp[j] = points[i][j] + max(left_max[j], right_max[j]);
            }
            
            dp = move(new_dp);
        }
        
        return *max_element(dp.begin(), dp.end());
    }
};