class Solution {
public:
    int maxProfit(vector<int>& price) {
      int maxPro = 0; 
      int minprice=INT_MAX;
      int n = price.size();
      for (int i=0 ; i<n ; i++){
        minprice = min(minprice , price[i]);
        maxPro = max(maxPro , price[i] - minprice);
      }
      return maxPro;
    }
};