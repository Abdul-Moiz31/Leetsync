class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_set<int> window;
        long long maxSum = 0;
        long long currSum = 0;
        int left = 0;
        for (int right = 0; right < nums.size(); right++) {
            while(window.find(nums[right]) != window.end()) {
                currSum -= nums[left];
                window.erase(nums[left]);
                left++;
            }

            window.insert(nums[right]);
            currSum += nums[right];

            if (right - left + 1 == k) {
                maxSum = max(maxSum, currSum);

                currSum -= nums[left];
                window.erase(nums[left]);
                left++;
            }
        }

        return maxSum;
    }
};