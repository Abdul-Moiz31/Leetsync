class Solution {
public:
    int minLength(string s) {
        string stck;
        int i=0,n=s.size();
        while(i<n){
            if(stck.empty()){
                stck.push_back(s[i]);
            }
            else if(stck.back()=='A' && s[i]=='B'){
                stck.pop_back();
            }
            else if(stck.back()=='C' && s[i]=='D'){
                stck.pop_back();
            }
            else{
                stck.push_back(s[i]);
            }
            i++;
        }
        return stck.size();
    }
};