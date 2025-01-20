class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
       int n = nums.size();
        int maxi = 1;
        sort(nums.begin(), nums.end());
        unordered_map<int,int> m;
        for(int i = 0; i < n; i++) m[nums[i]] = 1;

        int t;
        for(int i = 1; i < n; i++){
            t = k;
            int j = i - 1;
            if(nums[i] == nums[j]){
                m[nums[i]]++;
                maxi = max(maxi,m[nums[i]]);
            }

            else{
                while(t>0 && j>=0){
                    t = t - (nums[i] - nums[j]);
                    if(t >= 0) m[nums[i]]++;
                    j--;
                    maxi = max(maxi,m[nums[i]]);
                }
            }
        }

        return maxi;
        }
};