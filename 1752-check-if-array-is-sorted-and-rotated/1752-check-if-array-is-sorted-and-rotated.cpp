class Solution {
public:
    bool check(vector<int>& nums) {
      int cnt = 0;
      int n = nums.size();
        if(n<=1 ){
            return true;
        }
        for (int i = 0; i < n; i++) {
            if (nums[i] > nums[(i + 1) % n ])  {
                cnt++;
            }
        }
        return cnt<=1;
    }
};