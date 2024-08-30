class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int l1 =0 ; 
        int l2 = 0 ;

        for(int &num:nums){
            if(num > l1){
                l2=l1;
                l1=num;
            } else{
                l2 = max(l2 , num);
            }
        }
        return (l1-1)*(l2-1);
    }
};