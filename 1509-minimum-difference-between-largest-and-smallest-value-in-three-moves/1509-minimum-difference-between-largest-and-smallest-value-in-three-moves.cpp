class Solution {
public:
    int minDifference(vector<int>& nums) {
       sort(nums.begin() , nums.end());
       int n = nums.size();
       int minVal = INT_MAX;
       if(n<=4)
       return 0;
       minVal = min(minVal , nums[n-4] -nums[0]);
       minVal = min(minVal , nums[n-1] -nums[3]);
       minVal = min(minVal , nums[n-2] -nums[2]);
       minVal = min(minVal , nums[n-3] -nums[1]);
       return minVal;
    }
};