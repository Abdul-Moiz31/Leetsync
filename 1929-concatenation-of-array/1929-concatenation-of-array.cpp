class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
          int n = nums.size();
          int m = 2*n;
          vector<int>ans(m);
          int  j = 0;
          for( int i = 0 ; i<m ; i++){
            if(j>=n){
                j=0;
            }
            ans[i] = nums[j++];
          }
          return ans;
    }
};