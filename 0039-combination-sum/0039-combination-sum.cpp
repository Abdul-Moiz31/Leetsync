class Solution {
public:
    set<vector<int>> s;
    void getcombSum(vector<int>& arr, int i ,  int target , vector<int> &combine , vector<vector<int>> &ans){

            if(i== arr.size() || target < 0 ) return ;
            if(target == 0)
                if(s.find(combine) == s.end()){
                    s.insert(combine);
                ans.push_back(combine);
                return;
            }

            combine.push_back(arr[i]);


        getcombSum(arr , i+1 , target -arr[i] , combine , ans  ); // single include

        getcombSum(arr , i , target -arr[i] , combine , ans); // multiple include
        
        combine.pop_back(); // Bactrack

        getcombSum(arr , i+1 , target ,  combine , ans  ); // exclusion
    }
    
    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        vector<vector<int>> ans;
        vector<int> combine;

        getcombSum( arr , 0 , target ,  combine , ans );
        return ans;
    }
};