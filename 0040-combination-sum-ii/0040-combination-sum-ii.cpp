class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
    }class Solution {
    void combine(vector<int> &cand, int tar, vector<int> &vec, vector<vector<int>> &res, int i, int n){
        if(tar < 0) return;
        if(tar == 0){
            res.push_back(vec);
            return;
        }
        for(int j = i; j < n; j++){
            if(j > i && cand[j] == cand[j-1]) continue; 
            vec.push_back(cand[j]);
            combine(cand, tar - cand[j], vec, res, j + 1, n);
            vec.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> vec;
        sort(candidates.begin(), candidates.end());
        combine(candidates, target, vec, ans, 0, candidates.size());
        return ans;
    }
};
};