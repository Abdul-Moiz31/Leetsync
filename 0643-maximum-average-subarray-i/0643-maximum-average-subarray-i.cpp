class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double window =0;
        int l = 0;
        double averagesum = INT_MIN;
        for(int r = 0 ; r<nums.size() ;r++){
            window += nums[r];
            if( r - l +1 > k){
                window -= nums[l];
                l++;
            }

            if( r - l + 1 == k){
                averagesum = max(averagesum , window/k);
            }
        }
        return averagesum;
    }
};