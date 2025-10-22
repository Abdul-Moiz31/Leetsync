class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> window;
        int l = 0;
        for(int r = 0 ; r < nums.size() ; r++){
            if(window.find(nums[r]) != window.end()){
                return true;
            }
            window.insert(nums[r]);

            if(r-l+1 > k){
                window.erase(nums[l]);
                l++;
            }
        }
        return false;
    }
};