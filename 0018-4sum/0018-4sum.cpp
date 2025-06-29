class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            for (int j = i + 1; j < n ; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;
                int left = j + 1;
                int right = n - 1;
                while (left < right) {
                    long long quad =
                        (long long)nums[i] + nums[j] + nums[left] + nums[right];
                    if (quad > target) {
                        right--;
                    } else if (quad < target) {
                        left++;
                    } else {
                        vector<int> temp = {nums[i] , nums[j] , nums[left] , nums[right]};
                        ans.push_back(temp);
                        while (left < right && nums[left] == nums[left + 1])
                            left++;
                        while (left < right && nums[right] == nums[right - 1])
                            right--;
                        left++;
                        right--;
                    }
                }
            }
        }
        return ans;
    }
};