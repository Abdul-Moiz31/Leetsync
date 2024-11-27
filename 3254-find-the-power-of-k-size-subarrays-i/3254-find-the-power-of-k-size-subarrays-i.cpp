class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n  = nums.size();
        vector<int>res;
        for(int i = 0 ; i<= n-k ; i++){
            bool isSorted = true;
            int maxE = nums[i];
            
            for(int j =i + 1 ;  j<i+k ; j++){
                if(nums[j] != nums[j-1] + 1){
                    isSorted = false;
                    break;
                }
                maxE = max(maxE , nums[j]);
            }
            if(isSorted) {
                res.push_back(maxE);
            }
            else {
                res.push_back(-1);

            }
        }

    return res;
    }
};