class Solution {
public:
    vector<vector<int>> result; // Stores all combinations

    void backtrack(int start, int n, int k, vector<int>& path) {
        if (path.size() == k) {
            result.push_back(path);
            return;
        }

        for (int i = start; i <= n; ++i) {
            path.push_back(i);           // Choose
            backtrack(i + 1, n, k, path); // Explore
            path.pop_back();             // Un-choose (backtrack)
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<int> path;
        backtrack(1, n, k, path);
        return result;
    }
};
