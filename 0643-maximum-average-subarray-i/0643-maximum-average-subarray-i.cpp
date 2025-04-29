class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double window = 0;
        int left = 0;
        double averageSum = INT_MIN ;
        for(int right =0 ; right < nums.size() ; right++){
            window += nums[right];

            if(right - left + 1 > k ){
                window -= nums[left];
                left++;
            }
               if(right - left + 1 == k){
                averageSum = max(averageSum , window/k);
            }
        }
        return averageSum;
    }
};