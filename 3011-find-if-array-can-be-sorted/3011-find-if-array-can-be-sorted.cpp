class Solution {
public:
    int setbit(int num) {
        int count = 0;
        while (num) {
            count += num & 1;
            num >>= 1;
        }
        return count;
    }

    bool canSortArray(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i < n - 1; ++i) {
            for (int j = 0; j < n - 1; ++j) {
                if (nums[j] > nums[j + 1] &&
                    setbit(nums[j]) == setbit(nums[j + 1])) {
                    swap(nums[j], nums[j + 1]);
                }
            }
        }

        return is_sorted(nums.begin(), nums.end());
    }
};