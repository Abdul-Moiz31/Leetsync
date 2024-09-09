class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
       int l = 0 , r =0;
       int win =0; 
       int ans = INT_MIN;
       while( r < nums.size()){
           if(r-l < k){ 
            win +=nums[r];
            r++;
           } else if(r-l == k){
            ans=max(ans, win);
            win +=nums[r];
            r++;
            win -=nums[l];
            l++;
           }

       }
       ans=max(ans,win);
     return (double)ans/k ;

    }
};