class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int maxi = INT_MIN;
        long long sum = 0;
        int start = -1;
        int end = -1;
        for (int i = 0; i < n; i++) {
            if (sum == 0)
                start = i;
            sum += nums[i];
            if (sum > maxi) {
                maxi = sum;
            }
            if (sum < 0) {
                sum = 0;
            }
        }
        return maxi;
    }
};