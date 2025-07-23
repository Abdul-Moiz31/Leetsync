class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin() , g.end());
        sort(s.begin() , s.end());

        int children = 0 ;
        int cookies = 0;

        while(children < g.size() && cookies < s.size()){
            if(g[children] <= s[cookies]){
                children++;
            }
            cookies++;
        }
        return children;
    }
};