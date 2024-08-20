class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;
        vector<pair<int,int>>ans;
        vector<int>res;

        for(auto i : nums){
            int x = i;
            mpp[x]++;
        }
        for(auto i : mpp){
            ans.push_back({i.second,i.first});
        }
        sort(ans.begin(),ans.end());
        
        for(int i=ans.size()-1;k!=0;i--){
            res.push_back(ans[i].second);
            k--;
        }
        return res;
        
    }
};