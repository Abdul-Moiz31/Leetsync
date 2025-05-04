class Solution {
public:
    void getPermuwithDuplicates(vector<int>& nums , int ind , vector<vector<int>>& ans){
        if(ind == nums.size()){
            ans.push_back(nums);
            return ;
        }
        unordered_set<int> mp;

        for(int i = ind ; i < nums.size() ; i++){
            if(mp.count(nums[i])) continue;
            mp.insert(nums[i]);
            swap(nums[ind]  , nums[i]);
            getPermuwithDuplicates(nums , ind+1 , ans);
            swap(nums[ind]  , nums[i]);
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
            sort(nums.begin() , nums.end());
        vector<vector<int>> ans;
        getPermuwithDuplicates(nums , 0 , ans);
        return ans;
    }
};