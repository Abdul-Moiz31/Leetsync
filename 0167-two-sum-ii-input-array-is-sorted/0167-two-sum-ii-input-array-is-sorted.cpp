class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size()-1;

        while(l<r){
        int total = nums[l] + nums[r];
         if(total == target){
            return {l+1 , r+1};
        } else if(total > target){
            r--;
        } else{
            l++;
        }
    }
     return {-1,-1};
    }
};