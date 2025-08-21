class Solution {
public:
    vector<int> findOrder(int V, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(V);

        // Building a tree
        int n = prerequisites.size();
        for (int i = 0; i < n; i++) {
            int course = prerequisites[i][0];
            int prereq = prerequisites[i][1];
            adj[prereq].push_back(course);
        }

        // Check Indegree
        vector<int> indegree(V, 0);
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < adj[i].size(); j++) {
                int neighbor = adj[i][j];
                indegree[neighbor]++;
            }
        }

        // queue
        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> topo;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            topo.push_back(node);

            for (int i = 0; i <adj[node].size() ; i++) {
                int neighbor = adj[node][i];
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }
        if(topo.size() == V)     return topo;
        return {};
    }
};