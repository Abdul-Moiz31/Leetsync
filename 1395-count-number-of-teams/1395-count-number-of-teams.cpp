class Solution {
public:
    int numTeams(vector<int>& r) {
        int res = 0;
        for(int i = 0 ; i<r.size()-2 ; i++){
            for(int j=i+1 ; j<r.size() ; j++){
                for(int k=j+1 ; k<r.size(); k++){
                    if(r[i] > r[j] && r[j] > r[k]){
                        res++;
                    } if(r[i]  < r[j] && r[j] < r[k]){
                        res++;
                    }
                }
            }
        }
        return res; 
    }
};