class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> ans;
        for(int i=0 ; i<n ; i++){
            int pre = 0;
            for(int j =i; j < n ; j++){
                pre +=nums[j];
                arr.push_back(pre);
            }
        }
        sort(arr.begin() , arr.end());
        int result =0;
        int MOD = 1000000007;
        for(int i = left -1 ; i< right ; i++){
            result (result +arr[i]) % MOD;

        }
       return result;
    }
};