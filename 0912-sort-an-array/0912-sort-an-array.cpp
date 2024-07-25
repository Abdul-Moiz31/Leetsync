class Solution {
public:
    void Heapify(vector<int>& nums, int n, int i) {
        int max = i;
        int l = (2 * i) + 1, r = (2 * i) + 2;
        if (l < n && nums[l] > nums[max])
            max = l;
        if (r < n && nums[r] > nums[max])
            max = r;
        if (max != i) {
            swap(nums[max], nums[i]);
            Heapify(nums, n, max);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        for (int i = n / 2 - 1; i >= 0; i--) {
            Heapify(nums, n, i);
        }
        for (int i = n - 1; i >= 0; i--) {
            swap(nums[0], nums[i]);
            Heapify(nums, i, 0);
        }
        return nums;
    }
};