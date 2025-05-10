class Solution {
public:
    void dfs(int i, int j, vector<vector<int>>& visited,
             vector<vector<int>>& heights, int n, int m) {
        visited[i][j] = 1;
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};

        for (int d = 0; d < 4; d++) {
            int nrow = i + dx[d];
            int ncol = j + dy[d];
            if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m &&
                !visited[nrow][ncol] && heights[nrow][ncol] >= heights[i][j]) {
                dfs(nrow, ncol, visited, heights, n, m);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> pacific(n, vector<int>(m, 0));
        vector<vector<int>> atlantic(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            dfs(i, 0, pacific, heights, n, m);
        }
        for (int j = 0; j < m; j++) {
            dfs(0, j, pacific, heights, n, m);
        }

        //    DFS for atlantic
        for (int i = 0; i < n; i++) {
            dfs(i, m - 1, atlantic, heights, n, m);
        }
        for (int j = 0; j < m; j++) {
            dfs(n - 1, j, atlantic, heights, n, m);
        }

        vector<vector<int>> result;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    result.push_back({i, j});
                }
            }
        }
        return result;
    }
};