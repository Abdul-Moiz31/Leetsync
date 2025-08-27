class Solution {
public:
    
    void getUniqueCombinations(vector<int>& arr, int target , int i , vector<int>& combine , vector<vector<int>>& ans){
      if( target == 0){
    ans.push_back(combine);
    return ;
}
 
  
   // check
   for(int j = i ; j<arr.size() ; j++){
    if(j > i  && arr[j] == arr[j-1])
        continue;
        if (arr[j] > target) break;

    combine.push_back(arr[j]);

    getUniqueCombinations(arr , target - arr[j] , j+1 , combine , ans);
    combine.pop_back();
}

}
    
    vector<vector<int>> combinationSum2(vector<int>& arr, int target) {
        sort(arr.begin() , arr.end());
        vector<int> combine;
        vector<vector<int>> ans;

        getUniqueCombinations(arr , target , 0, combine , ans);

        return ans;

    }
};