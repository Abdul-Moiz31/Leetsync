class Solution {
public:
    void dfs(int i, int j, vector<vector<int>>& visited,
             vector<vector<char>>& board, int n, int m) {
        visited[i][j] = 1;

        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, -1, 0, 1};
        for (int d = 0; d < 4; d++) {
            int nrow = i + dx[d];
            int ncol = j + dy[d];
            if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m &&
                visited[nrow][ncol] == 0 && board[nrow][ncol] == 'O') {
                dfs(nrow, ncol, visited, board, n, m);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<int>> visited(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            if (board[i][0] == 'O' && visited[i][0] == 0)
                dfs(i, 0, visited, board, n, m);
            if (board[i][m - 1] == 'O' && visited[i][m - 1] == 0)
                dfs(i, m - 1, visited, board, n, m);
        }
        for (int j = 0; j < m; j++) {
            if (board[0][j] == 'O' && visited[0][j] == 0)
                dfs(0, j, visited, board, n, m);
            if (board[n - 1][j] == 'O' && visited[n - 1][j] == 0)
                dfs(n - 1, j, visited, board, n, m);
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!visited[i][j] && board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
        // return board;
    }
};