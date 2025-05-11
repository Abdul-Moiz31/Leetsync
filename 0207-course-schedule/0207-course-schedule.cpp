class Solution {
public:
    bool canFinish(int V, vector<vector<int>>& prerequisites) {
        vector<int> adj[V]; // Adjacency list

        // Graph Building

        int n = prerequisites.size();
        for (int i = 0; i < n; i++) {
            int course = prerequisites[i][0];
            int prereq = prerequisites[i][1];
            adj[prereq].push_back(course); // prereq → course
        }

        // Step 2: Calculate in-degree of each node
        vector<int> indegree(V, 0);
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < adj[i].size(); j++) {
                int neighbors = adj[i][j];
                indegree[neighbors]++;
            }
        }
        // Step 3: Push all nodes with in-degree 0 into the queue
        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        // Step 4: Perform BFS (Kahn’s Algorithm)
        vector<int> topo;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            topo.push_back(node);

            for (int i = 0; i < adj[node].size(); i++) {
                int neighbor = adj[node][i];
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }
        return topo.size() == V;
    }
};