class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int low = 0 ;
        int high=nums.size() -1;
        vector<int> result = {-1 , -1};

        while(low <= high){
            int mid = (low + high)/2;
            if(nums[mid] == target){
                result[0] = mid;
                high = mid - 1;
            } else if(nums[mid] < target){
                low= mid+1;
            } else  {
                high = mid -1;
            }
        }

        if(result[0] == -1 ) return result;

        low = result[0];
        high = nums.size() -1;

         while(low <= high){
            int mid = (low + high)/2;
            if(nums[mid] == target){
                result[1] = mid;
                low = mid + 1;
            } else if(nums[mid] < target){
                low= mid+1;
            } else  {
                high = mid -1;
            }
        }
        return result ;
       
    }
};