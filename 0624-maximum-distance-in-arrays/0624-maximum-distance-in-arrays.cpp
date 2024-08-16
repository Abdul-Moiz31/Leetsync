class Solution {
public:
    int maxDistance(vector<vector<int>>& arr) {
        int MIN = arr[0].front();
        int MAX = arr[0].back();

        int ans =0;

        for(int i = 1  ; i<arr.size() ; i++){
            int currMin = arr[i].front();
            int currMax = arr[i].back();

            ans = max({ ans , abs(currMin - MAX), abs(currMax - MIN)});

            MAX = max(MAX , currMax);
            MIN = min(MIN , currMin);
        }
        return ans;
    }
};