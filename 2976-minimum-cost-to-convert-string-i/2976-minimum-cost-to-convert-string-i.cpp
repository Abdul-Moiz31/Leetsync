class Solution {
public:
    long long minimumCost(string s, string t, vector<char>& o, vector<char>& c, vector<int>& cost) {
        const int inf = 1 << 29;
        int g[26][26];
        for(int i = 0 ; i< 26; i++){
            fill(begin(g[i]), end(g[i]), inf);
            g[i][i] = 0;
        }
        for(int i = 0 ;i<o.size() ; ++i){
            int x = o[i] - 'a';
            int y= c[i] - 'a';
            int z = cost[i];
            g[x][y] = min(g[x][y], z);
        }
        for (int k = 0; k < 26; ++k) {
            for (int i = 0; i < 26; ++i) {
                for (int j = 0; j < 26; ++j) {
                    g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
                }
            }
        }
        long long ans = 0;
        int n =s.length();
        for(int i =0 ; i<n ; ++i){
            int x = s[i] - 'a';
            int y = t[i] - 'a';
            if(x != y){
                if(g[x][y] >= inf){
                    return -1;
                }
                ans += g[x][y];
            }
        }
        return ans;
    }
};