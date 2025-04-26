class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int cnt = 0;
        sort(nums.begin() , nums.end());
        while (left < right) {
            int sum = nums[left] + nums[right];
            if (sum < target) {
                cnt += (right -left);
                left++;
                
            } else {
                right--;
            }
        }
        return cnt;
    }
};