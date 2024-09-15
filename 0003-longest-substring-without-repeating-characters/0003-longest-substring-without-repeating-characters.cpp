class Solution {
public:
    int lengthOfLongestSubstring(string nums) {
        int i=0 ,j=0 , n=nums.size();
        int ans=0;
        unordered_map<char,int>mp;
        while(j<n){
            mp[nums[j]]++;

            if(mp[nums[j]]==1){
                ans=max(ans,j-i+1);
                j++;
            }
            else if(mp[nums[j]]>1){
                while(mp[nums[j]]>1){
                    mp[nums[i]]--;
                    if(mp[nums[i]]==0)
                    mp.erase(nums[i]);
                    i++;
                }
                j++;
            }
        }
        return ans;
    }
};