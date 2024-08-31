class Solution {
public:
    int heightChecker(vector<int>& hi) {
        vector<int> arr = hi;
        sort(arr.begin(),arr.end());

        int ans = 0;
        for(int i=0; i<arr.size(); i++){
            if(arr[i]!=hi[i]) ans++;
        }
        return ans;
    }
};