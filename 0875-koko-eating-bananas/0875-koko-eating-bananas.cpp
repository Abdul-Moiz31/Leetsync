class Solution {
public:
    int findMax(vector<int> &piles){
        int maxi = INT_MIN;
        int n = piles.size();
        for(int i = 0 ; i<n ; i++){
            maxi = max(maxi , piles[i]);
        }
        return maxi;
    }

    long long calculatehours(vector<int> &piles , int hours ){
        long long  totalhours = 0;
        int n = piles.size();
        for(int i = 0 ; i<n ;i++){
            totalhours += ceil((double)piles[i] / (double)hours);
        }
        return totalhours;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
          int low = 1;
          int high = findMax(piles);
          while(low <= high){
            int mid = (low+high)/2;
            long long totalhours = calculatehours(piles , mid);
            if(totalhours <= h){
                high =  mid -1;
            } else {
                low = mid+1;
            }
          }
          return low;
    }
};