class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> window;
        int left = 00  ;
        for(int right = 0 ; right < nums.size() ; right++){
            while(window.find(nums[right]) != window.end()){
                 return true;
            }
             window.insert(nums[right]);

            if(right - left + 1 > k ) {
                 window.erase(nums[left]);
                 left++;
            }
        }
        return false;
    }
};