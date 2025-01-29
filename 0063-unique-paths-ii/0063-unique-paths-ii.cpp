class Solution {
public:
     // Memoization
    int uniquePathsWithObstacles1(int i , int j , vector<vector<int>>& obstacleGrid ,  vector<vector<int>> &dp ){
         if (i < 0 || j < 0 || obstacleGrid[i][j] == 1) {
            return 0;
        }
        if(i==0 && j==0)
        return 1;
        // if(i<0 || j<0)
        //  return 0;
         
         if(dp[i][j] != -1)
            return dp[i][j];
         
         int down = uniquePathsWithObstacles1 (i-1 , j , obstacleGrid, dp);
         int right = uniquePathsWithObstacles1 (i , j-1 , obstacleGrid, dp);

         return dp[i][j]=down + right;
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
         int n = obstacleGrid.size();
         int m = obstacleGrid[0].size();
        vector<vector<int>> dp(n , vector<int>(m, -1));

        return uniquePathsWithObstacles1(n-1 , m-1 , obstacleGrid , dp);
    }
};