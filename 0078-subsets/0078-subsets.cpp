class Solution {
public:
    void subs(vector<int>& nums, vector<vector<int>>& res, vector<int>& sub, int idx) {
        int l=nums.size();  
        res.push_back(sub);
        for(int i=idx;i<l;i++){
            sub.push_back(nums[i]);
            subs(nums, res, sub,i+1);
            sub.pop_back();
        }
        return;
    }
     vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> sub;
        vector<vector<int>> res;
        subs(nums, res, sub, 0);
        return res;
    }
};