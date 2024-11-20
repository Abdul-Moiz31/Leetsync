class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    /* Brute Force 
       int n = nums.size();
       for(int i = 0 ;i<n;i++){
        for(int j = i+1 ; j<n; j++){
            if(nums[i] + nums[j] == target){
                return {i+1 , j+1};
            }

        }
       }
       return {};
       */
// Two Pointer 
       int l = 0 , r = nums.size()-1;

       while(l<r){
        int currsum = nums[l] + nums[r];
         if (currsum > target ){
            r--;
         } else if (currsum < target){
            l ++;
         }
         else{
            return {l + 1 , r + 1};
         }
       }
       return {};
    }
};