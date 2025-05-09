class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit =0;
        int minProfit = INT_MAX;
        for(int i = 0 ;i< prices.size() ;i++){
            minProfit = min(minProfit , prices[i] );
            maxProfit = max(maxProfit , prices[i] - minProfit );
        }
        return maxProfit;
    }
};