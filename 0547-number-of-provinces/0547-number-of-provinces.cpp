class Solution {
public:
    void dfs(int node , vector<vector<int>>& N , vector<int>& visited) {
        visited[node] = 1;
       for (int i =0 ; i< N[node].size() ;i++){
        if(N[node][i] == 1 && visited[i] == 0){
            dfs(i , N , visited);
        }
       }
    }

    int findCircleNum(vector<vector<int>>& N) {
        int n = N.size();
        vector<int> visited(n, 0);
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                cnt++;
                dfs(i,N, visited);
            }
        }
        return cnt;
    }
};