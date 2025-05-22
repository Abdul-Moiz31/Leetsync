class Solution {
public:
    int helper(int i, int j, vector<vector<int>>& grid) {
        if (i == 0 && j == 0)
            return grid[0][0];
        if (i < 0 || j < 0)
            return INT_MAX;

        int left = helper(i - 1, j, grid);
        int up = helper(i, j - 1, grid);

        return grid[i][j] + min(left, up);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        return helper(n-1, m-1, grid);
    }
};