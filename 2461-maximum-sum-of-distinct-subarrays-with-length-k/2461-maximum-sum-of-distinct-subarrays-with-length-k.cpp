class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_set<int> window;
        long long currentSum = 0;
        int left =0 ;
        long long maxSum = 0;
        for(int right = 0 ; right <nums.size() ;right++){
            while(window.find(nums[right]) != window.end()){
                currentSum -= nums[left];
                window.erase(nums[left]);
                left++;
            }
            window.insert(nums[right]);
            currentSum += nums[right];
                
            if( right - left +1 == k ){
                maxSum = max(maxSum , currentSum);
            
            currentSum -= nums[left];
             window.erase(nums[left]);
             left++;
             }
        }
        return maxSum;
    }
};