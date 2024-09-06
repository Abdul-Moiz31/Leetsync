class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum=0, avg=0;

        for(int i=0 ; i<k; i++){
            sum+=nums[i];
        }
        avg=sum / k;

        int i=0, j=k;

        while(j<nums.size()){
            sum-=nums[i];
            sum+=nums[j];

            i++;
            j++;

            avg = max(avg, sum / k);
        }
          return avg;
    }
};