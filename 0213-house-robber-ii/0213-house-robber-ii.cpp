class Solution {
public:
   int maximumadjacentsum(vector<int> &nums){
    int n = nums.size();
        int prev = nums[0];
        int prev2 = 0;
        for(int i  = 1 ; i< n ; i++){
            int take =  nums[i];
            if(i>1) take += prev2;
            int nontake = 0 + prev;
            int curr = max(take , nontake);
            prev2 = prev;
            prev=curr;
        }
        return prev;
   }
   
    int rob(vector<int>& nums1) {
        int n= nums1.size();
        vector<int> temp1 , temp2;
        if(n==1) return  nums1[0];
        for(int i = 0 ;i< n ; i++){
            if(i !=0) temp1.push_back(nums1[i]);
            if(i != n-1) temp2.push_back(nums1[i]);
        }
        return max(maximumadjacentsum(temp1) , maximumadjacentsum(temp2));
    }
};