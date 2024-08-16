class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) 
    {
        unordered_map<int , int> mp;
        vector<int> res;

        for(int i=0 ;i<nums2.size() ; i++){
            int j = i + 1;

            while(j<nums2.size() && nums2[j] <= nums2[i]) 
            j++;

            if(j==nums2.size())
             mp[nums2[i]] = -1;
             else 
             mp[nums2[i]] = nums2[j];
        }
             for(auto it:nums1){
                int x=mp[it];
                res.push_back(x);
             }
             return res;
        }
};