class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();

        int pointer1 = 1;
        for(int pointer2 = 1 ; pointer2 < n ; pointer2++){
            if(nums[pointer2] != nums[pointer2-1]){
                nums[pointer1] = nums[pointer2];
                pointer1++;
            }
        }
        return pointer1;
    }
};