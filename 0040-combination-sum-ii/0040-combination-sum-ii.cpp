class Solution {
public:
    
    void getUniqueCombinations(vector<int>& arr, int target , int i , vector<int>& combine , vector<vector<int>>& ans){
      if( target == 0){
    ans.push_back(combine);
    return ;
}
    if (i== arr.size() || target < 0 ) return;
 
  
   // check
   if(i > 0 && arr[i] == arr[i-1]){
     return ;
    }

    combine.push_back(arr[i]);

    getUniqueCombinations(arr , target - arr[i] , i+1 , combine , ans);
    combine.pop_back();
    getUniqueCombinations(arr , target , i+1 , combine , ans);


}
    
    vector<vector<int>> combinationSum2(vector<int>& arr, int target) {
        sort(arr.begin() , arr.end());
        vector<int> combine;
        vector<vector<int>> ans;

        getUniqueCombinations(arr , target , 0, combine , ans);

        return ans;

    }
};