class NumArray {
public:
vector<int> res;
    NumArray(vector<int>& nums) {
        res.push_back(0);
        for(int num:nums)
        res.push_back(res.back() + num);
        }
    
    int sumRange(int l, int r) {
         return res[r+1] - res[l];
        }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */