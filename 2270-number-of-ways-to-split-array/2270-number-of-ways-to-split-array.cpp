class Solution {
public:
    int waysToSplitArray(vector<int>& nums) 
    {
        vector<long> pref;
        pref.push_back(0);
        for(auto val : nums) pref.push_back(pref.back() + val);

        int ans = 0, n = nums.size();
        for(int i = 1; i < n; i++)
            if(pref[i] >= pref.back() - pref[i]) ans++;
        return ans;    
    }
};