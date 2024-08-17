class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int , int> numMap;
        for ( int i = 0 ; i< nums.size() ; i++ ){
        int comp = target - nums[i];
        if(numMap.find(comp) != numMap.end()){
            return {numMap[comp], i};
        }
        numMap[nums[i]] = i;
        }
        return {};
    }
};