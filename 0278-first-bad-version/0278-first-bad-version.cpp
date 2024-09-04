// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
      int l=0 , r=n;
        int minBad;

       while(l<=r){
            int mid = (l+r)/2;

           if(isBadVersion(mid) == true){
               minBad = mid;
               r = mid -1; 
           }else{
               l=mid+1;
           }
       }
       return minBad;
    }
};