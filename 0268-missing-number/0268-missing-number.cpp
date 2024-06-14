class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n =nums.size();
        int target = (n*(n+1)/2);
        int res=0; 
        for ( auto it:nums){
            res +=it;
        }
        return target - res;
    }
};