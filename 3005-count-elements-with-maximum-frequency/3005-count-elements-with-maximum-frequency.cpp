class Solution {
public:
    int maxFrequencyElements(vector<int>& n) {
        map<int,int>mp;
       for(int i = 0; i < n.size();i++){
            mp[n[i]]++;
        }
        int mxi = 0;
        for(int i=0; i<n.size(); i++ ){
            mxi = max(mxi,mp[n[i]]);
        }
        int cnt=0;
        for(int i=0; i<n.size(); i++ ){
            if(mp[n[i]] == mxi){
                cnt++;
            }
        }
        return cnt;
    } 

};