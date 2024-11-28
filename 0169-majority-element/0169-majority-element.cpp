class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int max=nums[0];
        int cnt = 1;
        
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == max) {
                cnt++;
            } else {
                cnt--;
                if (cnt == 0) {
                    max = nums[i];
                    cnt = 1;
                }
            }
        }
        return max;
    }
};