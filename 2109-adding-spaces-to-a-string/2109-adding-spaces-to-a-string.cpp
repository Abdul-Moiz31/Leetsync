class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ans ="";
        int id =0;
        for(int i=0 ; i<s.size() ; i++){
            if(id<spaces.size() && i==spaces[id]){
                ans+=' ';
                id++;
            }
            ans+=s[i];
        }
        return ans;
    }
};