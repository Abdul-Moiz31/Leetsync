class Solution {
public:
    void getSubset(vector<int>& nums, vector<int>& ans, int i, vector<vector<int>>& allSubset) {
        if (i == nums.size()) {
            allSubset.push_back(ans);
            return;
        }
        ans.push_back(nums[i]);
        getSubset(nums, ans, i + 1, allSubset);

        ans.pop_back();
        getSubset(nums, ans, i + 1, allSubset);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> allSubset;
        vector<int> ans;
        getSubset(nums, ans, 0, allSubset);

        return allSubset;
    }
};