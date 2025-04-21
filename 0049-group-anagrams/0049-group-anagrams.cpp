class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
    int n = strs.size();
    vector<bool> visited(n, false);
    vector<vector<string>> result;

    for (int i = 0; i < n; i++) {
        if (visited[i]) continue;

        vector<string> group;
        group.push_back(strs[i]);
        visited[i] = true;
        string sorted_i = strs[i];
        sort(sorted_i.begin(), sorted_i.end());

        for (int j = i + 1; j < n; j++) {
            string sorted_j = strs[j];
            sort(sorted_j.begin(), sorted_j.end());

            if (sorted_i == sorted_j) {
                group.push_back(strs[j]);
                visited[j] = true;
            }
        }
        result.push_back(group);
    }

    return result;
    }
};
