class Solution {
public:
    void getcombSum(vector<int>& arr, int i ,  int target , vector<int> &combine , vector<vector<int>> &ans){

            if(i== arr.size() || target < 0 ) return ;
            if(target == 0){
                ans.push_back(combine);
                return;
            }

            combine.push_back(arr[i]);


        getcombSum(arr , i , target -arr[i] , combine , ans  ); // single include

        
        combine.pop_back(); // Bactrack

        getcombSum(arr , i+1 , target ,  combine , ans  ); // exclusion
    }
    
    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        sort(arr.begin() , arr.end());
        vector<vector<int>> ans;
        vector<int> combine;

        getcombSum( arr , 0 , target ,  combine , ans );
        return ans;
    }
};