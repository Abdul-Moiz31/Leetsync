class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();
        vector<int>dp(n+1 , INT_MAX) ;
        dp[0] = 0; // Base case

        for(int i = 0 ; i <=n ; i++){
            int total_w = 0;
            int max_h = 0;
            for(int j = i ; j> 0 ; j--){
                total_w += books[j-1][0];
                if(total_w > shelfWidth){
                    break;
                }
                max_h = max(max_h , books[j-1][1]);
                dp[i] = min(dp[i] , dp[j-1] + max_h);
            }
        }
        return dp[n];
    }
};