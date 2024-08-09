class Solution {
public:
    bool check(vector<vector<int>>& grid, int x, int y) {
        vector<int> cnt(10, 0);

        // Check for valid numbers and uniqueness
        for (int i = x; i < x + 3; i++) {
            for (int j = y; j < y + 3; j++) {
                if (grid[i][j] < 1 || grid[i][j] > 9 || cnt[grid[i][j]] > 0)
                    return false;
                cnt[grid[i][j]]++;
            }
        }

        // Check rows
        for (int i = x; i < x + 3; i++) {
            int sum = 0;
            for (int j = y; j < y + 3; j++) {
                sum += grid[i][j];
            }
            if (sum != 15)
                return false;
        }

        // Check columns
        for (int j = y; j < y + 3; j++) {
            int sum = 0;
            for (int i = x; i < x + 3; i++) {
                sum += grid[i][j];
            }
            if (sum != 15)
                return false;
        }

        // Check main diagonal
        int sum = 0;
        for (int i = 0; i < 3; i++) {
            sum += grid[x + i][y + i];
        }
        if (sum != 15)
            return false;

        // Check anti-diagonal
        sum = 0;
        for (int i = 0; i < 3; i++) {
            sum += grid[x + i][y + 2 - i];
        }
        if (sum != 15)
            return false;

        return true;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int cnt = 0;
        for (int i = 0; i < m - 2; i++) {
            for (int j = 0; j < n - 2; j++) {
                if (check(grid, i, j))
                    cnt++;
            }
        }
        return cnt;
    }
};