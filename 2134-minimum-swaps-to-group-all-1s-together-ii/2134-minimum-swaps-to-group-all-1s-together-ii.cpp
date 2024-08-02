class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int cnt1 = 0 , cnt , n=nums.size() ;
        cnt1=count(nums.begin() , nums.end() , 1);
        int windowsize=cnt1;
        
        for(int i =0 ; i<windowsize; i++){
            if(nums[i] == 0)
            cnt++;
        }
        int mn=cnt;
        for(int i =windowsize ; i < windowsize + n ; i++){
            if(nums[i%n] == 0) cnt++;
            if(nums[i-windowsize] == 0) cnt--;

            mn = min(mn, cnt);
        }
        return mn;
    }
};