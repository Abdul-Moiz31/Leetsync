class Solution {
public:
    void dfs(int i, int j, vector<vector<int>>& vis,
             vector<vector<int>>& heights, int n, int m) {
        vis[i][j] = 1;
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};

        for (int d = 0; d < 4; d++) {
            int nrow = i + dx[d]; 
            int ncol = j + dy[d];
            if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m &&
                !vis[nrow][ncol] && heights[nrow][ncol] >= heights[i][j]) {
                dfs(nrow, ncol, vis, heights, n, m);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> pacific(n, vector(m, 0));
        vector<vector<int>> atlantic(n, vector(m, 0));

        // Start DFS from Pacific Ocean borders
        for (int i = 0; i < n; i++)
            dfs(i, 0, pacific, heights, n, m); // Left column
        for (int j = 0; j < m; j++)
            dfs(0, j, pacific, heights, n, m); // Top row

        // Start DFS from Atlantic Ocean borders
        for (int i = 0; i < n; i++)
            dfs(i, m - 1, atlantic, heights, n, m); // Right column
        for (int j = 0; j < m; j++)
            dfs(n - 1, j, atlantic, heights, n, m); // Bottom row

        // Collect results
        vector<vector<int>> res;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    res.push_back({i, j});
                }
            }
        }
        return res;
    }
};